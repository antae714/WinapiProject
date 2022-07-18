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
    //void* extradriverdata;

public:
    SoundManager();
    virtual ~SoundManager();

public:
	//����� �޼���
	bool PlaySound_(const E_Sound&);
};