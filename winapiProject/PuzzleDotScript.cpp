#include "PuzzleDotScript.h"
#include "TextureComponent.h"
#include "TransformComponent.h"
#include "GameObject.h"
#include "E_Component.h"
#include "AllObject.h"
#include "E_Objtype.h"
#include "Macro.h"
#include "LineScript.h"
#include "PuzzleBoardScript.h"

PuzzleDotScript::PuzzleDotScript()
{
	refCount = 0;
}

PuzzleDotScript::~PuzzleDotScript()
{
}

void PuzzleDotScript::play()
{
	clickLogic();
}

void PuzzleDotScript::plusrefCount()
{
	if (0 < ++refCount)
	{
		TextureComponent* texture = GETCOMPONENT(owner, TextureComponent);
		texture->setbitmap("Starbutton_Selected", texture->getxSize(), texture->getySize());
	}
}

void PuzzleDotScript::minusrefCount()
{
	if (0 >= --refCount) {
		TextureComponent* texture = GETCOMPONENT(owner, TextureComponent);
		texture->setbitmap("Starbutton", texture->getxSize(), texture->getySize());
	}
}

void PuzzleDotScript::clickLogic()
{
	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::puzzleliner);

	bool islining = true;
	for (ObjIter iter = temp.first; iter != temp.second; ++iter) {
		GameObject* obj = iter.operator*().second;
		LineScript* line = GETSCRIPT(obj, LineScript);
		if (!line->getisend()) {
			islining = false;
			line->setisend(true);

			pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::PuzzleBoard);
			PuzzleBoardScript* puzzle = GETSCRIPT(temp.first.operator*().second, PuzzleBoardScript);

			if (puzzle->isAnswer(owner, line->getfirstptr())) {
				line->setsecond(owner);
				plusrefCount();
				line->Setting();
			}
			else {
				allObject->deleteObj(iter);
			}
			break;
		}
	}

	if (islining) {
		pair<ObjIter, ObjIter> player = allObject->getallObj(E_Objtype::character);
		GameObject* tempobj = new GameObject();
		tempobj->pushcomponent(E_Component::TransformComponent, new TransformComponent());
		tempobj->pushcomponent(E_Component::TextureComponent, new TextureComponent());
		tempobj->setscript(new LineScript(owner, player.first.operator*().second));
		tempobj->Start();
		AllObject::getInstance()->push(E_Objtype::puzzleliner, tempobj);
	}
}
