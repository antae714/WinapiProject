#include "E_Bitmap.h"

string enumBitmap::conversion(const E_Bitmap& p_enum) {
	switch (p_enum)
	{
	case E_Bitmap::background:
		return "background";
	case E_Bitmap::background_2:
		return "background_2";
	case E_Bitmap::background_3:
		return "background_3";
	case E_Bitmap::background_4:
		return "background_4";
	case E_Bitmap::background_5:
		return "background_5";
	case E_Bitmap::background_6:
		return "background_6";
	case E_Bitmap::background_7:
		return "background_7";
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
	case E_Bitmap::character3:
		return "character3";
	case E_Bitmap::puzzlebutton:
		return "puzzlebutton";
	case E_Bitmap::puzzlecleartestimg:
		return "puzzlecleartestimg";
	case E_Bitmap::Starbutton:
		return "Starbutton";
	case E_Bitmap::Starbutton_Selected:
		return "Starbutton_Selected";
	case E_Bitmap::Starbutton_Fake:
		return "Starbutton_Fake";
	case E_Bitmap::Dialog:
		return "Dialog";
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
	case E_Bitmap::npc_assistant:
		return "npc_assistant";
	case E_Bitmap::npc:
		return "npc";
	case E_Bitmap::npc1_1:
		return "npc1_1";
	case E_Bitmap::npc1_2:
		return "npc1_2";
	case E_Bitmap::npc1_3:
		return "npc1_3";
	case E_Bitmap::start:
		return "start";
	case E_Bitmap::load:
		return "load";
	case E_Bitmap::option:
		return "option";
	case E_Bitmap::exit:
		return "exit";
	case E_Bitmap::TitleButton:
		return "TitleButton";
	case E_Bitmap::UI_Character:
		return "UI_Character";
	case E_Bitmap::UI_Character_Hit:
		return "UI_Character_Hit";
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
	else if ("background_3" == p_str)
	{
		return E_Bitmap::background_3;
	}
	else if ("background_4" == p_str)
	{
		return E_Bitmap::background_4;
	}
	else if ("background_5" == p_str)
	{
		return E_Bitmap::background_5;
	}
	else if ("background_6" == p_str)
	{
		return E_Bitmap::background_6;
	}
	else if ("background_7" == p_str)
	{
		return E_Bitmap::background_7;
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
	else if ("character3" == p_str) {
		return E_Bitmap::character3;
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
	else if ("Starbutton_Fake" == p_str) {
		return E_Bitmap::Starbutton_Fake;
	}
	else if ("Dialog" == p_str) {
		return E_Bitmap::Dialog;
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
	else if ("npc_assistant" == p_str)
	{
		return E_Bitmap::npc_assistant;
	}
	else if ("npc" == p_str)
	{
		return E_Bitmap::npc;
	}
	else if ("npc1_1" == p_str)
	{
		return E_Bitmap::npc1_1;
	}
	else if ("npc1_2" == p_str)
	{
		return E_Bitmap::npc1_2;
	}
	else if ("npc1_3" == p_str)
	{
		return E_Bitmap::npc1_3;
	}
	else if ("start" == p_str)
	{
		return E_Bitmap::start;
	}
	else if ("load" == p_str)
	{
		return E_Bitmap::load;
	}
	else if ("option" == p_str)
	{
		return E_Bitmap::option;
	}
	else if ("exit" == p_str)
	{
		return E_Bitmap::exit;
	}
	else if ("TitleButton" == p_str)
	{
		return E_Bitmap::TitleButton;
	}
	else if ("UI_Character" == p_str)
	{
		return E_Bitmap::UI_Character;
	}
	else if ("UI_Character_Hit" == p_str)
	{
	return E_Bitmap::UI_Character_Hit;
	}
	return E_Bitmap::MAX;
}

string enumBitmap::toFile(const E_Bitmap& p_enum) {
	return string("./Resource/Image/") + conversion(p_enum) + ".bmp";
}