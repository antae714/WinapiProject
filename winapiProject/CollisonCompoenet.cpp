#include "CollisonCompoenet.h"
#include "Rect.h"
#include "Script.h"
#include "GameObject.h"
#include "TransformComponent.h"
#include "E_Component.h"
#include "Math.h"
#include "Vector2.h"
#include "Macro.h"
#include "TextureComponent.h"
#include "CollisonFunction.h"
#include "AllObject.h"

CollisonCompoenet::CollisonCompoenet() : rect(new Rect()), istriger(false)
{
}

CollisonCompoenet::CollisonCompoenet(const Rect& p_rect) : istriger(false)
{
	rect = new Rect();
	*rect = p_rect;
}

CollisonCompoenet::~CollisonCompoenet()
{
	delete rect;
}

void CollisonCompoenet::Start()
{
	if (Component* tempcomponenet = owner->getcomponent(E_Component::TransformComponent)) {
		TransformComponent* temp = dynamic_cast<TransformComponent*>(tempcomponenet);
		rect->setpivotptr(temp->getpivotptr());
		rect->setrotateptr(temp->getrotateptr());
	}
}

GameObject* CollisonCompoenet::CollisonLogic()
{
	AllObject* allObject = AllObject::getInstance();
	vector<ObjIter> itervec;
	for (ObjIter iter = allObject->allObjbegin(); iter != allObject->allObjend(); ++iter)
	{
		GameObject* obj = iter.operator*().second;
		if (GETCOMPONENT(obj, CollisonCompoenet)) {
			if (obj == owner) continue;
			itervec.push_back(iter);
		}
	}
	if (itervec.empty()) return nullptr;
	for (int i = 0; i < itervec.size(); ++i)
	{
		GameObject* obj = itervec.at(i).operator*().second;
		CollisonCompoenet* other = GETCOMPONENT(obj, CollisonCompoenet);
		if (Math::isin(*this->rect, *other->rect)) {
			setistriger(other, true);
			return obj;
		}
		else {
			setistriger(other, false);
		}
	}
	return nullptr;
}

void CollisonCompoenet::OnCollison(CollisonCompoenet* other)
{
	GameObject* otherobj = other->owner;
	CollisonFunction* coll = dynamic_cast<CollisonFunction*>(other->owner->getscriptptr());
	if (coll) {
		coll->OnCollison(otherobj);
	}
}

void CollisonCompoenet::OnCollisonEnter(CollisonCompoenet* other)
{
	GameObject* otherobj = other->owner;
	CollisonFunction* coll = dynamic_cast<CollisonFunction*>(other->owner->getscriptptr());
	if (coll) {
		coll->OnCollisonEnter(otherobj);
	}
}

void CollisonCompoenet::OnCollisonExit(CollisonCompoenet* other)
{
	GameObject* otherobj = other->owner;
	CollisonFunction* coll = dynamic_cast<CollisonFunction*>(other->owner->getscriptptr());
	if (coll) {
		coll->OnCollisonExit(otherobj);
	}
}

const Rect& CollisonCompoenet::getrect()
{
	return *rect;
}

void CollisonCompoenet::setistriger(CollisonCompoenet* other,bool p_istriger)
{
	if(istriger == p_istriger) return;
	istriger = p_istriger;
	if (istriger) {
		this->OnCollisonEnter(other);
		other->OnCollisonEnter(this);
	}
	else {
		this->OnCollisonExit(other);
		other->OnCollisonExit(this);
	}
}
