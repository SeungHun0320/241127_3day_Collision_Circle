#include "pch.h"
#include "Object.h"

CObject::CObject() : m_fSpeed(0.f), m_eDirect(ZERO), m_bDead(false)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
	ZeroMemory(&m_tRect, sizeof(RECT));
}

CObject::~CObject()
{
}

void CObject::Update_Rect()
{
	m_tRect.left   = LONG(m_tInfo.fX - (m_tInfo.fCX * 0.5f));
	m_tRect.top    = LONG(m_tInfo.fY - (m_tInfo.fCY * 0.5f));
	m_tRect.right  = LONG(m_tInfo.fX + (m_tInfo.fCX * 0.5f));
	m_tRect.bottom = LONG(m_tInfo.fY + (m_tInfo.fCY * 0.5f));
}

DIRECTION CObject::Get_Direct()
{
	return m_eDirect;
}

void CObject::Set_Direct(DIRECTION eDirect)
{
	m_eDirect = eDirect;
}

bool CObject::Get_Dead()
{
	return m_bDead;
}

void CObject::Set_Dead()
{
	m_bDead = true;
}
