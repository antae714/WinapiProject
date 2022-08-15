#include "PuzzleAbility.h"
#include "GameObject.h"
#include "AllObject.h"
#include "E_Objtype.h"
#include "PlayerScript.h"
#include "Macro.h"
#include "PuzzleData.h"

PuzzleAbility::PuzzleAbility() {
}

void PuzzleAbility::KeyInput() {
	if (PuzzleData::getInstance()->getisclear()) return;

	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::character);
	for (ObjIter iter = temp.first; iter != temp.second; ++iter)
	{
		GameObject* obj = iter.operator*().second;
		GETSCRIPT(obj, PlayerScript)->Ability();
		break;
	}

	owner->setisActive(false);
}