#include "TextureComponent.h"
#include "Vector2.h"
#include "Rect.h"
#include "GameObject.h"
#include "E_Component.h"
#include "TransformComponent.h"
#include "UITransformComponent.h"
#include "WindowMsg.h"
#include "BitmapManager.h"
#include "AnimationStruct.h"
#include "Macro.h"

TextureComponent::TextureComponent()
{
	bitmap = nullptr;
	animation = nullptr;
	rect = new Rect();
}

TextureComponent::TextureComponent(const string& p_str, const Rect& p_rect)
{
	rect = new Rect();
	*rect = p_rect;
	animation = nullptr;
	setbitmap(p_str, p_rect.getweight(), p_rect.getheight());
}

TextureComponent::TextureComponent(const string& p_str, const Rect& p_rect, int p_x, int p_y)
{
	rect = new Rect();
	*rect = p_rect;
	animation = nullptr;
	setbitmap(p_str, p_x, p_y);
}


TextureComponent::TextureComponent(const AnimationStruct& p_animation, const Rect& p_rect , int p_x, int p_y)
{
	rect = new Rect();
	*rect = p_rect;
	animation = new AnimationStruct(p_animation);
	bitmap = nullptr;

	setbitmap(animation->getbitmapname(), p_x, p_y);
}

TextureComponent::TextureComponent(const AnimationStruct& p_animation, const Rect& p_rect)
{
	rect = new Rect();
	*rect = p_rect;
	animation = new AnimationStruct(p_animation);
	bitmap = nullptr;

	setbitmap(animation->getbitmapname(), p_rect.getweight(), p_rect.getheight());
}

TextureComponent::~TextureComponent()
{
	delete rect;
} 

void TextureComponent::Start()
{
	transformset();
}

void TextureComponent::Update()
{
	if (animation) {
		animation->Update();
		setbitmap(animation->getbitmapname(), xSize, ySize);
	}
}

HBITMAP TextureComponent::getbitmap() const
{
	return bitmap;
}

Rect TextureComponent::getrect() const
{
	return *rect;
}

const Rect& TextureComponent::getrectptr() const
{
	return *rect;
}

int TextureComponent::getxSize() const
{
	return xSize;
}

int TextureComponent::getySize() const
{
	return ySize;
}

AnimationStruct* TextureComponent::getanimationptr() const
{
	return animation;
}

const AnimationStruct* TextureComponent::getanimationconst() const
{
	return animation;
}

void TextureComponent::setbitmap(string p_str,int p_x,int p_y)
{
	xSize = p_x;
	ySize = p_y;

	if(enumBitmap::conversion(p_str) < E_Bitmap::MAX)
		bitmap = BitmapManager::getInstance()->getBitmap(enumBitmap::conversion(p_str), p_x, p_y);
}

HBITMAP TextureComponent::setbitmap(void* ptr)
{
	HBITMAP returnbit = bitmap;
	bitmap = (HBITMAP)ptr;
	return returnbit;
}

void TextureComponent::setrect(const Rect& p_rect)
{
	*rect = p_rect;
	transformset();
}

void TextureComponent::transformset()
{
	TransformComponent* Transform = GETCOMPONENT(owner, TransformComponent);
	if (Transform) {
		rect->setpivotptr(Transform->getpivotptr());
		rect->setrotateptr(Transform->getrotateptr());
	}
	UITransformComponent* UI = GETCOMPONENT(owner, UITransformComponent);
	if (UI) {
		rect->setpivotptr(UI->getpivotptr());
		rect->setrotateptr(UI->getrotateptr());
	}
}
