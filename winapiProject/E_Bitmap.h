#pragma once
#include <string>

using namespace std;
enum class E_Bitmap
{
	background,
	background_2,
	background_Title,
	backgroundpuzzle,
	puzzlehint,
	character,
	character2,
	puzzlebutton,
	puzzlecleartestimg,
	Starbutton, 
	Starbutton_Selected,
	Dialog,
	Line,
	Blue,
	Green,
	Red,
	logo,
	npc_assistant,
	npc1_1,
	npc1_2,
	npc1_3,
	start,
	load,
	option,
	exit,
	TitleButton,
	UI_Character,

	MAX
};


namespace enumBitmap {;
string conversion(const E_Bitmap&);
E_Bitmap conversion(const string&);

string toFile(const E_Bitmap&);
}
