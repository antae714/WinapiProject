#include "PlayerScript.h"
#include "WindowMsg.h"
#include "GameData.h"
#include "GameObject.h"
#include "E_Component.h"
#include "TransformComponent.h"
#include "GameTime.h"
#include "TextureComponent.h"
#include "Vector2.h"
#include "Math.h"
#include "AllObject.h"
#include "E_Objtype.h"
#include "LineScript.h"
#include "Macro.h"
#include "UI_Hit.h"

#define VK_A 0x41
#define VK_S 0x53
#define VK_D 0x44
#define VK_W 0x57
#define VK_Q 0x51
#define VK_E 0x45

PlayerScript::PlayerScript()
{
	x = 0;
	y = 0;
	speed = PLAYERSPEED;
	moveState = E_PlayerState::Nomal;

	top = 0;
	bottom = 0;
	left = 0;
	right = 0;

	cooldown = 0;
	cooldown_sw = false;

	life = 5;
}

void PlayerScript::Update()
{
	InputLogic();
	MoveLogic();
	AbilityUpdate();
}

void PlayerScript::InputLogic()
{
	WindowMsg* windowMsg = WindowMsg::getInstance();
	const UINT& imsg = windowMsg->getiMessage();
	const WPARAM& wparam = windowMsg->getwParam();
	const Vector2* playerpos = dynamic_cast<TransformComponent*>(owner->getcomponent(E_Component::TransformComponent))->getpivotptr();

	if (imsg == WM_KEYDOWN) {
		if (wparam == VK_LEFT || wparam == VK_A) {
			x -= 1;
		}
		else if (wparam == VK_RIGHT || wparam == VK_D) {
			x += 1;
		}
		else if (wparam == VK_UP || wparam == VK_W) {
			y += 1;
		}
		else if (wparam == VK_DOWN || wparam == VK_S) {
			y -= 1;
		}
		else if (wparam == VK_SHIFT) {
			if (moveState != E_PlayerState::Puzzle) speed = PLAYERSPEED * 3;
		}
	}
	else if (imsg == WM_KEYUP) {
		if (wparam == VK_LEFT || wparam == VK_A) {
			x = 0;
		}
		else if (wparam == VK_RIGHT || wparam == VK_D) {
			x = 0;
		}
		else if (wparam == VK_UP || wparam == VK_W) {
			y = 0;
		}
		else if (wparam == VK_DOWN || wparam == VK_S) {
			y = 0;
		}
		else if (wparam == VK_SHIFT) {
			speed = PLAYERSPEED;
		}
	}
}

void PlayerScript::MoveLogic()
{
	GameTime* gameTime = GameTime::getInstance();
	TransformComponent* tempcom = dynamic_cast<TransformComponent*>(owner->getcomponent(E_Component::TransformComponent));

	tempcom->move(Vector2(x, y).GetNormalize() * speed * gameTime->getdeltaTime() * 100);

	LimitArea();
}

void PlayerScript::LimitArea()
{
	TransformComponent* tempcom = dynamic_cast<TransformComponent*>(owner->getcomponent(E_Component::TransformComponent));
	Vector2 temppivot = tempcom->getpivot();
	if (temppivot.getx() <= left)
	{
		temppivot.setx(left);
	}
	else if (temppivot.getx() >= right) {
		temppivot.setx(right);
	}
	if (temppivot.gety() >= top)
	{
		temppivot.sety(top);
	}
	else if (temppivot.gety() <= bottom) {
		temppivot.sety(bottom);
	}
	tempcom->setpivot(temppivot);
}

void PlayerScript::SetMovableArea()
{
	TextureComponent* tempcom = dynamic_cast<TextureComponent*>(owner->getcomponent(E_Component::TextureComponent));

	int top = WINDOWY / 2 - tempcom->getySize() / 2;
	int bottom = WINDOWY / -2 + tempcom->getySize() / 2;
	int left = WINDOWX / -2 + tempcom->getxSize() / 2;
	int right = WINDOWX / 2 - tempcom->getxSize() / 2;
}

void PlayerScript::SetMovableArea(int p_top, int p_bottom, int p_left, int p_right)
{
	top = p_top;
	bottom = p_bottom;
	left = p_left;
	right = p_right;
}

void PlayerScript::setmoveState(E_PlayerState p_moveState)
{
	moveState = p_moveState;
}

void PlayerScript::AbilityUpdate() {

	if (!cooldown_sw) {
		return;
	}

	GameTime* gameTime = GameTime::getInstance();
	cooldown += gameTime->getdeltaTime() * 100;

	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::puzzleMine);
	Vector2 playerpos = dynamic_cast<TransformComponent*>(owner->getcomponent(E_Component::TransformComponent))->getpivot();

	if (cooldown > 500) {
		TextureComponent* texture = dynamic_cast<TextureComponent*>(owner->getcomponent(E_Component::TextureComponent));
		texture->setbitmap("character2", texture->getxSize(), texture->getySize());
		cooldown_sw = false;

		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			dynamic_cast<TextureComponent*>(obj->getcomponent(E_Component::TextureComponent))->setbitmap("Green", 50, 50);
		}

		return;
	}

	for (ObjIter iter = temp.first; iter != temp.second; ++iter)
	{
		GameObject* obj = iter.operator*().second;
		Vector2 objpos = dynamic_cast<TransformComponent*>(obj->getcomponent(E_Component::TransformComponent))->getpivot();

		if (Math::lpts(objpos, playerpos, 250)) {
			dynamic_cast<TextureComponent*>(obj->getcomponent(E_Component::TextureComponent))->setbitmap("Starbutton_Fake", 50, 50);
		}
	}
}

void PlayerScript::Ability() {

	TextureComponent* texture = dynamic_cast<TextureComponent*>(owner->getcomponent(E_Component::TextureComponent));
	texture->setbitmap("character3", texture->getxSize(), texture->getySize());
	cooldown = 0;
	cooldown_sw = true;
}

void PlayerScript::onHit()
{
	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp2 = allObject->getallObj(E_Objtype::puzzleliner);
	for (ObjIter iter = temp2.first; iter != temp2.second; ++iter) {
		GameObject* obj = iter.operator*().second;
		LineScript* line = GETSCRIPT(obj, LineScript);
		if (!line->getisend()) {
			line->setisend(true);
			allObject->deleteObj(obj);
		}
	}

	pair<ObjIter, ObjIter> temp3 = allObject->getallObj(E_Objtype::background);
	for (ObjIter iter = temp3.first; iter != temp3.second; ++iter) {
		GameObject* obj = iter.operator*().second;
		UI_Hit* hit = GETSCRIPT(obj, UI_Hit);
		if (!hit) continue;

		hit->Hit();
		break;
	}

	Damage();
}

void PlayerScript::Damage() {
	--life;
}

void PlayerScript::LifeReset() {
	life = 5;
}

int PlayerScript::getLife() {
	return life;
}