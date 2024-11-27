#pragma once
#include "Object.h"

template<typename T>
class CAbstractFactory
{
public:
	CAbstractFactory() {}
	~CAbstractFactory() {}

public:
	static CObject* Create()
	{
		CObject* pObj = new T;
		pObj->Initialize();
		return pObj;
	}

	static CObject* Create(float _iX, float _iY, DIRECTION eDirect)
	{
		CObject* pObj = new T;
		pObj->Initialize();
		pObj->Set_Pos(_iX, _iY);
		pObj->Set_Direct(eDirect);

		return pObj;
	}
};

