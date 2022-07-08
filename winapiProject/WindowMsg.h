#pragma once

#include <Windows.h>
#include "SingletonCls.h"

class WindowMsg : public SingletonCls<WindowMsg>
{
private:
	//������ �޼��� �����Դϴ�
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

	//�߻��� ������޼����� �������ݴϴ�
	void settingMsg(HWND, UINT, WPARAM, LPARAM);
	WindowMsg* sethinstance(HINSTANCE);

};

