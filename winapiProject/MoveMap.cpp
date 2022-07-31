#include "MoveMap.h"
#include "LevelData.h"
#include "AllObject.h"
#include "E_Objtype.h"
#include "E_Component.h"
#include "GameObject.h"
#include "TransformComponent.h"
#include "TextureComponent.h"
#include "CollisonCompoenet.h"
#include "Vector2.h"
#include "SoundManager.h"
#include "Math.h"

MoveMap::MoveMap()
{
}

void MoveMap::Set(string p_src, string p_dest, int p_x, int p_y)
{
	m_src = p_src;
	m_dest = p_dest;
	m_pos_x = p_x;
	m_pos_y = p_y;
}

void MoveMap::play()
{
	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::character);
	TransformComponent* playerpos = nullptr;
	TextureComponent* playertxt = nullptr;
	for (ObjIter iter = temp.first; iter != temp.second; ++iter)
	{
		GameObject* obj = iter.operator*().second;
		playerpos = dynamic_cast<TransformComponent*>(obj->getcomponent(E_Component::TransformComponent));
		playertxt = dynamic_cast<TextureComponent*>(obj->getcomponent(E_Component::TextureComponent));
		break;
	}

	TextureComponent* tempcom2 = dynamic_cast<TextureComponent*>(owner->getcomponent(E_Component::TextureComponent));

	if (!Math::isin(tempcom2->getrectptr(), playertxt->getrectptr())) {
		return;
	}

	string src = m_src, dest = m_dest;
	int x = m_pos_x, y = m_pos_y;

	LevelData::DeleteLevel(src);
	LevelData::LevelLode(dest);

	playerpos->setpivot(Vector2(x, y));
}