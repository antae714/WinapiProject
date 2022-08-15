#pragma once
#include <string>

using namespace std;
enum class E_Bitmap
{
	background,
	background_2,
	background_3,
	background_4,
	background_5,
	background_6,
	background_7,
	background_Title,
	backgroundpuzzle,
	puzzlehint,
	character,
	character_idle_1,
	character_idle_2,
	character_idle_3,
	character_idle_4,
	character_idle2_1,
	character_idle2_2,
	character_idle2_3,
	character_idle2_4,
	character_move_1,
	character_move_2,
	character_move_3,
	character_move_4,
	character_move2_1,
	character_move2_2,
	character_move2_3,
	character_move2_4,
	character_run_1,
	character_run_2,
	character_run_3,
	character_run_4,
	character_run_5,
	character_run_6,
	character_run2_1,
	character_run2_2,
	character_run2_3,
	character_run2_4,
	character_run2_5,
	character_run2_6,
	character2,
	character3,
	puzzlebutton,
	puzzle_ui,
	puzzlecleartestimg,
	Starbutton,
	Starbutton_Selected,
	Starbutton_Fake,
	heart,
	Dialog,
	Line,
	Blue,
	Green,
	Red,
	logo,
	npc_assistant,
	npc,
	npc1_1,
	npc1_2,
	npc1_3,
	npc2_1,
	npc2_2,
	npc2_3,
	npc2_4,
	puzzle_1,
	puzzle_2,
	puzzle_3,
	puzzle_4,
	puzzle_5,
	puzzle_6,
	puzzle_7,
	start,
	load,
	option,
	exit,
	TitleButton,
	UI_Character,
	UI_Character_Hit,


	chaser,
	Ant_move_1,
	Ant_move_2,

	MAX
};


namespace enumBitmap {
	;
	string conversion(const E_Bitmap&);
	E_Bitmap conversion(const string&);

	string toFile(const E_Bitmap&);
}
