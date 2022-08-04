#include "Camera.h"
#include "WindowMsg.h"
#include "GameData.h"
#include "Vector2.h"
#include "ScreenPoint.h"
#include "AllObject.h"
#include "GameObject.h"
#include "E_Component.h"
#include "TextureComponent.h"
#include "TextComponent.h"
#include "Rect.h"
#include "Math.h"
#include "MemDc.h"
#include "MyBitmap.h"
#include "Macro.h"


#pragma warning(disable: 4244)

Camera::Camera()
{
	green = (HBITMAP)LoadImage(NULL, "./Resource/Image/System/Green.bmp", IMAGE_BITMAP, 1, 1, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
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

	PatBlt(MemDC(), 0, 0, gameData->getwindowX(), gameData->getwindowY(), BLACKNESS);

	for (ObjIter iter = allObject->allObjbegin(); iter != allObject->allObjend(); ++iter) {
		const GameObject* obj = iter.operator*().second;
		if (!obj->getisActive()) continue;
		
		Component* transform = obj->getcomponent(E_Component::TransformComponent);
		Component* ui = obj->getcomponent(E_Component::UITransformComponent);
		TextureComponent* texture = GETCOMPONENT(obj, TextureComponent);
		if (transform && texture && texture->getbitmap()) {
			TextureRender(MemDC, texture);
		}
		else if (ui && texture) {
			UIRender(MemDC, texture);
		}

		TextComponent* text = GETCOMPONENT(obj, TextComponent);
		if (text) {
			TextRender(MemDC, text);
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

void Camera::TextureRender(MemDc& p_memdc, const TextureComponent* p_texture)
{
	const Rect& temprect = p_texture->getrectptr();
	vector<Vector2> vec2vec = temprect.getVertexes();
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
		pointarr[i].y -= min.y;
	}
	int rectWeight = (int)temprect.getweight();
	int rectHeight = (int)temprect.getheight();

	MyBitmap tempBitmap(p_memdc(), xSize, ySize);
	MyBitmap BackBitmap(p_memdc(), rectWeight, rectHeight);

	MemDc BackDc(p_memdc(), tempBitmap());
	MemDc ObjDc(p_memdc(), p_texture->getbitmap());
	MemDc tempObjDc(p_memdc(), BackBitmap());
	MemDc greenDc(p_memdc(), green);

	StretchBlt(BackDc(), 0, 0, xSize, ySize, greenDc(), 0, 0, 1, 1, SRCCOPY);
	StretchBlt(tempObjDc(), 0, 0, rectWeight, rectHeight, ObjDc(), 0, 0, p_texture->getxSize(), p_texture->getySize(), SRCCOPY);
	PlgBlt(BackDc(), pointarr, tempObjDc(), 0, 0, rectWeight, rectHeight, 0, 0, 0);
	transparentBlt(p_memdc(), min.x, min.y, xSize, ySize, BackDc());
}

void Camera::TextRender(MemDc& p_memdc, const TextComponent* p_text)
{
	Vector2 point = p_text->getpoint();
	string text = p_text->getText();
	int strlength = p_text->getnownum()+1;
	MyBitmap tempBitmap(p_memdc(), strlength * 11, 30);
	MemDc greenDc(p_memdc(), green);
	MemDc tempdc(p_memdc(), tempBitmap());

	HFONT font = CreateFont(30, 10, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, NONANTIALIASED_QUALITY, 0, TEXT("±¼¸²"));

	SetBkColor(tempdc(), MaskColor);
	StretchBlt(tempdc(), 0, 0, strlength * 11, 30, greenDc(), 0, 0, 1, 1, SRCCOPY);
	DeleteObject((HFONT)SelectObject(tempdc(), font));
	TextOut(tempdc(), 0, 0, text.c_str(), strlength);
	transparentBlt(p_memdc(), point.getx(), point.gety(), strlength * 11, 30, tempdc());
}

void Camera::UIRender(MemDc& p_memdc, const TextureComponent* p_texture)
{
	const Rect& temprect = p_texture->getrectptr();
	Vector2 pivot = temprect.getpivot();

	int Weight = (int)temprect.getweight();
	int halfWeight = (int)temprect.gethalfweight();
	int Height = (int)temprect.getheight();
	int halfHeight = (int)temprect.gethalfheight();
	int xSize = (int)p_texture->getxSize();
	int ySize = (int)p_texture->getySize();

	MyBitmap tempBitmap(p_memdc(), Weight, Height);
	MyBitmap BackBitmap(p_memdc(), xSize, ySize);

	MemDc BackDc(p_memdc(), tempBitmap());
	MemDc ObjDc(p_memdc(), p_texture->getbitmap());
	MemDc tempObjDc(p_memdc(), BackBitmap());
	MemDc greenDc(p_memdc(), green);

	StretchBlt(BackDc(), 0, 0, Weight, Height, greenDc(), 0, 0, 1, 1, SRCCOPY);
	StretchBlt(tempObjDc(), 0, 0, xSize, ySize, ObjDc(), 0, 0, xSize, ySize, SRCCOPY);

	StretchBlt(BackDc(), 0, 0, Weight, Height, tempObjDc(), 0, 0, xSize, ySize, SRCCOPY);
	transparentBlt(p_memdc(), pivot.getx() - halfWeight, pivot.gety() - halfHeight, Weight, Height, BackDc());
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