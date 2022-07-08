#pragma once

struct tagPOINT;
class ScreenPoint
{
private:
	int x;
	int y;

public:
	ScreenPoint();
	ScreenPoint(int p_x, int p_y);

public:
	int getx();
	int gety();
	void setx(int);
	void sety(int);

	tagPOINT pointreturn();
};

