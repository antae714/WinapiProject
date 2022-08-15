#include "PuzzleEnemy1.h"
#include "AllObject.h"
#include "E_Objtype.h"
#include "Macro.h"
#include "TransformComponent.h"
#include "E_Component.h"
#include "GameObject.h"
#include "Vector2.h"
#include "GameTime.h"
#include "PlayerScript.h"
#include "AnimationStruct.h"
#include "TextureComponent.h"
#include "PuzzleData.h"

PuzzleEnemy1::PuzzleEnemy1()
{
}

void PuzzleEnemy1::Start()
{
	GameObject* player = (*AllObject::getInstance()->getallObj(E_Objtype::character).first).second;
	transform = GETCOMPONENT(owner, TransformComponent);
	transform2 = GETCOMPONENT(player, TransformComponent);
	
	pivotset();
}

void PuzzleEnemy1::Set(int p_speed)
{
	speed = p_speed;
}

void PuzzleEnemy1::Update()
{
	if (PuzzleData::getInstance()->getisclear()) return;
	GameTime* gameTime = GameTime::getInstance();
	Vector2 distance = transform2->getpivot() - transform->getpivot();
	transform->addpivot(distance.GetNormalize() * PLAYERSPEED * gameTime->getdeltaTime() * speed);

	TextureComponent* texture = GETCOMPONENT(owner, TextureComponent);
	if (distance.getx() > 0) texture->setdirection(0);
	else if (distance.getx() < 0) texture->setdirection(1);
}

void PuzzleEnemy1::OnCollisonEnter(GameObject* other)
{
	//ÁÙ²÷±â

	AllObject* allObject = AllObject::getInstance();
	GETSCRIPT((*allObject->getallObj(E_Objtype::character).first).second,PlayerScript)->onHit();

	pivotset();
	//AllObject::getInstance()->deleteObj(owner);
}

void PuzzleEnemy1::pivotset()
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
 