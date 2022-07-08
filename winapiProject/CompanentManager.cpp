#include "CompanentManager.h"
#include "TextureComponent.h"
#include "TransformComponent.h"
#include "E_Component.h"

template<typename T>
Component* CompanentManager::MakeComponent()
{
	return new T();
}

CompanentManager::CompanentManager()
{
	//�� ���ڿ��� �´� ������Ʈ�� �������ݴϴ�
	FNptrarr.at((int)E_Component::TextureComponent) = &CompanentManager::MakeComponent<TextureComponent>;
	FNptrarr.at((int)E_Component::TransformComponent) = &CompanentManager::MakeComponent<TransformComponent>;
}


CompanentManager::~CompanentManager()
{
}

Component* CompanentManager::getComponent(E_Component p_componentName)
{
	if (p_componentName == E_Component::MAX) {
		_ASSERT(0 && "���������ʴ� ������Ʈ");
		return nullptr;
	}
	return FNptrarr.at((int)p_componentName)(*this);
}

Component* CompanentManager::getComponent(string p_str)
{
	return getComponent(enumCom::conversion(p_str));
}
