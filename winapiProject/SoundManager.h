#pragma once

#include <string>
#include "SingletonCls.h"


enum class E_Sound;
class SoundManager : public SingletonCls<SoundManager>
{
public:
	//����� �޼���
	bool PlaySound(const E_Sound&);
};