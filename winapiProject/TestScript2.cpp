#include "TestScript2.h"
#include "WindowMsg.h"
#include "GameObject.h"
#include "E_Component.h"
#include "TransformComponent.h"
#include "TextureComponent.h"
#include "AllObject.h"
#include "LevelData.h"
#include "E_Objtype.h"
#include "Rect.h"

TestScript2::TestScript2()
{
	isClicked = false;
}

void TestScript2::play()
{
	if (isClicked)
	{
		isClicked = false;
		TextureComponent* texture = dynamic_cast<TextureComponent*>(owner->getcomponent(E_Component::TextureComponent));
		texture->setbitmap("Starbutton", texture->getxSize(), texture->getySize());
	}
	else
	{
		isClicked = true;
		TextureComponent* texture = dynamic_cast<TextureComponent*>(owner->getcomponent(E_Component::TextureComponent));
		texture->setbitmap("Starbutton_Selected", texture->getxSize(), texture->getySize());
	}

	AnswerFn();
}

void TestScript2::AnswerFn()
{
	// 활성화된 오브젝트 판정
	LevelData::DeleteLevel(E_Objtype::puzzleliner);

	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::puzzleDot);

	int count = 0;
	bool stagesw[81] = { 0, };
	Vector2 stageswpos[81];

	for (ObjIter iter = temp.first; iter != temp.second; ++iter)
	{
		GameObject* obj = iter.operator*().second;
		TestScript2* temp = dynamic_cast<TestScript2*>(obj->getscriptptr());
		if (!temp) continue;

		if (temp->isClicked == true)
		{
			stageswpos[count] = dynamic_cast<TransformComponent*>(obj->getcomponent(E_Component::TransformComponent))->getpivot();
			stagesw[count++] = true;
		}
		else
		{
			stagesw[count++] = false;
		}
	}

	// 정답 판정
	int answercheck = 0;
	if (true == stagesw[13] && true == stagesw[30])
	{
		AddLine(stageswpos[13], stageswpos[30]);
		++answercheck;
	}
	if (true == stagesw[30] && true == stagesw[38])
	{
		AddLine(stageswpos[30], stageswpos[38]);
		++answercheck;
	}
	if (true == stagesw[38] && true == stagesw[45])
	{
		AddLine(stageswpos[38], stageswpos[45]);
		++answercheck;
	}
	if (true == stagesw[13] && true == stagesw[60])
	{
		AddLine(stageswpos[13], stageswpos[60]);
		++answercheck;
	}
	if (true == stagesw[13] && true == stagesw[34])
	{
		AddLine(stageswpos[13], stageswpos[34]);
		++answercheck;
	}
	if (true == stagesw[34] && true == stagesw[60])
	{
		AddLine(stageswpos[34], stageswpos[60]);
		++answercheck;
	}
	if (true == stagesw[60] && true == stagesw[66])
	{
		AddLine(stageswpos[60], stageswpos[66]);
		++answercheck;
	}
	if (true == stagesw[66] && true == stagesw[75])
	{
		AddLine(stageswpos[66], stageswpos[75]);
		++answercheck;
	}

	if (8 == answercheck)
	{
		LevelData::LevelLode(E_Objtype::puzzlecleartest);
	}
}

void TestScript2::AddLine(Vector2 p_begin, Vector2 p_end)
{
	int px = p_end.getx();
	int py = p_end.gety();
	int lx = px - p_begin.getx();
	int ly = py - p_begin.gety();
	px -= lx / 2;
	py -= ly / 2;

	float line_atan = atan2(ly, -lx);
	int line_length = sqrt(lx * lx + ly * ly);

	GameObject* tempobj = new GameObject();

	TransformComponent* tempcomp = new TransformComponent();
	tempcomp->setpivot(Vector2(px, py));
	tempcomp->setrotate(line_atan);
	tempobj->pushcomponent(E_Component::TransformComponent, tempcomp);

	TextureComponent* tempcomp2 = new TextureComponent();
	tempcomp2->setbitmap("Line", line_length, 5);
	tempcomp2->setrect(Rect(0, line_length, 5));
	tempobj->pushcomponent(E_Component::TextureComponent, tempcomp2);

	tempobj->Start();
	AllObject::getInstance()->push(E_Objtype::puzzleliner, tempobj);	
}

void TestScript2::Activate()
{
	isClicked = true;
	dynamic_cast<TextureComponent*>(owner->getcomponent(E_Component::TextureComponent))->setbitmap("Starbutton_Selected", 50, 50);
}