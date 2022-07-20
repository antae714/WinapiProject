#include "E_Bitmap.h"

string enumBitmap::conversion(const E_Bitmap& p_enum) {
	switch (p_enum)
	{
	case E_Bitmap::background:
		return "background";
	case E_Bitmap::background_2:
		return "background_2";
	case E_Bitmap::background_Title:
		return "background_Title";
	case E_Bitmap::backgroundpuzzle:
		return "backgroundpuzzle";
	case E_Bitmap::puzzlehint:
		return "puzzlehint";
	case E_Bitmap::character:
		return "character";
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
	case E_Bitmap::Line:
		return "Line";
	case E_Bitmap::Blue:
		return "Blue";
	case E_Bitmap::Green:
		return "Green";
	case E_Bitmap::Red:
		return "Red";
	case E_Bitmap::logo:
		return "logo";
	case E_Bitmap::npc:
		return "npc";
	case E_Bitmap::npc2:
		return "npc2";
	case E_Bitmap::start:
		return "start";
	case E_Bitmap::exit:
		return "exit";
	case E_Bitmap::MAX:
		return "";
	}
}
E_Bitmap enumBitmap::conversion(const string& p_str) {
	if ("background" == p_str) {
		return E_Bitmap::background;
	}
	else if ("background_2" == p_str)
	{
		return E_Bitmap::background_2;
	}
	else if ("background_Title" == p_str)
	{
		return E_Bitmap::background_Title;
	}
	else if ("backgroundpuzzle" == p_str) {
		return E_Bitmap::backgroundpuzzle;
	}
	else if ("puzzlehint" == p_str)
	{
		return E_Bitmap::puzzlehint;
	}
	else if ("character" == p_str)
	{
		return E_Bitmap::character;
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
	else if ("Line" == p_str)
	{
		return E_Bitmap::Line;
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
	else if ("logo" == p_str)
	{
		return E_Bitmap::logo;
	}
	else if ("npc" == p_str)
	{
		return E_Bitmap::npc;
	}
	else if ("npc2" == p_str)
	{
		return E_Bitmap::npc2;
	}
	else if ("start" == p_str)
	{
		return E_Bitmap::start;
	}
	else if ("exit" == p_str)
	{
		return E_Bitmap::exit;
	}
	return E_Bitmap::MAX;
}

string enumBitmap::toFile(const E_Bitmap& p_enum) {
	return string("./Resource/Image/") + conversion(p_enum) + ".bmp";
}