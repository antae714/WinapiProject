#include "PuzzleBoardScript.h"
#include "LevelData.h"
#include "E_Objtype.h"
#include "AllObject.h"
#include "Vector2.h"
#include "PuzzleDotScript.h"
#include "TransformComponent.h"
#include "E_Component.h"
#include "GameObject.h"

PuzzleBoardScript::PuzzleBoardScript()
{
	answercheck = 0;
}

bool PuzzleBoardScript::isAnswer(const GameObject* p_first, const GameObject* p_second)
{
	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::puzzleDot);

	int count = 0;
	bool stagesw[81] = { 0, };
	pair<int, int> pair(-1, -1);
	for (ObjIter iter = temp.first; iter != temp.second; ++iter, ++count)
	{
		GameObject* obj = iter.operator*().second;
		if (obj == p_first || obj == p_second) {
			if (-1 == pair.first) {
				pair.first = count;
			}
			else {
				pair.second = count;
			}
		}
	}

	if (pair.first == 13 && pair.second == 30) {
		answer();
		return true;
	}
	if (pair.first == 30 && pair.second == 38) {
		answer();
		return true;
	}
	if (pair.first == 38 && pair.second == 45) {
		answer();
		return true;
	}
	if (pair.first == 13 && pair.second == 60) {
		answer();
		return true;
	}
	if (pair.first == 13 && pair.second == 34) {
		answer();
		return true;
	}
	if (pair.first == 34 && pair.second == 60) {
		answer();
		return true;
	}
	if (pair.first == 60 && pair.second == 66) {
		answer();
		return true;
	}
	if (pair.first == 66 && pair.second == 75) {
		answer();
		return true;
	}

	return false;

}


void PuzzleBoardScript::answer()
{
	++answercheck;
	if (8 == answercheck)
	{
		LevelData::LevelLode(E_Objtype::puzzlecleartest);
	}
}