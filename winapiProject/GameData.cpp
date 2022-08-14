#include "GameData.h"
#include "Vector2.h"
#include "Rect.h"

GameData::GameData()
{
	isgaming = true;
	windowX = WINDOWX + 16;
	windowY = WINDOWY + 39;
	backSound = BACKSOUND;
	effectSound = EFFECTSOUND;

	cameraPivot = nullptr;
}

GameData::~GameData()
{
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

int GameData::getIngamewindowX()
{
	return windowX - 16;
}

int GameData::getIngamewindowY()
{
	return windowY - 39;
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
	if (cameraLimit) {
		int limitx = cameraLimit->gethalfweight() - windowX * 0.5;
		int limity = cameraLimit->gethalfheight() - windowY * 0.5;
		Vector2 tempVec = cameraLimit->getpivot() + *cameraPivot;
		if (cameraPivot) {
			if (abs(tempVec.getx()) > limitx) {
				if (tempVec.getx() < 0)
					tempVec.setx(-limitx);
				else
					tempVec.setx(limitx);
			}
			if (abs(tempVec.gety()) > limity) {
				if (tempVec.gety() < 0)
					tempVec.sety(-limity);
				else
					tempVec.sety(limity);
			}
			return tempVec;
		}
		else {
			return Vector2(0, 0);
		}
	}
	else {
		if (cameraPivot) {
			return *cameraPivot;
		}
		else {
			return Vector2(0, 0);
		}

	}

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

void GameData::setcameraPivot(const Vector2* p_pivot, const Rect* limit)
{
	cameraPivot = p_pivot;
	cameraLimit = limit;
}
