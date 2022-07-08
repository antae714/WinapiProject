#pragma once

#include <Windows.h>
#include "SingletonCls.h"

#define MaskColor RGB(0,255,0)

class Vector2;
class GameObject;
class Camera : public SingletonCls<Camera>
{
private:
	HBITMAP beforeBuffer;

public:
	Camera();
	virtual ~Camera();
public:
	void Render();

private:

	void beforeRender();
	void realRender();


	void transparentBlt(const HDC& backdc, const int& xdest, const int& ydest, const int& wdest, const int& hdest, const HDC& ObjDC);
	void debugRender(const HDC MemDC, const GameObject* obj);
};

