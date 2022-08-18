#include "LineScript.h"
#include "GameObject.h"
#include "TransformComponent.h"
#include "TextureComponent.h"
#include "Vector2.h"
#include "GameObject.h"
#include "E_Component.h"
#include "Rect.h"
#include "AllObject.h"
#include "E_Objtype.h"
#include "Macro.h"
#include "PuzzleDotScript.h"
#include "PuzzleBoardScript.h"

LineScript::LineScript() :
	first(nullptr), second(nullptr), isend(false)
{
}

LineScript::LineScript(GameObject* p_first, const GameObject* p_second) :
	first(p_first), second(p_second), isend(false)
{
}

LineScript::LineScript(GameObject* p_first, const GameObject* p_second, bool p_isend) :
	first(p_first), second(p_second), isend(p_isend)
{
}


LineScript::~LineScript()
{
	//버튼이 먼저 지워지면 에러

	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::PuzzleBoard);
	if (temp.first == temp.second) return;
	pair<ObjIter, ObjIter> temp2 = allObject->getallObj(E_Objtype::character);
	if (temp2.first == temp2.second) return;
	GameObject* player = temp2.first.operator*().second;
	PuzzleBoardScript* puzzle = GETSCRIPT(temp.first.operator*().second, PuzzleBoardScript);

	if(player != second)
		puzzle->AnswerDelete(first, second);

	GETSCRIPT(first, PuzzleDotScript)->minusrefCount();
	PuzzleDotScript* PuzzleDot = GETSCRIPT(second, PuzzleDotScript);
	if (PuzzleDot) {
		PuzzleDot->minusrefCount();
	}
}

void LineScript::Set(int p_first, int p_second, bool p_isend = true)
{
	isend = p_isend;
	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::puzzleDot);
	int i = 0;
	for (ObjIter iter = temp.first; iter != temp.second; ++iter, ++i) {
		GameObject* obj = iter.operator*().second;
		if (i == p_first) {
			first = obj;
			GETSCRIPT(first, PuzzleDotScript)->plusrefCount(owner);
		}
		else if (i == p_second) {
			second = obj;
			GETSCRIPT(second, PuzzleDotScript)->plusrefCount(owner);
		}
	}

	_ASSERT(first && "할당되지않음");
	_ASSERT(second && "할당되지않음");
	//GETSCRIPT(allObject->getallObj(E_Objtype::PuzzleBoard).first.operator*().second, PuzzleBoardScript)->answer();
}

void LineScript::Awake(GameObject* p_owner)
{ 
	Script::Awake(p_owner);
	if(first)
		GETSCRIPT(first, PuzzleDotScript)->plusrefCount(owner);
}

void LineScript::Start()
{
	Setting();
}

void LineScript::Update()
{
	if (!isend) {
		Setting();
	}
}

void LineScript::Setting()
{
	Vector2 begin = GETCOMPONENT(first, TransformComponent)->getpivot();
	Vector2 end = GETCOMPONENT(second, TransformComponent)->getpivot();
	
	int px = end.getx();
	int py = end.gety();
	int lx = px - begin.getx();
	int ly = py - begin.gety();
	px -= lx / 2;
	py -= ly / 2;

	float line_atan = atan2(ly, lx);
	int line_length = sqrt(lx * lx + ly * ly);

	GameObject* tempobj = new GameObject();

	TransformComponent* tempcomp = (TransformComponent*)owner->getcomponent(E_Component::TransformComponent);
	tempcomp->setpivot(Vector2(px, py - 10));
	tempcomp->setrotate(line_atan);

	TextureComponent* tempcomp2 = (TextureComponent*)owner->getcomponent(E_Component::TextureComponent);
	//tempcomp2->setrect(*tempcomp2->getrect().setweight(line_length));
	tempcomp2->setbitmap("Line", 100, 5);
	tempcomp2->setrect(Rect(line_length, 5));

	tempcomp2->Start();
}

GameObject* LineScript::getfirstptr()
{
	return first;
}

bool LineScript::getisend()
{
	return isend;
}

void LineScript::setsecond(const GameObject* p_second)
{
	second = p_second;
}

void LineScript::setisend(bool p_isend)
{
	isend = p_isend;
}
