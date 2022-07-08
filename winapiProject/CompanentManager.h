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
	//맵에 저장할 컴포넌트생성 함수입니다
	template<typename T>
	Component* MakeComponent();

public:
	//오브젝트를 만들때 호출하면 그에맞는 컴포넌트를 반환해줍니다
	Component* getComponent(E_Component);
	Component* getComponent(string);
};