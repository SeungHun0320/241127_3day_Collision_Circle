#pragma once
#include "Object.h"



class CBullet : public CObject
{
public:
	CBullet();
	~CBullet();

public:
	void Initialize() override;
	int Update() override;
	void Late_Update() override;
	void Render(HDC hDC) override;
	void Release() override;
	
};

