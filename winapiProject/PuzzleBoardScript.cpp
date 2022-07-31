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
#include "Macro.h"
#include "Math.h"
#include <fstream>

PuzzleBoardScript::PuzzleBoardScript()
{
	ifstream file;

	file.open(string("./Resource/Level/") + "balance" + ".txt");
	_ASSERT(!file.fail() && "¿¡·¯");

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
		answerVec.emplace_back(stoi(comp.at(0)), stoi(comp.at(1)));
		answercheck.push_back(stoi(comp.at(2)));
	}
	answerVec.resize(answerVec.size());
	answercheck.resize(answercheck.size());
	file.close();
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