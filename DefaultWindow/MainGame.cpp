#include "pch.h"
#include "MainGame.h"
#include "Player.h"
#include "Monster.h"
#include "AbstractFactory.h"
#include "CollisionManager.h"

CMainGame::CMainGame()
	: m_hDC(nullptr), m_trc(),
	m_dwTime(0), m_iFPS(0)
{
	ZeroMemory(&m_szFPS, sizeof(m_szFPS));
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_hDC = GetDC(g_hWnd);
	m_ObjList[OBJ_PLAYER].push_back(CAbstractFactory<CPlayer>::Create());
	if (CPlayer* Temp = dynamic_cast<CPlayer*>(m_ObjList[OBJ_PLAYER].front()))
	{
		Temp->Set_Bullet(&m_ObjList[OBJ_BULLET]);
	}

	for (int i = 0; i < 4; i++)
	{
		m_ObjList[OBJ_MONSTER].push_back(CAbstractFactory<CMonster>::Create(100.f, ((i + 1) * 120.f), ZERO));
	}
}

void CMainGame::Update()
{
	for (int i = 0; i < OBJ_END; i++)
	{
		for (auto iter = m_ObjList[i].begin();
			iter != m_ObjList[i].end();)
		{
			int iResult = (*iter)->Update();

			if (OBJ_DEAD == iResult)
			{
				if (OBJ_DEAD == m_ObjList[OBJ_PLAYER].front()->Update())
				{
					PostQuitMessage(0);
					break;
				}
					
				Safe_Delete<CObject*>(*iter);
				iter = m_ObjList[i].erase(iter);
			}
			else
				iter++;
		}
	}
}

void CMainGame::Late_Update()
{
	for (int i = 0; i < OBJ_END; i++)
	{
		for (auto iter = m_ObjList[i].begin();
			iter != m_ObjList[i].end(); iter++)
		{
			(*iter)->Late_Update();
		}
	}

	CCollisionManager::Collision_Circle(m_ObjList[OBJ_MONSTER], m_ObjList[OBJ_BULLET]);
	CCollisionManager::Collision_Rect(m_ObjList[OBJ_MONSTER], m_ObjList[OBJ_PLAYER]);
}

void CMainGame::Render()
{
	++m_iFPS;

	Rectangle(m_hDC, 0, 0, WINCX, WINCY);
	Rectangle(m_hDC, 50, 50, WINCX - 50, WINCY - 50);

	if (m_dwTime + 1000 < GetTickCount64())
	{
		swprintf_s(m_szFPS, L"FPS : %d", m_iFPS);
		
		m_iFPS = 0;
		m_dwTime = GetTickCount64();
	}
	TextOut(m_hDC, 0, 0, m_szFPS, lstrlen(m_szFPS));

	TCHAR szBuf[32] = L"";
	wsprintf(szBuf, L"Bullet : %d", static_cast<int>(m_ObjList[OBJ_BULLET].size()));
	TextOut(m_hDC, 0, 20, szBuf, lstrlen(szBuf));

	for (int i = 0; i < OBJ_END; i++)
	{
		for (auto iter = m_ObjList[i].begin();
			iter != m_ObjList[i].end(); iter++)
		{
			(*iter)->Render(m_hDC);
		}
	}
}

void CMainGame::Release()
{
	for (int i = 0; i < OBJ_END; i++)
	{
		for_each(m_ObjList[i].begin(), m_ObjList[i].end(), Safe_Delete<CObject*>);
		m_ObjList[i].clear();
	}

	ReleaseDC(g_hWnd, m_hDC);
}

