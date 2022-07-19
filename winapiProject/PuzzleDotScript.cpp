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
	isClicked = false;
}

void PuzzleDotScript::play()
{
	if (!isClicked)
	{
		setisClicked(true);
	}
	clickLogic();
}

bool PuzzleDotScript::getisClicked() const
{
	return isClicked;
}

void PuzzleDotScript::setisClicked(bool p_isClicked)
{
	isClicked = p_isClicked;
	if (isClicked)
	{
		TextureComponent* texture = GETCOMPONENT(owner, TextureComponent);
		texture->setbitmap("Starbutton_Selected", texture->getxSize(), texture->getySize());
	}
	else
	{
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
				//정답이면 라인second 이거로 바꾸기
				line->setsecond(owner);
				line->Setting();
			}
			else {
				GETSCRIPT(line->getfirstptr(), PuzzleDotScript)->setisClicked(false);
				setisClicked(false);
				allObject->deleteObj(iter);
			}
			break;
			//정답 판정후	아니면 라인지우고 islining 변경
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
