#include "Camera.h"
#include "WindowMsg.h"
#include "GameData.h"
#include "Vector2.h"
#include "ScreenPoint.h"
#include "AllObject.h"
#include "GameObject.h"
#include "E_Component.h"
#include "TextureComponent.h"
#include "Rect.h"
#include "Math.h"
#include "MemDc.h"
#include "MyBitmap.h"


#pragma warning(disable: 4244)

Camera::Camera()
{
	green = (HBITMAP)LoadImage(NULL, "./Resource/Image/System/Green.bmp", IMAGE_BITMAP, 256, 256, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
}
Camera::~Camera()
{
	DeleteObject(green);
}

void Camera::Render()
{
	beforeRender();
	realRender();
}

void Camera::beforeRender()
{
	HDC hdc;
	WindowMsg* windowMsg = WindowMsg::getInstance();
	GameData* gameData = GameData::getInstance();
	AllObject* allObject = AllObject::getInstance();

	hdc = GetDC(WindowMsg::getInstance()->gethWnd());
	if (beforeBuffer) DeleteObject(beforeBuffer);
	beforeBuffer = CreateCompatibleBitmap(hdc, gameData->getwindowX(), gameData->getwindowY());
	MemDc MemDC(hdc, beforeBuffer);

	PatBlt(MemDC(), 0, 0, gameData->getwindowX(), gameData->getwindowY(), WHITENESS);

	for (ObjIter iter = allObject->allObjbegin(); iter != allObject->allObjend(); ++iter) {
		const GameObject* obj = iter.operator*().second;
		Component* temp = obj->getcomponent(E_Component::TextureComponent);
		if (temp) {
			TextureComponent* texture = dynamic_cast<TextureComponent*>(temp);
			const Rect& temprect = dynamic_cast<TextureComponent*>(texture)->getrectptr();
			vector<Vector2> vec2vec = temprect.getVectors();
			POINT pointarr[4];

			POINT min, max;
			min.x = LONG_MAX;
			min.y = LONG_MAX;
			max.x = LONG_MIN;
			max.y = LONG_MIN;
			for (int i = 0; i < 4; i++)
			{
				pointarr[i] = Math::CarttoScreen(vec2vec.at(i)).toPOINT();
				if (min.x > pointarr[i].x) {
					min.x = pointarr[i].x;
				}
				if (max.x < pointarr[i].x) {
					max.x = pointarr[i].x;
				}
				if (min.y > pointarr[i].y) {
					min.y = pointarr[i].y;
				}
				if (max.y < pointarr[i].y) {
					max.y = pointarr[i].y;
				}
			}
			int xSize = max.x - min.x, ySize = max.y - min.y;
			for (int i = 0; i < 4; i++) {
				pointarr[i].x -= min.x;
				pointarr[i].y = abs(pointarr[i].y - min.y - ySize);
			}
			int rectWeight = (int)temprect.getweight();
			int rectHeight = (int)temprect.getweight();

			MyBitmap tempBitmap(hdc, xSize, ySize);
			MyBitmap BackBitmap(hdc, rectWeight, rectHeight);

			MemDc BackDc(hdc, tempBitmap());
			MemDc ObjDc(hdc, texture->getbitmap());
			MemDc tempObjDc(hdc, BackBitmap());
			MemDc greenDc(hdc, green);

			StretchBlt(BackDc(), 0, 0, xSize, ySize, greenDc(), 0, 0, 256, 256, SRCCOPY);
			StretchBlt(tempObjDc(), 0, 0, rectWeight, rectHeight, ObjDc(), 0, 0, texture->getxSize(), texture->getySize(), SRCCOPY);
			PlgBlt(BackDc(), pointarr, tempObjDc(), 0, 0, rectWeight, rectHeight, 0, 0, 0);
			transparentBlt(MemDC(), min.x, min.y, xSize, ySize, BackDc());
			//debugRender(MemDC, obj);
		}
	}

	ReleaseDC(WindowMsg::getInstance()->gethWnd(), hdc);
}

void Camera::realRender()
{
	PAINTSTRUCT ps;
	HWND hWnd = WindowMsg::getInstance()->gethWnd();
	GameData* gameData = GameData::getInstance();
	InvalidateRect(hWnd, NULL, FALSE);

	HDC hdc = BeginPaint(hWnd, &ps);

	MemDc MemDC(hdc, beforeBuffer);

	BitBlt(hdc, 0, 0, gameData->getwindowX(), gameData->getwindowY(), MemDC(), 0, 0, SRCCOPY);

	EndPaint(hWnd, &ps);
}

void Camera::debugRender(const HDC MemDC, const GameObject* obj)
{
	Component* temp = obj->getcomponent(E_Component::TextureComponent);
	if (temp) {
		TextureComponent* texture = dynamic_cast<TextureComponent*>(temp);
		const Rect& temprect = dynamic_cast<TextureComponent*>(texture)->getrectptr();
		POINT rectp = Math::CarttoScreen(temprect.getpivot()).toPOINT();
		string tempstr1 = string("x : ") + to_string((int)temprect.getpivot().getx()) + ", y :" + to_string((int)temprect.getpivot().gety());
		HDC Memdc2 = CreateCompatibleDC(MemDC);
		HBITMAP tempbitmap = CreateCompatibleBitmap(MemDC, tempstr1.size() * 6, 16);
		HBITMAP OldBitmap = (HBITMAP)SelectObject(Memdc2, tempbitmap);

		COLORREF oldcolor = SetBkColor(Memdc2, MaskColor);
		TextOut(Memdc2, 0, 0, (LPCSTR)tempstr1.c_str(), tempstr1.size());
		SetBkColor(Memdc2, oldcolor);

		transparentBlt(MemDC, rectp.x - temprect.gethalfweight(), rectp.y + temprect.gethalfheight(),
			tempstr1.size() * 6, 16, Memdc2);

		SelectObject(Memdc2, OldBitmap);
		DeleteDC(Memdc2);

		DeleteObject(tempbitmap);
	}
}

void Camera::transparentBlt(const HDC& backdc, const int& xdest, const int& ydest,
	const int& wdest, const int& hdest, const HDC& ObjDC)
{
	HBITMAP maskbimap = CreateBitmap(wdest, hdest, 1, 1, NULL);

	MemDc maskDC(backdc, maskbimap);
	COLORREF tempcol = SetBkColor(ObjDC, MaskColor);
	BitBlt(maskDC(), 0, 0, wdest, hdest, ObjDC, 0, 0, SRCCOPY);
	SetBkColor(ObjDC, tempcol);

	BitBlt(backdc, xdest, ydest, wdest, hdest, ObjDC, 0, 0, SRCINVERT);
	BitBlt(backdc, xdest, ydest, wdest, hdest, maskDC(), 0, 0, SRCAND);
	BitBlt(backdc, xdest, ydest, wdest, hdest, ObjDC, 0, 0, SRCINVERT);

	DeleteObject(maskbimap);
}