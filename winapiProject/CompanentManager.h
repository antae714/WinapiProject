#pragma once

#include<array>
#include<string>
#include <functional>

#include "SingletonCls.h"
#include "E_Component.h"


using namespace std;

class Component;

class CompanentManager : public SingletonCls<CompanentManager> {
private:
	array<function<Component*(CompanentManager&)>, (size_t)E_Component::MAX> FNptrarr;

public:
	CompanentManager();
	virtual ~CompanentManager();

private:
	//�ʿ� ������ ������Ʈ���� �Լ��Դϴ�
	template<typename T>
	Component* MakeComponent();

public:
	//������Ʈ�� ���鶧 ȣ���ϸ� �׿��´� ������Ʈ�� ��ȯ���ݴϴ�
	Component* getComponent(E_Component);
	Component* getComponent(string);
};