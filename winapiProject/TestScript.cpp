#include "TestScript.h"
#include "WindowMsg.h"
#include "GameObject.h"
#include "E_Component.h"
#include "TransformComponent.h"
#include "Vector2.h"
#include "GameObject.h"

#define VK_A 0x41
#define VK_S 0x53
#define VK_D 0x44
#define VK_W 0x57

TestScript::TestScript()
{
	x = 0;
	y = 0;
	speed = 2;
}

void TestScript::play()
{
	InputLogic();
	MoveLogic();
}

void TestScript::InputLogic()
{
	WindowMsg* windowMsg = WindowMsg::getInstance();
	const UINT& imsg = windowMsg->getiMessage();
	const WPARAM& wparam = windowMsg->getwParam();

	if (imsg == WM_KEYDOWN) {
		if (wparam == VK_LEFT || wparam == VK_A) {
			Fnptrplay.emplace(VK_LEFT, &TestScript::xminus);
		}
		else if (wparam == VK_RIGHT || wparam == VK_D) {
			Fnptrplay.emplace(VK_RIGHT, &TestScript::xplus);
		}
		else if (wparam == VK_UP || wparam == VK_W) {
			Fnptrplay.emplace(VK_UP, &TestScript::yplus);
		}
		else if (wparam == VK_DOWN || wparam == VK_S) {
			Fnptrplay.emplace(VK_DOWN, &TestScript::yminus);
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

void TestScript::MoveLogic()
{
	for (const pair<int, void(TestScript::*)()>& item : Fnptrplay) {
		(this->*item.second)();
	}
	TransformComponent* tempcom = dynamic_cast<TransformComponent*>(owner->getcomponent(E_Component::TransformComponent));

	tempcom->setpivot(tempcom->getpivot() + Vector2(x, y).GetNormalize() * speed);
	x = 0;
	y = 0;
}

void TestScript::PuzzleLogic()
{
}

void TestScript::xplus()
{
	++x;
}

void TestScript::xminus()
{
	--x;
}

void TestScript::yplus()
{
	++y;
}

void TestScript::yminus()
{
	--y;
}

