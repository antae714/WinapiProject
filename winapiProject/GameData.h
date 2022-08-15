#pragma once

#include "SingletonCls.h"
#include <map>
#include <string>

#define WINDOWX 1280
#define WINDOWY 720
#define BACKSOUND 100
#define EFFECTSOUND 100

class Vector2;
class Rect;

class GameData : public SingletonCls<GameData>
{
private:
	bool isgaming;
	int windowX;
	int windowY;
	int backSound;
	int effectSound;
	const Vector2* cameraPivot;
	const Rect* cameraLimit;
	map<string, int> game_varias;

public:
	GameData();
	virtual ~GameData();

public:
	bool getisgaming();
	int getwindowX();
	int getwindowY();
	int getIngamewindowX();
	int getIngamewindowY();
	int getbackSound();
	int geteffectSound();
	const Vector2& getcameraPivot();
	int getvarias(string);

	void setisgaming(bool);
	void setwindowX(int);
	void setwindowY(int);
	void setbackSound(int);
	void seteffectSound(int);
	void setcameraPivot(const Vector2* pivot, const Rect* limit);
	void setvarias(string, int);
	void resetvarias();
};

