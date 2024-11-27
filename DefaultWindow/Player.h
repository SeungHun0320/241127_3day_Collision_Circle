#pragma once
#include "Object.h"
#include "Bullet.h"

class CPlayer : public CObject
{
public:
	CPlayer();
	virtual ~CPlayer();

public:
	virtual void Initialize()override;
	virtual int Update() override;
	void Late_Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

public:
	void Set_Bullet(list<CObject*>* pBullet) { m_pBullet = pBullet; }

private:
	void Key_Input();
	CObject* Create_Bullet(DIRECTION eDirect);

private:
	list<CObject*>* m_pBullet;

	ULONG64 m_ullLast_Bullet;

};

