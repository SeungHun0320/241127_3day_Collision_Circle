#pragma once
#include "define.h"

enum DIRECTION { ZERO, UP, DOWN, LEFT, RIGHT, LEFTUP, RIGHTUP, LEFTDOWN, RIGHTDOWN };


class CObject
{
public:
	CObject();
	virtual ~CObject();

public:
	INFO Get_Info() { return m_tInfo; }
	RECT* Get_Rect() { return &m_tRect; }

	void Set_Pos(float _fX, float _fY)
	{
		m_tInfo.fX = _fX;
		m_tInfo.fY = _fY;
	}

public:
	virtual void Initialize()PURE;
	virtual int Update()PURE;
	virtual void Late_Update()PURE;
	virtual void Render(HDC hDC)PURE;
	virtual void Release()PURE;

public:
	void Update_Rect();

public:
	DIRECTION Get_Direct();
	void Set_Direct(DIRECTION eDirect);
	bool Get_Dead();
	void Set_Dead();
	
protected:
	INFO m_tInfo;   // 위치 정보를 저장할 구조체?
	RECT m_tRect;   // 그리기용 렉트

	bool m_bDead;
	float m_fXSpeed; // 속도
	float m_fYSpeed;
	DIRECTION m_eDirect; // 방향 설정
};

