#include "TestScript.h"
#include "WindowMsg.h"
#include "GameObject.h"
#include "E_Component.h"
#include "TransformComponent.h"
#include "Vector2.h"

#define VK_A 0x41
#define VK_S 0x53
#define VK_D 0x44
#define VK_W 0x57
#define VK_Q 0x51
#define VK_E 0x45


void TestScript::play()
{
	WindowMsg* windowMsg = WindowMsg::getInstance();
	const UINT& imsg = windowMsg->getiMessage();
	const WPARAM& wparam = windowMsg->getwParam();
	if (imsg == WM_KEYDOWN) {
		int x = 0, y = 0;
		if (wparam == VK_LEFT || wparam == VK_A) {
			--x;
		}
		else if (wparam == VK_RIGHT || wparam == VK_D) {
			++x;

		}
		else if (wparam == VK_UP || wparam == VK_S) {
			++y;
		}
		else if (wparam == VK_DOWN || wparam == VK_W) {
			--y;
		}
		float reotate = 0;
		if (wparam == VK_Q) {
			reotate -= 0.1;
		}
		else if (wparam == VK_E) {
			reotate += 0.1;
		}
		TransformComponent* tempcom = dynamic_cast<TransformComponent*>(owner->getcomponent(E_Component::TransformComponent));
		tempcom->setpivot(tempcom->getpivot() + Vector2(x, y).GetNormalize()*2);
		tempcom->setrotate(tempcom->getrotate() + reotate);
	}
}

