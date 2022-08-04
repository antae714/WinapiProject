#include "TextureComponent.h"
#include "Vector2.h"
#include "Rect.h"
#include "GameObject.h"
#include "E_Component.h"
#include "TransformComponent.h"
#include "UITransformComponent.h"
#include "WindowMsg.h"
#include "BitmapManager.h"
#include "Macro.h"

TextureComponent::TextureComponent()
{
	bitmap = nullptr; 
	rect = new Rect();
}

TextureComponent::TextureComponent(const string& p_str, const Rect& p_rect)
{
	rect = new Rect();
	*rect = p_rect;
	setbitmap(p_str, p_rect.gethalfweight(), p_rect.gethalfweight());
}

TextureComponent::TextureComponent(const string& p_str, const Rect& p_rect , int p_x, int p_y)
{
	rect = new Rect();
	*rect = p_rect;
	setbitmap(p_str, p_x, p_y);
}

TextureComponent::~TextureComponent()
{
	delete rect;
} 

void TextureComponent::Start()
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

void TextureComponent::setbitmap(string p_str,int p_x,int p_y)
{
	xSize = p_x;
	ySize = p_y;
	if(enumBitmap::conversion(p_str) < E_Bitmap::MAX)
		bitmap = BitmapManager::getInstance()->getBitmap(enumBitmap::conversion(p_str), p_x, p_y);
}

void TextureComponent::setbitmap(void* ptr)
{
	bitmap = (HBITMAP)ptr;
}

void TextureComponent::setrect(const Rect& p_rect)
{
	*rect = p_rect;
}