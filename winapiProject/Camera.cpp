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


#pragma warning(disable: 4244)

Camera::Camera()
{
}
Camera::~Camera()
{
}

void Camera::Render()
{
	beforeRender();
	realRender();
}

void Camera::beforeRender()
{
	HBITMAP hOldBmp;
	HDC hdc, MemDC;
	WindowMsg* windowMsg = WindowMsg::getInstance();
	GameData* gameData = GameData::getInstance();
	AllObject* allObject = AllObject::getInstance();


	hdc = GetDC(WindowMsg::getInstance()->gethWnd());
	if (beforeBuffer) DeleteObject(beforeBuffer);
	beforeBuffer = CreateCompatibleBitmap(hdc, gameData->getwindowX(), gameData->getwindowY());
	MemDC = CreateCompatibleDC(hdc);
	hOldBmp = (HBITMAP)SelectObject(MemDC, beforeBuffer);
	PatBlt(MemDC, 0, 0, gameData->getwindowX(), gameData->getwindowY(), WHITENESS);

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
			HDC MemDC2 = CreateCompatibleDC(hdc);
			HDC MemDC3 = CreateCompatibleDC(hdc);
			HDC GreenDc = CreateCompatibleDC(hdc);
			HBITMAP tempBitmap1_1 = CreateCompatibleBitmap(hdc, xSize, ySize);
			HBITMAP greenBitmap = CreateCompatibleBitmap(hdc, rectWeight, rectHeight);
			//HBITMAP greenBitmap = (HBITMAP)LoadImage(NULL, "./Resource/Image/System/Green.bmp", IMAGE_BITMAP, rectWeight, rectHeight, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
			HBITMAP holdBmp2 = (HBITMAP)SelectObject(MemDC2, tempBitmap1_1);
			HBITMAP holdBmp3 = (HBITMAP)SelectObject(MemDC3, texture->getbitmap());
			HBITMAP holdBmp4 = (HBITMAP)SelectObject(GreenDc, greenBitmap);

			StretchBlt(MemDC2, 0, 0, xSize, ySize, GreenDc, 0, 0, rectWeight, rectHeight, SRCCOPY);
			StretchBlt(MemDC2, 0, 0, xSize, ySize, GreenDc, 0, 0, rectWeight, rectHeight, SRCCOPY);
			StretchBlt(GreenDc, 0, 0, rectWeight, rectHeight, MemDC3, 0, 0, texture->getxSize(), texture->getySize(), SRCCOPY);
			PlgBlt(MemDC2, pointarr, GreenDc, 0, 0, rectWeight, rectHeight, 0, 0, 0);
			transparentBlt(MemDC, min.x, min.y, xSize, ySize, MemDC2);
			//debugRender(MemDC, obj);

			SelectObject(MemDC2, holdBmp2);
			DeleteDC(MemDC2);
			SelectObject(MemDC3, holdBmp3);
			DeleteDC(MemDC3);
			SelectObject(GreenDc, holdBmp4);
			DeleteDC(GreenDc);
			DeleteObject(tempBitmap1_1);
			DeleteObject(greenBitmap);
		}
	}

	SelectObject(MemDC, hOldBmp);
	DeleteDC(MemDC);
	ReleaseDC(WindowMsg::getInstance()->gethWnd(), hdc);
}

void Camera::realRender()
{
	PAINTSTRUCT ps;
	HDC MemDC;
	HBITMAP OldBitmap;
	HWND hWnd = WindowMsg::getInstance()->gethWnd();
	GameData* gameData = GameData::getInstance();
	InvalidateRect(hWnd, NULL, FALSE);

	HDC hdc = BeginPaint(hWnd, &ps);

	MemDC = CreateCompatibleDC(hdc);
	OldBitmap = (HBITMAP)SelectObject(MemDC, beforeBuffer);

	BitBlt(hdc, 0, 0, gameData->getwindowX(), gameData->getwindowY(), MemDC, 0, 0, SRCCOPY);

	SelectObject(MemDC, OldBitmap);
	DeleteDC(MemDC);

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
	HDC maskDC;
	HBITMAP maskbimap, oldbitmap;
	maskDC = CreateCompatibleDC(backdc);
	maskbimap = CreateBitmap(wdest, hdest, 1, 1, NULL);
	oldbitmap = (HBITMAP)SelectObject(maskDC, maskbimap);

	COLORREF tempcol = SetBkColor(ObjDC, MaskColor);
	BitBlt(maskDC, 0, 0, wdest, hdest, ObjDC, 0, 0, SRCCOPY);
	SetBkColor(ObjDC, tempcol);

	BitBlt(backdc, xdest, ydest, wdest, hdest, ObjDC, 0, 0, SRCINVERT);
	BitBlt(backdc, xdest, ydest, wdest, hdest, maskDC, 0, 0, SRCAND);
	BitBlt(backdc, xdest, ydest, wdest, hdest, ObjDC, 0, 0, SRCINVERT);

	SelectObject(maskDC, oldbitmap);
	DeleteDC(maskDC);
	DeleteObject(maskbimap);
}