#include "PuzzleBoardScript.h"
#include "LevelData.h"
#include "E_Objtype.h"
#include "AllObject.h"
#include "Vector2.h"
#include "PuzzleDotScript.h"
#include "TransformComponent.h"
#include "E_Component.h"
#include "GameObject.h"
#include "TextureComponent.h"
#include "LineScript.h"
#include "PuzzleMine.h"
#include "Macro.h"
#include "Math.h"
#include "Rect.h"
#include <fstream>

PuzzleBoardScript::PuzzleBoardScript()
{
	ifstream file;

	file.open(string("./Resource/Level/") + "balance" + ".txt");
	_ASSERT(!file.fail() && "¿¡·¯");

	bool deny_creation[81] = { 0, };
	while (!file.eof())
	{
		string line;
		getline(file, line);
		if ('\0' == line[0]) continue;
		if ('/' == line[0]) continue;
		string value;
		vector<string> comp;
		while (0 != line.length())
		{
			for (int i = 0; i < line.length(); ++i)
			{
				if (',' == line[i])
				{
					value = line.substr(0, i);
					comp.push_back(value);
					line = line.substr(i + 1);
					break;
				}
			}
		}
		deny_creation[stoi(comp.at(0))] = true;
		deny_creation[stoi(comp.at(1))] = true;
		answerVec.emplace_back(stoi(comp.at(0)), stoi(comp.at(1)));
		answercheck.push_back(stoi(comp.at(2)));
	}
	answerVec.resize(answerVec.size());
	answercheck.resize(answercheck.size());
	file.close();

	vector<int> mine_avoid;
	mine_avoid.push_back(40);
	for (int i = 0; i < 81; ++i) {
		if (deny_creation[i] == true) {
			mine_avoid.push_back(i);
		}
	}

	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::puzzleDot);

	for (int i = 0; i < 15; ++i) {
		int rd;

		while (1) {
			bool repeated = false;
			rd = rand() % 81;

			for (int j = 0; j < mine_avoid.size(); ++j) {
				if (rd == mine_avoid[j]) {
					repeated = true;
					break;
				}
			}

			if (!repeated) {
				break;
			}
		}
		mine_avoid.push_back(rd);

		GameObject* gameObject = new GameObject();
		gameObject->pushcomponent(E_Component::TextureComponent, new TextureComponent("Green", Rect(0.f, 50.f, 50.f), 50, 50));
		GameObject* obj = nullptr;
		TransformComponent* posit = nullptr;

		int j = 0;
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			if (j == rd) {
				obj = iter.operator*().second;
				posit = dynamic_cast<TransformComponent*>(obj->getcomponent(E_Component::TransformComponent));
				break;
			}
			++j;
		}		
		gameObject->pushcomponent(E_Component::TransformComponent, new TransformComponent(posit->getpivot(), 0));

		gameObject->setscript(new PuzzleMine(obj));
		gameObject->Start();

		allObject->push(E_Objtype::puzzleMine, gameObject);
	}
}

bool PuzzleBoardScript::isAnswer(const GameObject* p_first, const GameObject* p_second)
{
	int first = GETSCRIPT(p_first, PuzzleDotScript)->getnumber();
	int second = GETSCRIPT(p_second, PuzzleDotScript)->getnumber();
	if (first > second) Math::Swap(first, second);
	pair<int, int> temppair(first, second);
	
	for (int i = 0; i < answerVec.size(); ++i) {
		if (temppair == answerVec.at(i)) {
			answer(i);
			return true;
		}
	}
	return false;

}

void PuzzleBoardScript::Start()
{
	for (int i = 0; i < answercheck.size(); ++i) {
		if (answercheck.at(i)) {
			GameObject* tempobj = new GameObject();
			tempobj->pushcomponent(E_Component::TransformComponent, new TransformComponent());
			tempobj->pushcomponent(E_Component::TextureComponent, new TextureComponent());
			LineScript* line = new LineScript();
			line->Set(answerVec.at(i).first, answerVec.at(i).second, true);
			tempobj->setscript(line);
			tempobj->Start();
			AllObject::getInstance()->push(E_Objtype::puzzleliner, tempobj);
		}
	}
}


void PuzzleBoardScript::answer(int p_val)
{
	answercheck.at(p_val) = true;
	for (bool item : answercheck) {
		if (!item) return;
	}
	LevelData::LevelLode(E_Objtype::puzzlecleartest);
}