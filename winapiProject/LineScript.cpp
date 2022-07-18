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

LineScript::LineScript(GameObject* p_first, const GameObject* p_second) : 
	first(p_first), second(p_second), isend(false)
{
}

void LineScript::Awake(GameObject* p_owner)
{ 
	Script::Awake(p_owner);
	Setting();
}

void LineScript::play()
{
	Setting();
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

	float line_atan = atan2(ly, -lx);
	int line_length = sqrt(lx * lx + ly * ly);

	GameObject* tempobj = new GameObject();

	TransformComponent* tempcomp = (TransformComponent*)owner->getcomponent(E_Component::TransformComponent);
	tempcomp->setpivot(Vector2(px, py));
	tempcomp->setrotate(line_atan);

	TextureComponent* tempcomp2 = (TextureComponent*)owner->getcomponent(E_Component::TextureComponent);
	tempcomp2->setbitmap("Line", 100, 5);
	tempcomp2->setrect(Rect(0, line_length, 5));

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
