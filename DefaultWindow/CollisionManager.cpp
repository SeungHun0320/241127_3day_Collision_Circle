#include "pch.h"
#include "CollisionManager.h"

CCollisionManager::CCollisionManager()
{
}

CCollisionManager::~CCollisionManager()
{
}

void CCollisionManager::Collision_Rect(list<CObject*> pDst, list<CObject*> pSrc)
{
	RECT rc;

	for (auto& Dst : pDst)
	{
		for (auto& Src : pSrc)
		{
			if (IntersectRect(&rc, Dst->Get_Rect(), Src->Get_Rect()))
			{
				Dst->Set_Dead();
				Src->Set_Dead();
			}
		}
	}
}

void CCollisionManager::Collision_Circle(list<CObject*> _Dst, list<CObject*> _Src)
{
	for (auto& Dst : _Dst)
	{
		for (auto& Src : _Src)
		{
			int iX = ((Dst->Get_Info().fX - Src->Get_Info().fX));
			iX *= iX;
			int iY = (Dst->Get_Info().fY - Src->Get_Info().fY);
			iY *= iY;

			int iLove = (Dst->Get_Info().fCX * 0.5f) + (Src->Get_Info().fCY * 0.5f);
			iLove *= iLove;
			// ³­´Â ¶Ë¸ÛÃ»ÀÌ´Ù
			if ((iX + iY) <= iLove)
			{
				Dst->Set_Dead();
				Src->Set_Dead();
			}
		}
	}
}
