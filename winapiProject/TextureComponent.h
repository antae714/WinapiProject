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

	HBITMAP	getbitmap() const;
	Rect getrect() const;
	const Rect& getrectptr() const;
	int getxSize() const;
	int getySize() const;

	void setbitmap	(string, int, int);
	void setrect	(const Rect&);
private:
	//void DeleteBitmap();
};

