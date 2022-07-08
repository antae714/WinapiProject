#pragma once

#include <memory>

using namespace std;

//싱글톤을 상속받아서 싱글톤패턴을 적용시켜줍니다
template <typename T>
class SingletonCls
{
protected:
	static unique_ptr<T> instance;
public:
	static T* getInstance();
	static void deleteInstance();
};

template <typename T>
unique_ptr<T> SingletonCls<T>::instance = nullptr;

template<typename T>
T* SingletonCls<T>::getInstance()
{
	if (!instance.get()) {
		instance = make_unique<T>();
	}
	return instance.get();
}

template<typename T>
void SingletonCls<T>::deleteInstance()
{
	instance.reset();
}
