#include "pch.h"
#include "Monster.h"

CMonster::CMonster() : m_bRight(true), m_iHp(0)
{
}

CMonster::~CMonster()
{
}

void CMonster::Initialize()
{
	m_tInfo = { 100.f, 150.f, 80.f, 80.f };
	m_fSpeed = 3;
	m_iHp = 15;
}

int CMonster::Update()
{
	if (m_bDead == true)
		return OBJ_DEAD;

	if (m_bRight == true)
	{
		m_tInfo.fX += m_fSpeed;
	}
	if (m_bRight == false)
	{
		m_tInfo.fX -= m_fSpeed;
	}
	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CMonster::Late_Update()
{
	if (750 < m_tRect.right)
		m_bRight = false;

	if (50 > m_tRect.left)
		m_bRight = true;
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

