#pragma once

#include <Windows.h>
#include "SingletonCls.h"

#define MaskColor RGB(0,255,0)

class Vector2;
class GameObject;
class TextureComponent;
class TextComponent;
class MemDc;
class Camera : public SingletonCls<Camera>
{
private:
	HBITMAP beforeBuffer;
	HBITMAP green;

public:
	Camera();
	virtual ~Camera();
public:
	void Render();

private:
	void beforeRender();
	void realRender();

	void TextureRender(MemDc&, const TextureComponent*);
	void TextRender(MemDc&, const TextComponent*);
	void UIRender(MemDc&, const TextureComponent*);
	void transparentBlt(const HDC& backdc, const int& xdest, const int& ydest, const int& wdest, const int& hdest, const HDC& ObjDC);
};

