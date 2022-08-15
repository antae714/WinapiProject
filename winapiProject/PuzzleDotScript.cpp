#include "PuzzleDotScript.h"
#include "KeyInputComponent.h"
#include "TextureComponent.h"
#include "TransformComponent.h"
#include "GameObject.h"
#include "E_Component.h"
#include "AllObject.h"
#include "E_Objtype.h"
#include "Macro.h"
#include "Rect.h"
#include "LineScript.h"
#include "PuzzleBoardScript.h"
#include "PuzzleAbility.h"
#include "PuzzleBoardScript.h"
#include "PuzzleData.h"

PuzzleDotScript::PuzzleDotScript() :
	refCount(0), number(0)
{
}

PuzzleDotScript::PuzzleDotScript(int p_number) :
	refCount(0), number(p_number)
{
}

PuzzleDotScript::~PuzzleDotScript()
{
}

void PuzzleDotScript::KeyInput()
{
	if (PuzzleData::getInstance()->getisclear()) return;

	clickLogic();
}

void PuzzleDotScript::plusrefCount(GameObject* p_line)
{
	line.push_back(p_line);
	if (1 == ++refCount)
	{
		TextureComponent* texture = GETCOMPONENT(owner, TextureComponent);
		texture->setbitmap("Starbutton_Selected", texture->getxSize(), texture->getySize());
		if (!status && GETSCRIPT(line.back(), LineScript)->getisend()) {
			status = 1;
			CreateAbility();
		}
	}
}

void PuzzleDotScript::cut()
{
	AllObject* allObject = AllObject::getInstance();
	for (GameObject* item : line) {
		allObject->deleteObj(item);
	}
	line.clear();
}

void PuzzleDotScript::minusrefCount()
{
	if (0 == --refCount) {
		TextureComponent* texture = GETCOMPONENT(owner, TextureComponent);
		texture->setbitmap("Starbutton", texture->getxSize(), texture->getySize());
	}
}

int PuzzleDotScript::getrefCount()
{
	return refCount;
}

int PuzzleDotScript::getnumber()
{
	return number;
}

void PuzzleDotScript::setnumber(int p_number)
{
	number = p_number;
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
				plusrefCount(obj);
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

void PuzzleDotScript::CreateAbility() {

	AllObject* allObject = AllObject::getInstance();
	GameObject* gameObject = new GameObject();
	gameObject->pushcomponent(E_Component::TextureComponent, new TextureComponent("Green", Rect(50.f, 50.f)));
	TransformComponent* posit = dynamic_cast<TransformComponent*>(owner->getcomponent(E_Component::TransformComponent));
	gameObject->pushcomponent(E_Component::TransformComponent, new TransformComponent(posit->getpivot(), 0));
	KeyInputComponenet* keyinput = new KeyInputComponenet();
	keyinput->setkey(0x58);
	gameObject->pushcomponent(E_Component::KeyInputComponenet, keyinput);

	gameObject->setscript(new PuzzleAbility());
	gameObject->Start();

	allObject->push(E_Objtype::puzzleAbility, gameObject);
}