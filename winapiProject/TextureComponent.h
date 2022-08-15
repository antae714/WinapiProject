#pragma once
#include <Windows.h>
#include <string>
#include "Component.h"
#include "UpdateFunction.h"

class AnimationStruct;
class Vector2;
class Rect;
class TextureComponent : public Component , public UpdateFunction
{
private:
	//∫Ò∆Æ∏ 
	HBITMAP bitmap;
	int xSize;
	int ySize;
	//∑∫≈ ±€
	Rect* rect;
	AnimationStruct* animation;
	bool direction;
public:
	TextureComponent();
	TextureComponent(const string&, const Rect&);
	TextureComponent(const string&, const Rect&, int, int);
	TextureComponent(const AnimationStruct&, const Rect&, int, int);
	TextureComponent(const AnimationStruct&, const Rect&);
	virtual ~TextureComponent();

public:
	virtual void Start();
	virtual void Update();

	HBITMAP	getbitmap() const;
	Rect getrect() const;
	const Rect& getrectptr() const;
	int getxSize() const;
	int getySize() const;
	AnimationStruct* getanimationptr() const;
	const AnimationStruct* getanimationconst() const;
	bool getdirection() const;


	void setdirection(bool);
	void setbitmap	(string, int, int);
	HBITMAP setbitmap(void*);
	void setrect	(const Rect&);
private:
	//void DeleteBitmap();

	void transformset();
};

