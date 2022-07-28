#include "TextScript.h"
#include "Macro.h"
#include "TextComponent.h"
#include "GameObject.h"
#include "E_Component.h"
#include "WindowMsg.h"
#include "GameTime.h"

TextScript::TextScript()
{
}

void TextScript::play()
{
	TextComponent* text = GETCOMPONENT(owner, TextComponent);
	accumulateTime += GameTime::getInstance()->getdeltaTime();
	if (accumulateTime >= 0.07) {
		accumulateTime -= 0.07;
		text->nextnownum();
	}
	WindowMsg* WindowMsg = WindowMsg::getInstance();
	if (WM_KEYDOWN != WindowMsg->getiMessage()) return;
	if (VK_RETURN != WindowMsg->getwParam()) return;
	WindowMsg->settingMsg(WindowMsg->gethWnd(), 0, 0, 0);
	text->nextLine();
}
