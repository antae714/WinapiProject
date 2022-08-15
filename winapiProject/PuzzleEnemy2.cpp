#include "PuzzleEnemy2.h"
#include "GameObject.h"
#include "AllObject.h"
#include "E_Objtype.h"
#include "GameTime.h"
#include "Macro.h"
#include "E_Component.h"
#include "TransformComponent.h"
#include "TextureComponent.h"
#include "Vector2.h"
#include "PuzzleDotScript.h"
#include "PlayerScript.h"
#include "Rect.h"
#include "AnimationStruct.h"
#include "TextureComponent.h"
#include "PuzzleData.h"
#include "Math.h"

PuzzleEnemy2::PuzzleEnemy2()
{
}

void PuzzleEnemy2::Update()
{
	if (PuzzleData::getInstance()->getisclear()) return;

	if (state == E_enemyState::move) movestate();
	else if (state == E_enemyState::attack) attacktate();
	else if (state == E_enemyState::search) search();
}

void PuzzleEnemy2::Set(int p_speed)
{
	speed = p_speed;
}

void PuzzleEnemy2::Init()
{
	transform = GETCOMPONENT(owner, TransformComponent);
	pivotset();
	search();
	transform2 = GETCOMPONENT(target, TransformComponent);
	attacktime = 6;
}

void PuzzleEnemy2::movestate()
{
	GameTime* gameTime = GameTime::getInstance();
	Vector2 distance = transform2->getpivot() - transform->getpivot();

	transform->addpivot(distance.GetNormalize() * PLAYERSPEED * gameTime->getdeltaTime() * speed);

	TextureComponent* Texture1 = GETCOMPONENT(target, TextureComponent);
	TextureComponent* Texture2 = GETCOMPONENT(owner, TextureComponent);

	if (distance.getx() > 0) Texture2->setdirection(0);
	else if (distance.getx() < 0) Texture2->setdirection(1);

	const Rect& rect1 = Texture1->getrectptr();
	const Rect& rect2 = Texture2->getrectptr();

	if (Math::isin(rect1, rect2))
		state = E_enemyState::attack;
}

void PuzzleEnemy2::attacktate()
{
	GameTime* gameTime = GameTime::getInstance();
	attacktime -= gameTime->getdeltaTime();
	if (attacktime <=0) {
		GETSCRIPT(target, PuzzleDotScript)->cut();
		pivotset();
		attacktime = 6;
		state = E_enemyState::search;
	}
}

void PuzzleEnemy2::pivotset()
{
	int temp = rand() % 4;
	Vector2 tempvec;
	if (temp == 0)
		tempvec = Vector2(-2318, rand() % 2318 - 1159);
	if (temp == 1)
		tempvec = Vector2(2318, rand() % 2318 - 1159);
	if (temp == 2)
		tempvec = Vector2(rand() % 2318 - 1159, -2318);
	if (temp == 3)
		tempvec = Vector2(rand() % 2318 - 1159, 2318);
	transform->setpivot(tempvec);
}

void PuzzleEnemy2::search()
{
	vector<GameObject*> dotvec;
	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::puzzleDot);
	for (ObjIter iter = temp.first; iter != temp.second; ++iter)
	{
		PuzzleDotScript* dot = GETSCRIPT((*iter).second, PuzzleDotScript);
		if (0 < dot->getrefCount()) {
			dotvec.push_back((*iter).second);
		}
	}

	if (0 == dotvec.size()) return;
	state = E_enemyState::move;
	target = dotvec.at(rand() % dotvec.size());
	transform2 = GETCOMPONENT(target, TransformComponent);
}
