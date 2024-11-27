#pragma once
#include "Object.h"
class CMonster : public CObject
{
public:
	CMonster();
	~CMonster();

public:
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;

public:
	int Get_Hp();
	void Set_Hp(int iHp);

private:
	int m_iHp;
};

