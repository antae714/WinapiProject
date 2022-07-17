#include "E_Sound.h"

string enumSound::conversion(const E_Sound& p_enum) {
	switch (p_enum)
	{
	case E_Sound::BackGround:
		return "BackGround";
	case E_Sound::Click:
		return "Click";
	case E_Sound::MAX:
		return "";
	}
}
E_Sound enumSound::conversion(const string& p_str) {
	if ("BackGround" == p_str) {
		return E_Sound::BackGround;
	}
	else if ("Click" == p_str) {
		return E_Sound::Click;
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
		return string("./Resource/Sound/MP_Refreshing_Day.mp3");
	case E_Sound::Click:
		return string("./Resource/Sound/MP_Pling.mp3");
	}
	return string("./Resource/Sound/") + conversion(p_enum) + ".mp3";
}