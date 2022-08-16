#include "E_Bitmap.h"
#include "Macro.h"

string enumBitmap::conversion(const E_Bitmap& p_enum) {
	switch (p_enum)
	{
		ENUMTOSTRING(E_Bitmap, background)
		ENUMTOSTRING(E_Bitmap, background_2)
		ENUMTOSTRING(E_Bitmap, background_3)
		ENUMTOSTRING(E_Bitmap, background_4)
		ENUMTOSTRING(E_Bitmap, background_5)
		ENUMTOSTRING(E_Bitmap, background_6)
		ENUMTOSTRING(E_Bitmap, background_7)
		ENUMTOSTRING(E_Bitmap, background_Title)
		ENUMTOSTRING(E_Bitmap, backgroundpuzzle)
		ENUMTOSTRING(E_Bitmap, puzzlehint)
			ENUMTOSTRING(E_Bitmap, character_idle_1)
			ENUMTOSTRING(E_Bitmap, character_idle_2)
			ENUMTOSTRING(E_Bitmap, character_idle_3)
			ENUMTOSTRING(E_Bitmap, character_idle_4)
			ENUMTOSTRING(E_Bitmap, character_idle2_1)
			ENUMTOSTRING(E_Bitmap, character_idle2_2)
			ENUMTOSTRING(E_Bitmap, character_idle2_3)
			ENUMTOSTRING(E_Bitmap, character_idle2_4)
			ENUMTOSTRING(E_Bitmap, character_move_1)
			ENUMTOSTRING(E_Bitmap, character_move_2)
			ENUMTOSTRING(E_Bitmap, character_move_3)
			ENUMTOSTRING(E_Bitmap, character_move_4)
			ENUMTOSTRING(E_Bitmap, character_move2_1)
			ENUMTOSTRING(E_Bitmap, character_move2_2)
			ENUMTOSTRING(E_Bitmap, character_move2_3)
			ENUMTOSTRING(E_Bitmap, character_move2_4)
			ENUMTOSTRING(E_Bitmap, character_run_1)
			ENUMTOSTRING(E_Bitmap, character_run_2)
			ENUMTOSTRING(E_Bitmap, character_run_3)
			ENUMTOSTRING(E_Bitmap, character_run_4)
			ENUMTOSTRING(E_Bitmap, character_run_5)
			ENUMTOSTRING(E_Bitmap, character_run_6)
			ENUMTOSTRING(E_Bitmap, character_run2_1)
			ENUMTOSTRING(E_Bitmap, character_run2_2)
			ENUMTOSTRING(E_Bitmap, character_run2_3)
			ENUMTOSTRING(E_Bitmap, character_run2_4)
			ENUMTOSTRING(E_Bitmap, character_run2_5)
			ENUMTOSTRING(E_Bitmap, character_run2_6)
		ENUMTOSTRING(E_Bitmap, character2)
		ENUMTOSTRING(E_Bitmap, character3)
			ENUMTOSTRING(E_Bitmap, puzzlebutton)
			ENUMTOSTRING(E_Bitmap, puzzle_ui)
		ENUMTOSTRING(E_Bitmap, puzzlecleartestimg)
			ENUMTOSTRING(E_Bitmap, puzzleclear)
			ENUMTOSTRING(E_Bitmap, puzzlefailure)
		ENUMTOSTRING(E_Bitmap, Starbutton)
		ENUMTOSTRING(E_Bitmap, Starbutton_Selected)
		ENUMTOSTRING(E_Bitmap, Starbutton_Fake)
			ENUMTOSTRING(E_Bitmap, heart)
		ENUMTOSTRING(E_Bitmap, Dialog)
		ENUMTOSTRING(E_Bitmap, Line)
		ENUMTOSTRING(E_Bitmap, Blue)
		ENUMTOSTRING(E_Bitmap, Green)
		ENUMTOSTRING(E_Bitmap, Red)
		ENUMTOSTRING(E_Bitmap, logo)
		ENUMTOSTRING(E_Bitmap, npc_assistant)
		ENUMTOSTRING(E_Bitmap, npc)
		ENUMTOSTRING(E_Bitmap, npc1_1)
		ENUMTOSTRING(E_Bitmap, npc1_2)
		ENUMTOSTRING(E_Bitmap, npc1_3)
			ENUMTOSTRING(E_Bitmap, npc2_1)
			ENUMTOSTRING(E_Bitmap, npc2_2)
			ENUMTOSTRING(E_Bitmap, npc2_3)
			ENUMTOSTRING(E_Bitmap, npc2_4)
			ENUMTOSTRING(E_Bitmap, puzzle_1)
			ENUMTOSTRING(E_Bitmap, puzzle_2)
			ENUMTOSTRING(E_Bitmap, puzzle_3)
			ENUMTOSTRING(E_Bitmap, puzzle_4)
			ENUMTOSTRING(E_Bitmap, puzzle_5)
			ENUMTOSTRING(E_Bitmap, puzzle_6)
			ENUMTOSTRING(E_Bitmap, puzzle_7)
		ENUMTOSTRING(E_Bitmap, start)
		ENUMTOSTRING(E_Bitmap, load)
		ENUMTOSTRING(E_Bitmap, option)
		ENUMTOSTRING(E_Bitmap, exit)
		ENUMTOSTRING(E_Bitmap, TitleButton)
		ENUMTOSTRING(E_Bitmap, UI_Character)
		ENUMTOSTRING(E_Bitmap, UI_Character_Hit)
			ENUMTOSTRING(E_Bitmap, chaser)
			ENUMTOSTRING(E_Bitmap, Ant_move_1)
			ENUMTOSTRING(E_Bitmap, Ant_move_2)
			ENUMTOSTRING(E_Bitmap, Tutorial0)
			ENUMTOSTRING(E_Bitmap, Tutorial1)
			ENUMTOSTRING(E_Bitmap, Tutorial2)
			ENUMTOSTRING(E_Bitmap, Tutorial3)
			ENUMTOSTRING(E_Bitmap, Tutorial4)
			ENUMTOSTRING(E_Bitmap, elevator)
	}
}
E_Bitmap enumBitmap::conversion(const string& p_str) {
	STRINGTOENUM(E_Bitmap, background)
	STRINGTOENUM(E_Bitmap, background_2)
	STRINGTOENUM(E_Bitmap, background_3)
	STRINGTOENUM(E_Bitmap, background_4)
	STRINGTOENUM(E_Bitmap, background_5)
	STRINGTOENUM(E_Bitmap, background_6)
	STRINGTOENUM(E_Bitmap, background_7)
	STRINGTOENUM(E_Bitmap, background_Title)
	STRINGTOENUM(E_Bitmap, backgroundpuzzle)
	STRINGTOENUM(E_Bitmap, puzzlehint)
	STRINGTOENUM(E_Bitmap, character)
		STRINGTOENUM(E_Bitmap, character_idle_1)
		STRINGTOENUM(E_Bitmap, character_idle_2)
		STRINGTOENUM(E_Bitmap, character_idle_3)
		STRINGTOENUM(E_Bitmap, character_idle_4)
		STRINGTOENUM(E_Bitmap, character_idle2_1)
		STRINGTOENUM(E_Bitmap, character_idle2_2)
		STRINGTOENUM(E_Bitmap, character_idle2_3)
		STRINGTOENUM(E_Bitmap, character_idle2_4)
		STRINGTOENUM(E_Bitmap, character_move_1)
		STRINGTOENUM(E_Bitmap, character_move_2)
		STRINGTOENUM(E_Bitmap, character_move_3	)
		STRINGTOENUM(E_Bitmap, character_move_4)
		STRINGTOENUM(E_Bitmap, character_move2_1)
		STRINGTOENUM(E_Bitmap, character_move2_2)
		STRINGTOENUM(E_Bitmap, character_move2_3)
		STRINGTOENUM(E_Bitmap, character_move2_4)
		STRINGTOENUM(E_Bitmap, character_run_1)
		STRINGTOENUM(E_Bitmap, character_run_2)
		STRINGTOENUM(E_Bitmap, character_run_3)
		STRINGTOENUM(E_Bitmap, character_run_4)
		STRINGTOENUM(E_Bitmap, character_run_5)
		STRINGTOENUM(E_Bitmap, character_run_6)
		STRINGTOENUM(E_Bitmap, character_run2_1)
		STRINGTOENUM(E_Bitmap, character_run2_2)
		STRINGTOENUM(E_Bitmap, character_run2_3)
		STRINGTOENUM(E_Bitmap, character_run2_4)
		STRINGTOENUM(E_Bitmap, character_run2_5)
		STRINGTOENUM(E_Bitmap, character_run2_6)
	STRINGTOENUM(E_Bitmap, character2)
	STRINGTOENUM(E_Bitmap, character3)
	STRINGTOENUM(E_Bitmap, puzzlebutton)
		STRINGTOENUM(E_Bitmap, puzzle_ui)
	STRINGTOENUM(E_Bitmap, puzzlecleartestimg)
		STRINGTOENUM(E_Bitmap, puzzleclear)
		STRINGTOENUM(E_Bitmap, puzzlefailure)
	STRINGTOENUM(E_Bitmap, Starbutton)
	STRINGTOENUM(E_Bitmap, Starbutton_Selected)
		STRINGTOENUM(E_Bitmap, Starbutton_Fake)
		STRINGTOENUM(E_Bitmap, heart)
	STRINGTOENUM(E_Bitmap, Dialog)
	STRINGTOENUM(E_Bitmap, Line)
	STRINGTOENUM(E_Bitmap, Blue)
	STRINGTOENUM(E_Bitmap, Green)
	STRINGTOENUM(E_Bitmap, Red)
	STRINGTOENUM(E_Bitmap, logo)
	STRINGTOENUM(E_Bitmap, npc_assistant)
	STRINGTOENUM(E_Bitmap, npc)
	STRINGTOENUM(E_Bitmap, npc1_1)
	STRINGTOENUM(E_Bitmap, npc1_2)
	STRINGTOENUM(E_Bitmap, npc1_3)
		STRINGTOENUM(E_Bitmap, npc2_1)
		STRINGTOENUM(E_Bitmap, npc2_2)
		STRINGTOENUM(E_Bitmap, npc2_3)
		STRINGTOENUM(E_Bitmap, npc2_4)
		STRINGTOENUM(E_Bitmap, puzzle_1)
		STRINGTOENUM(E_Bitmap, puzzle_2)
		STRINGTOENUM(E_Bitmap, puzzle_3)
		STRINGTOENUM(E_Bitmap, puzzle_4)
		STRINGTOENUM(E_Bitmap, puzzle_5)
		STRINGTOENUM(E_Bitmap, puzzle_6)
		STRINGTOENUM(E_Bitmap, puzzle_7)
	STRINGTOENUM(E_Bitmap, start)
	STRINGTOENUM(E_Bitmap, load)
	STRINGTOENUM(E_Bitmap, option)
	STRINGTOENUM(E_Bitmap, exit)
	STRINGTOENUM(E_Bitmap, TitleButton)
	STRINGTOENUM(E_Bitmap, UI_Character)
	STRINGTOENUM(E_Bitmap, UI_Character_Hit)
		STRINGTOENUM(E_Bitmap, chaser)
		STRINGTOENUM(E_Bitmap, Ant_move_1)
		STRINGTOENUM(E_Bitmap, Ant_move_2)
		STRINGTOENUM(E_Bitmap, Tutorial0)
		STRINGTOENUM(E_Bitmap, Tutorial1)
		STRINGTOENUM(E_Bitmap, Tutorial2)
		STRINGTOENUM(E_Bitmap, Tutorial3)
		STRINGTOENUM(E_Bitmap, Tutorial4)
		STRINGTOENUM(E_Bitmap, elevator)
		return E_Bitmap::MAX;
	/*if ("background" == p_str) {
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
	return E_Bitmap::MAX;*/
}

string enumBitmap::toFile(const E_Bitmap& p_enum) {
	return string("./Resource/Image/") + conversion(p_enum) + ".bmp";
}