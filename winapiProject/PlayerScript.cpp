#include "PlayerScript.h"
#include "WindowMsg.h"
#include "GameData.h"
#include "GameObject.h"
#include "E_Component.h"
#include "TransformComponent.h"
#include "TextureComponent.h"
#include "Vector2.h"

#define VK_A 0x41
#define VK_S 0x53
#define VK_D 0x44
#define VK_W 0x57

PlayerScript::PlayerScript()
{
	x = 0;
	y = 0;
	speed = 2;

	top = 0;
	bottom = 0;
	left = 0;
	right = 0;
}

void PlayerScript::play()
{
	InputLogic();
	MoveLogic();
}

void PlayerScript::InputLogic()
{
	WindowMsg* windowMsg = WindowMsg::getInstance();
	const UINT& imsg = windowMsg->getiMessage();
	const WPARAM& wparam = windowMsg->getwParam();
	const Vector2* playerpos = dynamic_cast<TransformComponent*>(owner->getcomponent(E_Component::TransformComponent))->getpivotptr();

	if (imsg == WM_KEYDOWN) {
		if (wparam == VK_LEFT || wparam == VK_A) {
			Fnptrplay.emplace(VK_LEFT, &PlayerScript::xminus);
		}
		else if (wparam == VK_RIGHT || wparam == VK_D) {
			Fnptrplay.emplace(VK_RIGHT, &PlayerScript::xplus);
		}
		else if (wparam == VK_UP || wparam == VK_W) {
			Fnptrplay.emplace(VK_UP, &PlayerScript::yplus);
		}
		else if (wparam == VK_DOWN || wparam == VK_S) {
			Fnptrplay.emplace(VK_DOWN, &PlayerScript::yminus);
		}
		else if (wparam == VK_SHIFT) {
			speed = 6;
		}
	}
	else if (imsg == WM_KEYUP) {
		if (wparam == VK_LEFT || wparam == VK_A) {
			Fnptrplay.erase(VK_LEFT);
		}
		else if (wparam == VK_RIGHT || wparam == VK_D) {
			Fnptrplay.erase(VK_RIGHT);
		}
		else if (wparam == VK_UP || wparam == VK_W) {
			Fnptrplay.erase(VK_UP);
		}
		else if (wparam == VK_DOWN || wparam == VK_S) {
			Fnptrplay.erase(VK_DOWN);
		}
		else if (wparam == VK_SHIFT) {
			speed = 2;
		}
	}
}

void PlayerScript::MoveLogic()
{
	for (const pair<int, void(PlayerScript::*)()>& item : Fnptrplay) {
		(this->*item.second)();
	}
	TransformComponent* tempcom = dynamic_cast<TransformComponent*>(owner->getcomponent(E_Component::TransformComponent));

	if ((tempcom->getpivot().getx() - speed >= left || x > 0) &&
		(tempcom->getpivot().getx() + speed <= right || x < 0))
	{
		tempcom->setpivot(tempcom->getpivot() + Vector2(x, 0).GetNormalize() * speed);
	}
	if ((tempcom->getpivot().gety() + speed <= top || y < 0) &&
		(tempcom->getpivot().gety() - speed >= bottom || y > 0))
	{
		tempcom->setpivot(tempcom->getpivot() + Vector2(0, y).GetNormalize() * speed);
	}

	x = 0;
	y = 0;
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

void PlayerScript::xplus()
{
	++x;
}

void PlayerScript::xminus()
{
	--x;
}

void PlayerScript::yplus()
{
	++y;
}

void PlayerScript::yminus()
{
	--y;
}
