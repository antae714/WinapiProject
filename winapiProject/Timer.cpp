#include "Timer.h"
#include "LevelData.h"
#include "AllObject.h"
#include "E_Objtype.h"
#include "E_Component.h"
#include "WindowMsg.h"
#include "GameTime.h"
#include "GameObject.h"
#include "TextComponent.h"
#include "Math.h"

Timer::Timer()
{
	count = 300;
	time = 300;
}


void Timer::Update()
{
	GameTime* gameTime = GameTime::getInstance();
	time -= gameTime->getdeltaTime();

	if (count > time) {
		--count;
		dynamic_cast<TextComponent*>(owner->getcomponent(E_Component::TextComponent))->nextLine();
	}
}

int Timer::getTime() {
	return count;
}