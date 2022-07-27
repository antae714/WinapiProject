#include "TextScript.h"
#include "Macro.h"
#include "TextComponent.h"
#include "GameObject.h"
#include "E_Component.h"
#include "WindowMsg.h"

TextScript::TextScript()
{
}

void TextScript::play()
{
	WindowMsg* WindowMsg = WindowMsg::getInstance();
	if (WM_KEYDOWN != WindowMsg->getiMessage()) return;
	if (VK_RETURN != WindowMsg->getwParam()) return;
	WindowMsg->settingMsg(WindowMsg->gethWnd(), 0, 0, 0);
	TextComponent* text = GETCOMPONENT(owner, TextComponent);
	text->nextLine();
}
