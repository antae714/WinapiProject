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
#include "Math.h"

PuzzleEnemy2::PuzzleEnemy2()
{
}

void PuzzleEnemy2::Update()
{
	 if (state == E_enemyState::move) movestate();
	 else if (state == E_enemyState::attack) attacktate();
}

void PuzzleEnemy2::Init()
{
	state = E_enemyState::move;
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

	target = dotvec.at(rand() % dotvec.size());


	transform = GETCOMPONENT(owner, TransformComponent);
	int tempval = rand() % 4;
	Vector2 tempvec;
	if (tempval == 0)
		tempvec = Vector2(-2318, rand() % 2318 - 1159);
	if (tempval == 1)
		tempvec = Vector2(2318, rand() % 2318 - 1159);
	if (tempval == 2)
		tempvec = Vector2(rand() % 2318 - 1159, -2318);
	if (tempval == 3)
		tempvec = Vector2(rand() % 2318 - 1159, 2318);
	transform->setpivot(tempvec);
	transform2 = GETCOMPONENT(target, TransformComponent);

	attacktime = 5;
}

void PuzzleEnemy2::movestate()
{
	GameTime* gameTime = GameTime::getInstance();
	Vector2 distance = transform2->getpivot() - transform->getpivot();
	transform->addpivot(distance.GetNormalize() * PLAYERSPEED * gameTime->getdeltaTime() * 110);

	TextureComponent* Texture1 = GETCOMPONENT(target, TextureComponent);
	TextureComponent* Texture2 = GETCOMPONENT(owner, TextureComponent);

	const Rect& rect1 = Texture1->getrectptr();
	const Rect& rect2 = Texture2->getrectptr();
	if (Math::isin(rect1, rect2))
	{
		state = E_enemyState::attack;
	}
}

void PuzzleEnemy2::attacktate()
{
	GameTime* gameTime = GameTime::getInstance();
	attacktime -= gameTime->getdeltaTime();
	if (attacktime <=0) {
		GETSCRIPT(target, PuzzleDotScript)->cut();

		Init();
	}
}
