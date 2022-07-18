#pragma once
#include <Windows.h>
class MemDc
{
private:
	HDC memDc;
	HBITMAP oldbitmap;
public:
	MemDc(HDC);
	MemDc(HDC, HBITMAP);
	virtual ~MemDc();

public:
	void SelectObject_(HBITMAP);
	HDC getMemDC() const;

	HDC operator()() const;
};

