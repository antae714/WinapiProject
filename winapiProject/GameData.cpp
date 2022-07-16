#include "GameData.h"
#include "Vector2.h"

GameData::GameData()
{
	isgaming = true;
	windowX = WINDOWX;
	windowY = WINDOWY;
	backSound = BACKSOUND;
	effectSound = EFFECTSOUND;

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

int GameData::getbackSound()
{
	return backSound;
}

int GameData::geteffectSound()
{
	return effectSound;
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

void GameData::setbackSound(int p_val)
{
	backSound = p_val;
}

void GameData::seteffectSound(int p_val)
{
	effectSound = p_val;
}

void GameData::setcameraPivot(const Vector2& p_pivot)
{
	*cameraPivot = p_pivot;
}
