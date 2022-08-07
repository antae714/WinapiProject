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
	character2,
	character3,
	puzzlebutton,
	puzzlecleartestimg,
	Starbutton, 
	Starbutton_Selected,
	Starbutton_Fake,
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
	start,
	load,
	option,
	exit,
	TitleButton,
	UI_Character,
	UI_Character_Hit,

	MAX
};


namespace enumBitmap {;
string conversion(const E_Bitmap&);
E_Bitmap conversion(const string&);

string toFile(const E_Bitmap&);
}
