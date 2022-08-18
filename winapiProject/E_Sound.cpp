#include "E_Sound.h"

string enumSound::conversion(const E_Sound& p_enum) {
	switch (p_enum)
	{
	case E_Sound::BackGround:
		return "BackGround";
	case E_Sound::Puzzle:
		return "Puzzle";
	case E_Sound::Click:
		return "Click";
	case E_Sound::Timer:
		return "Timer";
	case E_Sound::Hit:
		return "Hit";
	case E_Sound::MAX:
		return "";
	}
}
E_Sound enumSound::conversion(const string& p_str) {
	if ("BackGround" == p_str) {
		return E_Sound::BackGround;
	}
	else if ("Puzzle" == p_str) {
		return E_Sound::Puzzle;
	}
	else if ("Click" == p_str) {
		return E_Sound::Click;
	}
	else if ("Timer" == p_str) {
		return E_Sound::Timer;
	}
	else if ("Hit" == p_str) {
		return E_Sound::Hit;
	}
	return E_Sound::MAX;
}
string enumSound::toFile(const E_Sound& p_enum) {
	/*switch (p_enum) {
	case E_Sound::BackGround:
		return string("MP_Refreshing_Day.mp3");
	case E_Sound::Click:
		return string("MP_Pling.wav");
	}*/
	switch (p_enum) {
	case E_Sound::BackGround:
		return string("./Resource/Sound/Rinne - Aqua.mp3");
	case E_Sound::Puzzle:
		return string("./Resource/Sound/Rinne - Connect.mp3");
	case E_Sound::Click:
		return string("./Resource/Sound/MP_Pling.mp3");
	case E_Sound::Timer:
		return string("./Resource/Sound/timer.mp3");
	case E_Sound::Hit:
		return string("./Resource/Sound/mine_damage.mp3");
	}
	return string("./Resource/Sound/") + conversion(p_enum) + ".mp3";
}