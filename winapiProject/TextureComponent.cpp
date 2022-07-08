#include "TextureComponent.h"
#include "Vector2.h"
#include "Rect.h"
#include "GameObject.h"
#include "E_Component.h"
#include "TransformComponent.h"
#include "WindowMsg.h"
#include "BitmapManager.h"

TextureComponent::TextureComponent()
{
	bitmap = nullptr; 
	rect = new Rect();
}

TextureComponent::TextureComponent(const string& p_str, const Rect& p_rect , int p_x, int p_y) : rect(new Rect(p_rect))
{
	setbitmap(p_str, p_x, p_y);
}

TextureComponent::~TextureComponent()
{
	//DeleteBitmap();
	delete rect;
} 

void TextureComponent::Start()
{
	if (Component* tempcomponenet = owner->getcomponent(E_Component::TransformComponent)) {
		TransformComponent* temp = dynamic_cast<TransformComponent*>(tempcomponenet);
		rect->setpivotptr(temp->getpivotptr());
		rect->setrotateptr(temp->getrotateptr());
	}

}

HBITMAP TextureComponent::getbitmap()
{
	return bitmap;
}

Rect TextureComponent::getrect()
{
	return *rect;
}

const Rect& TextureComponent::getrectptr()
{
	return *rect;
}

int TextureComponent::getxSize()
{
	return xSize;
}

int TextureComponent::getySize()
{
	return ySize;
}

void TextureComponent::setbitmap(string p_str,int p_x,int p_y)
{
	//DeleteBitmap();
	xSize = p_x;
	ySize = p_y;
	_ASSERT(enumBitmap::conversion(p_str) < E_Bitmap::MAX);
	if(enumBitmap::conversion(p_str) < E_Bitmap::MAX)
		bitmap = BitmapManager::getInstance()->getBitmap(enumBitmap::conversion(p_str), p_x, p_y);
	//bitmap = (HBITMAP)LoadImage(NULL, p_str.c_str(), IMAGE_BITMAP, xSize, ySize, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
}

void TextureComponent::setrect(const Rect& p_rect)
{
	*rect = p_rect;
}
//
//void TextureComponent::DeleteBitmap()
//{
//	if (bitmap) {
//		DeleteObject(bitmap);
//		bitmap = nullptr;
//	}
//}