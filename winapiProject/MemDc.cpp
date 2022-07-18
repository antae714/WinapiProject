#include "MemDc.h"

MemDc::MemDc(HDC p_hdc)
{
	memDc = CreateCompatibleDC(p_hdc);
	oldbitmap = nullptr;
}

MemDc::MemDc(HDC p_hdc, HBITMAP p_bit)
{
	memDc = CreateCompatibleDC(p_hdc);
	oldbitmap = (HBITMAP)SelectObject(memDc, p_bit);
}

MemDc::~MemDc()
{
	SelectObject(memDc, oldbitmap);
	DeleteDC(memDc);
}

void MemDc::SelectObject_(HBITMAP p_bit)
{
	oldbitmap = (HBITMAP)SelectObject(memDc, p_bit);
}

HDC MemDc::getMemDC() const
{
	return memDc;
}
HDC MemDc::operator()() const 
{
	return memDc;
}