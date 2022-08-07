#include "MoveMap.h"
#include "LevelData.h"
#include "AllObject.h"
#include "E_Objtype.h"
#include "E_Component.h"
#include "WindowMsg.h"
#include "GameTime.h"
#include "Camera.h"
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

void MoveMap::Update()
{
	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::character);
	TransformComponent* playerpos = nullptr;
	TextureComponent* playertxt = nullptr;
	GameObject* obj = nullptr;
	for (ObjIter iter = temp.first; iter != temp.second; ++iter)
	{
		obj = iter.operator*().second;
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
	int direction = 1;

	TransformComponent* tempcom3 = dynamic_cast<TransformComponent*>(owner->getcomponent(E_Component::TransformComponent));

	if (tempcom3->getpivot().getx() < 0) {
		direction = -1;
	}

	LevelData::DeleteLevel("text");
	LevelData::LevelLode(dest);
	allObject->addPivotGroup(enumObj::conversion(dest), Vector2(1280 * direction, 0));

	Camera* camera = Camera::getInstance();
	GameTime* gameTime = GameTime::getInstance();
	obj->setisActive(false);

	for (int i = 0; i < 32; i++)
	{
		allObject->addPivotGroup(enumObj::conversion(src), Vector2(-40 * direction, 0));
		allObject->addPivotGroup(enumObj::conversion(dest), Vector2(-40 * direction, 0));
		camera->Render();
		gameTime->TimeUpdate();
	}

	LevelData::DeleteLevel(src);
	obj->setisActive(true);
	playerpos->setpivot(Vector2(x, y));
	WindowMsg* windowMsg = WindowMsg::getInstance();
	windowMsg->settingMsg(windowMsg->gethWnd(), 0, 0, 0);
}