#pragma once
#include "define.h"
#include "Object.h"

enum OBJ_ID {OBJ_PLAYER, OBJ_MONSTER, OBJ_BULLET, OBJ_END};

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void Initialize();
	void Update();
	void Late_Update();
	void Render();
	void Release();

private:
	HDC m_hDC;

	list<CObject*> m_ObjList[OBJ_END];

	ULONG64 m_dwTime;
	int   m_iFPS;
	TCHAR m_szFPS[16];

	RECT m_trc;
};

