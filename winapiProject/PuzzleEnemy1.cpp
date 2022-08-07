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

PuzzleEnemy1::PuzzleEnemy1()
{
}

void PuzzleEnemy1::Start()
{
	GameObject* player = (*AllObject::getInstance()->getallObj(E_Objtype::character).first).second;
	transform = GETCOMPONENT(owner, TransformComponent);
	transform2 = GETCOMPONENT(player, TransformComponent);
}

void PuzzleEnemy1::Update()
{
	GameTime* gameTime = GameTime::getInstance();
	Vector2 distance = transform2->getpivot() - transform->getpivot();
	transform->move(distance.GetNormalize() * PLAYERSPEED * gameTime->getdeltaTime() * 80);
}

void PuzzleEnemy1::OnCollisonEnter(GameObject* other)
{
	//ÁÙ²÷±â


	AllObject::getInstance()->deleteObj(owner);
}
