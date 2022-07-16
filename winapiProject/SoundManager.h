#pragma once

#include <string>
#include "SingletonCls.h"


enum class E_Sound;
class SoundManager : public SingletonCls<SoundManager>
{
public:
	//사용할 메서드
	bool PlaySound(const E_Sound&);
};