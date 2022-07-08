#pragma once

#include <Windows.h>
#include "SingletonCls.h"

class WindowMsg : public SingletonCls<WindowMsg>
{
private:
	//윈도우 메세지 종류입니다
	HWND		hWnd;
	UINT		iMessage;
	WPARAM		wParam;
	LPARAM		lParam;
	HINSTANCE	hinstance;

public:
	WindowMsg();
	virtual ~WindowMsg();

public:
	HWND		gethWnd();
	UINT		getiMessage();
	WPARAM		getwParam();
	LPARAM		getlParam();
	HINSTANCE	gethinstance();

	//발생한 윈도우메세지를 갱신해줍니다
	void settingMsg(HWND, UINT, WPARAM, LPARAM);
	WindowMsg* sethinstance(HINSTANCE);

};

