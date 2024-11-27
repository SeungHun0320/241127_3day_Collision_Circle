#include "pch.h"
#include "Player.h"


CPlayer::CPlayer() : m_pBullet(nullptr), m_ullLast_Bullet(0)
{
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Initialize()
{
	m_tInfo = { WINCX * 0.5f, WINCY * 0.5f, 40.f, 80.f };
	m_fXSpeed = 10.f;
	m_fYSpeed = 10.f;
}

int CPlayer::Update()
{
	if (m_bDead == true)
		return OBJ_DEAD;

	Key_Input();
	CObject::Update_Rect();

	return OBJ_NOEVENT;
}

void CPlayer::Late_Update()
{
}

void CPlayer::Render(HDC hDC)
{
	Rectangle(hDC,
		m_tRect.left,
		m_tRect.top,
		m_tRect.right,
		m_tRect.bottom);

}

void CPlayer::Release()
{
}

void CPlayer::Key_Input()
{

	if (GetAsyncKeyState(VK_RIGHT))
	{
		if(750 > m_tRect.right)
			m_tInfo.fX += m_fXSpeed;
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		if (50 < m_tRect.left)
			m_tInfo.fX -= m_fXSpeed;
	}

	if (GetAsyncKeyState(VK_UP))
	{
		if (50 < m_tRect.top)
			m_tInfo.fY -= m_fYSpeed;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		if (550 > m_tRect.bottom)
			m_tInfo.fY += m_fYSpeed;
	}



	if (m_ullLast_Bullet + 150 < GetTickCount64())
	{
		if (GetAsyncKeyState(VK_W))
		{
			m_ullLast_Bullet = GetTickCount64();
			m_pBullet->push_back(Create_Bullet(UP));
		}

		if (GetAsyncKeyState(VK_A))
		{
			m_ullLast_Bullet = GetTickCount64();
			m_pBullet->push_back(Create_Bullet(LEFT));
		}

		if (GetAsyncKeyState(VK_S))
		{
			m_ullLast_Bullet = GetTickCount64();
			m_pBullet->push_back(Create_Bullet(DOWN));
		}

		if (GetAsyncKeyState(VK_D))
		{
			m_ullLast_Bullet = GetTickCount64();
			m_pBullet->push_back(Create_Bullet(RIGHT));
		}
	}
}

CObject* CPlayer::Create_Bullet(DIRECTION eDirect)
{
	CObject* pBullet = new CBullet;

	if (CBullet* Temp = dynamic_cast<CBullet*>(pBullet))
	{
		Temp->Set_Direct(eDirect);
	}
	
	pBullet->Initialize();
	pBullet->Set_Pos(m_tInfo.fX, m_tInfo.fY);

	return pBullet;
}


