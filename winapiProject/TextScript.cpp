#include "TextScript.h"
#include "Macro.h"
#include "TextComponent.h"
#include "GameObject.h"
#include "E_Component.h"
#include "AllObject.h"
#include "UITransformComponent.h"
#include "TextureComponent.h"
#include "TextComponent.h"
#include "InputComponenet.h"
#include "Rect.h"
#include "E_Objtype.h"

TextScript::TextScript()
{
}

void TextScript::play()
{
	if (!textobj) {
		AllObject* allObject = AllObject::getInstance();
		GameObject* gameObject = new GameObject();
		gameObject->pushcomponent(E_Component::UITransformComponent, new UITransformComponent(Vector2(640, 590), 0));
		gameObject->pushcomponent(E_Component::TextureComponent, new TextureComponent("Dialog",Rect(0,500,248)));
		gameObject->pushcomponent(E_Component::TextComponent, new TextComponent(Vector2(450,580), "Test"));
		gameObject->pushcomponent(E_Component::InputComponenet, new InputComponenet());
		gameObject->Start();
		allObject->push(E_Objtype::text, gameObject);
		textobj = gameObject;
	}
	else {
		TextComponent* text = GETCOMPONENT(textobj, TextComponent);
		if (!text->nextLine()) {
			AllObject::getInstance()->deleteObj(textobj);
			textobj = nullptr;
		}
	}
}
