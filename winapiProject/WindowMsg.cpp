#include "WindowMsg.h"

WindowMsg::WindowMsg()
{

}

WindowMsg::~WindowMsg()
{
}

HWND WindowMsg::gethWnd()
{
	return hWnd;
}

UINT WindowMsg::getiMessage()
{
	return iMessage;
}

WPARAM WindowMsg::getwParam()
{
	return wParam;
}

LPARAM WindowMsg::getlParam()
{
	return lParam;
}

HINSTANCE WindowMsg::gethinstance()
{
	return hinstance;
}

void WindowMsg::settingMsg(HWND p_hwnd, UINT p_msg, WPARAM p_wparam, LPARAM p_lparam)
{
	hWnd = p_hwnd;
	iMessage = p_msg;
	wParam = p_wparam;
	lParam = p_lparam;
}

WindowMsg* WindowMsg::sethinstance(HINSTANCE p_in)
{
	hinstance = p_in;
	return this;
}
