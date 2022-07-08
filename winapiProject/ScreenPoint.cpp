#include "ScreenPoint.h"
#include <Windows.h>

ScreenPoint::ScreenPoint() : x(0), y(0)
{
	
}

ScreenPoint::ScreenPoint(int p_x, int p_y) : x(p_x), y(p_y)
{
}

int ScreenPoint::getx()
{
	return x;
}

int ScreenPoint::gety()
{
	return y;
}

void ScreenPoint::setx(int p_x)
{
	x = p_x;
}

void ScreenPoint::sety(int p_y)
{
	y = p_y;
}

tagPOINT ScreenPoint::pointreturn()
{
	POINT temp;
	temp.x = this->x;
	temp.y = this->y;
	return temp;
}
