#include "MyBitmap.h"

MyBitmap::MyBitmap()
{
	bitmap = nullptr;
}

MyBitmap::MyBitmap(HDC p_dc, int p_x, int p_y)
{
	bitmap = CreateCompatibleBitmap(p_dc, p_x, p_y);
}

MyBitmap::~MyBitmap()
{
	if (bitmap)
		DeleteObject(bitmap);
}

MyBitmap* MyBitmap::CreateBitmap(HDC p_dc, int p_x, int p_y)
{
	bitmap = CreateCompatibleBitmap(p_dc, p_x, p_y);
	return this;
}

HBITMAP MyBitmap::operator()() {
	return bitmap;
}