#include "SoundManager.h"

SoundManager::SoundManager()
{
    channel = nullptr;
    //extradriverdata = nullptr;
    FMOD::System_Create(&system);
    system->init((int)E_Sound::MAX, FMOD_INIT_NORMAL, nullptr);
    for (int i = 0; i < (int)E_Sound::MAX; ++i) {
        system->createSound(enumSound::toFile((E_Sound)i).c_str(), FMOD_DEFAULT, 0, &soundarr.at(i));
    }
    soundarr.at(0)->setMode(FMOD_LOOP_NORMAL);
}

SoundManager::~SoundManager() {
    for (int i = 0; i < (int)E_Sound::MAX; ++i) {
        soundarr.at(i)->release();
    }
    system->release();
    system->close();
}

bool SoundManager::PlaySound_(const E_Sound& p_sound)
{
    FMOD_RESULT result = system->playSound(soundarr.at((int)p_sound), 0, false, &channel);
    return result == FMOD_OK;
}

