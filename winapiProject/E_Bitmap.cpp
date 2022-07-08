#include "E_Bitmap.h"

string enumBitmap::conversion(const E_Bitmap& p_enum) {
	switch (p_enum)
	{
	case E_Bitmap::background:
		return "background";
	case E_Bitmap::backgroundpuzzle:
		return "backgroundpuzzle";
	case E_Bitmap::character2:
		return "character2";
	case E_Bitmap::puzzlebutton:
		return "puzzlebutton";
	case E_Bitmap::puzzlecleartestimg:
		return "puzzlecleartestimg";
	case E_Bitmap::Starbutton:
		return "Starbutton";
	case E_Bitmap::Starbutton_Selected:
		return "Starbutton_Selected";
	case E_Bitmap::Blue:
		return "Blue";
	case E_Bitmap::Green:
		return "Green";
	case E_Bitmap::Red:
		return "Red";
	case E_Bitmap::MAX:
		return "";
	}
}
E_Bitmap enumBitmap::conversion(const string& p_str) {
	if ("background" == p_str) {
		return E_Bitmap::background;
	}
	else if ("backgroundpuzzle" == p_str) {
		return E_Bitmap::backgroundpuzzle;
	}
	else if ("character2" == p_str) {
		return E_Bitmap::character2;
	}
	else if ("puzzlebutton" == p_str) {
		return E_Bitmap::puzzlebutton;
	}
	else if ("puzzlecleartestimg" == p_str) {
		return E_Bitmap::puzzlecleartestimg;
	}
	else if ("Starbutton" == p_str) {
		return E_Bitmap::Starbutton;
	}
	else if ("Starbutton_Selected" == p_str) {
		return E_Bitmap::Starbutton_Selected;
	}
	else if ("Blue" == p_str) {
		return E_Bitmap::Blue;
	}
	else if ("Red" == p_str) {
		return E_Bitmap::Red;
	}
	else if ("Green" == p_str) {
		return E_Bitmap::Green;
	}
	return E_Bitmap::MAX;
}

string enumBitmap::toFile(const E_Bitmap& p_enum) {
	return string("./Resource/Image/") + conversion(p_enum) + ".bmp";
}