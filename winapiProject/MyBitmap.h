#pragma once
#include <Windows.h>
class MyBitmap
{
private:
	HBITMAP bitmap;

public:
	MyBitmap();
	MyBitmap(HDC, int, int);
	virtual ~MyBitmap();

public:
	MyBitmap* CreateBitmap(HDC, int, int);
	HBITMAP operator()();
};

