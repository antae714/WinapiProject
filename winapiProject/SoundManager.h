#pragma once

#include <string>
#include <array>
#include "SingletonCls.h"
#include "fmod.hpp"
#include "E_Sound.h"

using namespace std;

class SoundManager : public SingletonCls<SoundManager>
{
private:
    FMOD::System* system;
    array<FMOD::Sound*, (size_t)E_Sound::MAX> soundarr;
    FMOD::Channel* channel;
    FMOD::Channel* channel2;

public:
    SoundManager();
    virtual ~SoundManager();

public:
	//사용할 메서드
	bool PlaySound_(E_Sound);
    void changeBackground(E_Sound);

    void setBackVolume(float);
    void setEffectVolume(float);
};