#include "GameData.h"
#include "Vector2.h"

GameData::GameData()
{
	isgaming = true;
	windowX = WINDOWX;
	windowY = WINDOWY;
	cameraPivot = new Vector2(0,0);
}

bool GameData::getisgaming()
{
	return isgaming;
}

int GameData::getwindowX()
{
	return windowX;
}

int GameData::getwindowY()
{
	return windowY;
}

const Vector2& GameData::getcameraPivot()
{
	return *cameraPivot;
}

void GameData::setisgaming(bool p_bool)
{
	isgaming = p_bool;
}

void GameData::setwindowX(int p_windowX)
{
	windowX = p_windowX;
}

void GameData::setwindowY(int p_windowY)
{
	windowY = p_windowY;
}

void GameData::setcameraPivot(const Vector2& p_pivot)
{
	*cameraPivot = p_pivot;
}
