#pragma once
#include "Object.h"

class CCollisionManager
{
public:
	CCollisionManager();
	~CCollisionManager();

public:
	static void Collision_Rect(list<CObject*> pDst, list<CObject*> pSrc);
	static void Collision_Circle(list<CObject*> _Dst, list<CObject*> _Src);
};

