#include "InputComponenet.h"
#include "TextureComponent.h"
#include "GameObject.h"
#include "InputCommand.h"
#include "Script.h"
#include "E_Component.h"
#include "Rect.h"
#include "Vector2.h"
#include "Math.h"
#include "WindowMsg.h"

InputComponenet::InputComponenet()
{
}

InputComponenet::~InputComponenet()
{
}

bool InputComponenet::isClicked()
{
	TextureComponent* tempcom2 = dynamic_cast<TextureComponent*>(owner->getcomponent(E_Component::TextureComponent));
	if (!tempcom2) return false;

	POINT tempPoint;
	GetCursorPos(&tempPoint);
	ScreenToClient(WindowMsg::getInstance()->gethWnd(), &tempPoint);

	return Math::isin(tempcom2->getrectptr(), Math::ScreentoCart(Vector2(tempPoint.x, tempPoint.y)));
}

void InputComponenet::Onclicked()
{
	if (InputCommand* tempcommand = dynamic_cast<InputCommand*>(owner->getscriptptr())) {
		tempcommand->play();
	}
}

