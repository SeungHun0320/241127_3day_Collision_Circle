#include "pch.h"
#include "Bullet.h"

CBullet::CBullet() 
{
}

CBullet::~CBullet()
{
	Release();
}

void CBullet::Initialize()
{
	m_tInfo.fCX = 30.f;
	m_tInfo.fCY = 30.f;

	m_fSpeed = 7.f;
}

int CBullet::Update()
{
	if (m_bDead == true)
		return OBJ_DEAD;

	if(m_eDirect == UP)
		m_tInfo.fY -= m_fSpeed;
	if (m_eDirect == DOWN)
		m_tInfo.fY += m_fSpeed;
	if (m_eDirect == LEFT)
		m_tInfo.fX -= m_fSpeed;
	if (m_eDirect == RIGHT)
		m_tInfo.fX += m_fSpeed;

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CBullet::Late_Update()
{
	if (750 < m_tRect.right || 50 > m_tRect.left ||
		50 > m_tRect.top || 550 < m_tRect.bottom)
	{
		m_bDead = true;
	}
}

void CBullet::Render(HDC hDC)
{
	Ellipse(hDC,
		m_tRect.left,
		m_tRect.top,
		m_tRect.right,
		m_tRect.bottom);
}

void CBullet::Release()
{
}



