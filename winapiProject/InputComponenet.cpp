#include "InputComponenet.h"
#include "TextureComponent.h"
#include "GameObject.h"
#include "InputFunction.h"
#include "Script.h"
#include "E_Component.h"
#include "Rect.h"
#include "Vector2.h"
#include "Math.h"
#include "Macro.h"
#include "WindowMsg.h"

InputComponenet::InputComponenet()
{
}

InputComponenet::~InputComponenet()
{
}

bool InputComponenet::isClicked()
{
	TextureComponent* texture = dynamic_cast<TextureComponent*>(owner->getcomponent(E_Component::TextureComponent));
	if (!texture) return false;

	POINT tempPoint;
	GetCursorPos(&tempPoint);
	ScreenToClient(WindowMsg::getInstance()->gethWnd(), &tempPoint);
	Vector2 tempVec(tempPoint.x, tempPoint.y);
	if (owner->getcomponent(E_Component::TransformComponent)) {
		tempVec = Math::ScreentoCart(tempVec);
	}
	return Math::isin(texture->getrectptr(), tempVec);
}

void InputComponenet::Onclicked()
{
	if (InputFunction* tempcommand = dynamic_cast<InputFunction*>(owner->getscriptptr())) {
		tempcommand->play();
	}
}

