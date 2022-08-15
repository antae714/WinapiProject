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
#include "CollisonCompoenet.h"
#include "PuzzleEnemy1.h"
#include "PuzzleEnemy2.h"
#include "AnimationStruct.h"
#include "PlayerScript.h"
#include "GameData.h"
#include "PuzzleData.h"
#include <fstream>

PuzzleBoardScript::PuzzleBoardScript()
{
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

void PuzzleBoardScript::AnswerDelete(const GameObject* p_first, const GameObject* p_second)
{
	int first = GETSCRIPT(p_first, PuzzleDotScript)->getnumber();
	int second = GETSCRIPT(p_second, PuzzleDotScript)->getnumber();
	if (first > second) Math::Swap(first, second);
	pair<int, int> temppair(first, second);

	for (int i = 0; i < answerVec.size(); ++i) {
		if (temppair == answerVec.at(i)) {
			answercheck.at(i) = false;
			break;
		}
	}
}

void PuzzleBoardScript::Start()
{
	AllObject* allObject = AllObject::getInstance();
	for (int i = 0; i < answercheck.size(); ++i) {
		if (answercheck.at(i)) {
			GameObject* tempobj = new GameObject();
			tempobj->pushcomponent(E_Component::TransformComponent, new TransformComponent());
			tempobj->pushcomponent(E_Component::TextureComponent, new TextureComponent());
			LineScript* line = new LineScript();
			tempobj->setscript(line);
			line->Set(answerVec.at(i).first, answerVec.at(i).second, true);
			tempobj->Start();
			allObject->push(E_Objtype::puzzleliner, tempobj);
		}
	}

	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::puzzleEnemy);
	for (ObjIter iter = temp.first; iter != temp.second; ++iter) {
		PuzzleEnemy2* enemy2 = GETSCRIPT((*iter).second, PuzzleEnemy2);
		if (enemy2) {
			enemy2->Init();
		}
	}
}

void PuzzleBoardScript::Set(const string& type, string p_varias)
{
	varias = p_varias;
	ifstream file;

	file.open(string("./Resource/Level/") + type + ".txt");
	_ASSERT(!file.fail() && "에러");

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

		if (comp.at(0) == "Dot") {
			deny_creation[stoi(comp.at(1))] = true;
			deny_creation[stoi(comp.at(2))] = true;
			answerVec.emplace_back(stoi(comp.at(1)), stoi(comp.at(2)));
			answercheck.push_back(stoi(comp.at(3)));
		}

		if (comp.at(0) == "Enenmy") {
			if (comp.at(1) == "chaser") {
				{
					//추격자
					AllObject* allObject = AllObject::getInstance();
					GameObject* gameObject = new GameObject();
					Rect rect(50.f, 50.f);
					gameObject->pushcomponent(E_Component::TransformComponent, new TransformComponent(Vector2(), 0));
					gameObject->pushcomponent(E_Component::TextureComponent, new TextureComponent("chaser", rect));
					gameObject->pushcomponent(E_Component::CollisonCompoenet, new CollisonCompoenet(rect));
					PuzzleEnemy1* enemy = new PuzzleEnemy1();
					enemy->Set(stoi(comp.at(2)));
					gameObject->setscript(enemy);
					allObject->push(E_Objtype::puzzleEnemy, gameObject);
				}
			}
			else if (comp.at(1) == "Ant") {
				{
					AllObject* allObject = AllObject::getInstance();
					GameObject* gameObject = new GameObject();
					Rect rect(50.f, 50.f);
					gameObject->pushcomponent(E_Component::TransformComponent, new TransformComponent(Vector2(), 0));
					vector<string> tempvec{ "move" };
					vector<int> temp2vec{ 2 };
					gameObject->pushcomponent(E_Component::TextureComponent, new TextureComponent(AnimationStruct(0.3, "Ant", tempvec, temp2vec), rect));
					PuzzleEnemy2* enemy = new PuzzleEnemy2();
					enemy->Set(stoi(comp.at(2)));
					gameObject->setscript(enemy);
					allObject->push(E_Objtype::puzzleEnemy, gameObject);
				}
			}
		}
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
		gameObject->pushcomponent(E_Component::TextureComponent, new TextureComponent("Green", Rect(50.f, 50.f)));
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

void PuzzleBoardScript::answer(int p_val)
{
	answercheck.at(p_val) = true;
	for (bool item : answercheck) {
		if (!item) return;
	}
	PuzzleData::getInstance()->setisclear(true);

	AllObject* allObject = AllObject::getInstance();
	GameObject* player = (*allObject->getallObj(E_Objtype::character).first).second;
	PlayerScript* tempscr = dynamic_cast<PlayerScript*>(player->getscriptptr());
	tempscr->setismove(false);

	LevelData::LevelLode(E_Objtype::puzzlecleartest);

	
	GameData* gamedata = GameData::getInstance();
	gamedata->setvarias(varias, gamedata->getvarias(varias) + 1);
}