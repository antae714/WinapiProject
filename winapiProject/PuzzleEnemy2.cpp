#include "PuzzleEnemy2.h"
#include "GameObject.h"
#include "AllObject.h"
#include "E_Objtype.h"
#include "GameTime.h"
#include "Macro.h"
#include "E_Component.h"
#include "TransformComponent.h"
#include "Vector2.h"
#include "PlayerScript.h"

PuzzleEnemy2::PuzzleEnemy2()
{
	state = E_enemyState::move;
	target = (*AllObject::getInstance()->getallObj(E_Objtype::character).first).second;
	TransformComponent* transform = GETCOMPONENT(owner, TransformComponent);
	TransformComponent* transform2 = GETCOMPONENT(target, TransformComponent);
}

void PuzzleEnemy2::Update()
{
	GameTime* gameTime = GameTime::getInstance();
	Vector2 distance = transform->getpivot() - transform2->getpivot();
	transform->move(distance.GetNormalize() * PLAYERSPEED * gameTime->getdeltaTime() * 110);
}
