#include "UI_Hit.h"
#include "LevelData.h"
#include "AllObject.h"
#include "E_Objtype.h"
#include "E_Component.h"
#include "WindowMsg.h"
#include "GameTime.h"
#include "Camera.h"
#include "GameObject.h"
#include "TransformComponent.h"
#include "TextureComponent.h"
#include "CollisonCompoenet.h"
#include "Vector2.h"
#include "SoundManager.h"
#include "Math.h"

UI_Hit::UI_Hit()
{
	cooldown = 0;
	cooldown_sw = false;
}

void UI_Hit::Update()
{
	if (!cooldown_sw) {
		return;
	}

	GameTime* gameTime = GameTime::getInstance();
	cooldown += gameTime->getdeltaTime() * 100;

	if (cooldown > 40) {
		TextureComponent* texture = dynamic_cast<TextureComponent*>(owner->getcomponent(E_Component::TextureComponent));
		texture->setbitmap("UI_Character", texture->getxSize(), texture->getySize());
		cooldown_sw = false;
	}
}

void UI_Hit::Hit() {

	TextureComponent* texture = dynamic_cast<TextureComponent*>(owner->getcomponent(E_Component::TextureComponent));
	texture->setbitmap("UI_Character_Hit", texture->getxSize(), texture->getySize());
	cooldown = 0;
	cooldown_sw = true;
}