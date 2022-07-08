#pragma once
#include <Windows.h>
#include <string>
#include "Component.h"

class Vector2;
class Rect;
class TextureComponent : public Component
{
private:
	//∫Ò∆Æ∏ 
	HBITMAP bitmap;
	int xSize;
	int ySize;
	//∑∫≈ ±€
	Rect* rect;
public:
	TextureComponent();
	TextureComponent(const string&, const Rect&, int, int);
	virtual ~TextureComponent();

public:
	virtual void Start();


	HBITMAP	getbitmap();
	Rect getrect();
	const Rect& getrectptr();
	int getxSize();
	int getySize();

	void setbitmap	(string, int, int);
	void setrect	(const Rect&);
private:
	void DeleteBitmap();
};

