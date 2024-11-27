#include "pch.h"
#include "Monster.h"

CMonster::CMonster() : m_iHp(0)
{
}

CMonster::~CMonster()
{
}

void CMonster::Initialize()
{
	m_tInfo = { 100.f, 150.f, 80.f, 80.f };
	m_fXSpeed = 3.f;
	m_fYSpeed = 3.f;
	m_iHp = 15;
}

int CMonster::Update()
{
	if (m_bDead == true)
		return OBJ_DEAD;

	
	switch (m_eDirect)
	{
	case UP:
		m_tInfo.fY -= m_fYSpeed;
		break;

	case DOWN:
		m_tInfo.fY += m_fYSpeed;
		break;

	case LEFT:
		m_tInfo.fX -= m_fXSpeed;
		break;

	case RIGHT:
		m_tInfo.fX += m_fXSpeed;
		break;

	case LEFTUP:
		m_tInfo.fX -= m_fXSpeed;
		m_tInfo.fY -= m_fYSpeed;
		break;

	case LEFTDOWN:
		m_tInfo.fX -= m_fXSpeed;
		m_tInfo.fY += m_fYSpeed;
		break;

	case RIGHTUP:
		m_tInfo.fX += m_fXSpeed;
		m_tInfo.fY -= m_fYSpeed;
		break;

	case RIGHTDOWN:
		m_tInfo.fX += m_fXSpeed;
		m_tInfo.fY += m_fYSpeed;
		break;
	}

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CMonster::Late_Update()
{
	if (WINCX - 50 < m_tRect.right || 50 > m_tRect.left)
	{
		m_fXSpeed *= -1.f;
	}
	if (WINCY - 50 < m_tRect.bottom || 50 > m_tRect.top)
		m_fYSpeed *= -1.f;

}

void CMonster::Render(HDC hDC)
{
	Ellipse(hDC,
		m_tRect.left,
		m_tRect.top,
		m_tRect.right,
		m_tRect.bottom);

	//TCHAR szBuf[32] = L"";
	//wsprintf(szBuf, L"HP : %d", m_iHp);
	//TextOut(hDC, m_tInfo.fX - 20.f, m_tInfo.fY - 10.f, szBuf, lstrlen(szBuf));
}

void CMonster::Release()
{
}

int CMonster::Get_Hp()
{
	return m_iHp;
}

void CMonster::Set_Hp(int iHp)
{
	m_iHp = iHp;
}

