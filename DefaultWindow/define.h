#pragma once

#define WINCX 800
#define WINCY 600

#define PURE = 0
#define PI   3.141592f

#define OBJ_NOEVENT 0
#define OBJ_DEAD 1

#define VK_W 0x57
#define VK_A 0x41
#define VK_S 0x53
#define VK_D 0x44

extern HWND g_hWnd;

typedef struct tagInfo
{
	float fX, fY;    // 중심점을 계산하기 위한 좌표
	float fCX, fCY;  // 가로, 세로 길이

}INFO;

template<typename T>
void Safe_Delete(T& p)
{
	if (p != nullptr)
	{
		delete p;
		p = nullptr;
	}
}