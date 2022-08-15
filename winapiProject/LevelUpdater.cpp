#include "LevelUpdater.h"
#include "LevelData.h"
#include "AllObject.h"
#include "E_Objtype.h"
#include "E_Component.h"
#include "WindowMsg.h"
#include "GameObject.h"
#include "GameData.h"
#include "PlayerScript.h"
#include "UITransformComponent.h"
#include "CollisonCompoenet.h"
#include "TextureComponent.h"
#include "TextComponent.h"
#include "TextScript.h"
#include "PuzzleEntry.h"
#include "PuzzleExit.h"
#include "Timer.h"
#include "Rect.h"
#include "Math.h"
#include "Macro.h"

LevelUpdater::LevelUpdater()
{
}

void LevelUpdater::Update()
{
	switch (level) {
	case 0: level1_1(); break;
	case 1: level1_2(); break;
	case 2: level1_3(); break;
	case 3: level1_4(); break;
	case 4: level1_5(); break;
	case 5: level1_6(); break;
	case 6: level2_1(); break;
	case 7: level2_2(); break;
	case 8: level2_3(); break;
	case 9: level2_4(); break;
	case 10: level2_5(); break;
	case 11: level2_6(); break;
	}
}
void LevelUpdater::Set(int p_level)
{
	level = p_level;
}

void LevelUpdater::level1_1()
{
}

void LevelUpdater::level1_2()
{
	GameData* gamedata = GameData::getInstance();
	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::level1_2);
	if (gamedata->getvarias("level1_2_npc") == 1) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				tempscr->Set("dialog1_1");
				break;
			}
		}
	}
}

void LevelUpdater::level1_3()
{
	GameData* gamedata = GameData::getInstance();
	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::level1_3);
	if (gamedata->getvarias("level1_3_npc") == 1) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				tempscr->Set("dialog2_1", "level1_3_npc", 2);
				break;
			}
		}
	}
	if (gamedata->getvarias("level1_3_npc") == 2) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				tempscr->Set("dialog2_2", "level1_3_npc", 3);
				break;
			}
		}
	}
	if (gamedata->getvarias("level1_3_npc") == 3) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				delete tempscr;

				PuzzleEntry* tempscr2 = new PuzzleEntry();
				tempscr2->Set("puzzle_1", "level1_3_npc");
				obj->setscript(tempscr2);
				break;
			}
		}
	}
	if (gamedata->getvarias("level1_3_npc") == 4) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			PuzzleEntry* tempscr = dynamic_cast<PuzzleEntry*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				delete tempscr;

				TextScript* tempscr2 = new TextScript();
				tempscr2->Set("dialog2_3", "level1_3_npc", 5);
				obj->setscript(tempscr2);
				break;
			}
		}
	}
	if (gamedata->getvarias("level1_3_npc") == 5) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				tempscr->Set("dialog2_4");
				break;
			}
		}
	}
}

void LevelUpdater::level1_4()
{
	GameData* gamedata = GameData::getInstance();
	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::level1_4);
	if (gamedata->getvarias("level1_4_npc") == 1) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				tempscr->Set("dialog3_1", "level1_4_npc", 2);
				break;
			}
		}
	}
	if (gamedata->getvarias("level1_4_npc") == 2) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				delete tempscr;

				PuzzleEntry* tempscr2 = new PuzzleEntry();
				tempscr2->Set("puzzle_2", "level1_4_npc");
				obj->setscript(tempscr2);
				break;
			}
		}
	}
	if (gamedata->getvarias("level1_4_npc") == 3) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			PuzzleEntry* tempscr = dynamic_cast<PuzzleEntry*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				delete tempscr;

				TextScript* tempscr2 = new TextScript();
				tempscr2->Set("dialog3_2", "level1_4_npc", 4);
				obj->setscript(tempscr2);
				break;
			}
		}
	}
	if (gamedata->getvarias("level1_4_npc") == 4) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				tempscr->Set("dialog3_3");
				break;
			}
		}
	}
}

void LevelUpdater::level1_5()
{
	GameData* gamedata = GameData::getInstance();
	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::level1_5);
	if (gamedata->getvarias("level1_5_npc") == 1) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				tempscr->Set("dialog4_1", "level1_5_npc", 2);
				break;
			}
		}
	}
	if (gamedata->getvarias("level1_5_npc") == 2) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				delete tempscr;

				PuzzleEntry* tempscr2 = new PuzzleEntry();
				tempscr2->Set("puzzle_3", "level1_5_npc");
				obj->setscript(tempscr2);
				break;
			}
		}
	}
	if (gamedata->getvarias("level1_5_npc") == 3) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			PuzzleEntry* tempscr = dynamic_cast<PuzzleEntry*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				delete tempscr;

				TextScript* tempscr2 = new TextScript();
				tempscr2->Set("dialog4_2", "level1_5_npc", 4);
				obj->setscript(tempscr2);
				break;
			}
		}
	}
	if (gamedata->getvarias("level1_5_npc") == 4) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				tempscr->Set("dialog4_3");
				break;
			}
		}
	}
	if (gamedata->getvarias("level1_3_npc") >= 4 &&
		gamedata->getvarias("level1_4_npc") >= 3 &&
		gamedata->getvarias("level1_5_npc") >= 3) {
		int sw = 0;
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				if (sw == 1) {
					tempscr->Set("dialog4_4", "level1_5_wall", 1);
					break;
				}
				else {
					++sw;
				}
			}
		}
	}
	if (gamedata->getvarias("level1_5_wall") == 1) {
		int sw = 0;
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			CollisonCompoenet* tempcom = dynamic_cast<CollisonCompoenet*>(obj->getcomponent(E_Component::CollisonCompoenet));
			if (tempcom != nullptr) {
				obj->setisActive(false);
			}

			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				if (sw == 1) {
					tempscr->Set("dialog4_5", "level1_5_npc", 5);
					break;
				}
				else {
					++sw;
				}
			}
		}
	}
}

void LevelUpdater::level1_6()
{
}

void LevelUpdater::level2_1()
{
	GameData* gamedata = GameData::getInstance();
	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::level2_1);
	if (gamedata->getvarias("level2_1_npc") == 1) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				tempscr->Set("dialog8_1", "level2_1_npc", 2);
				break;
			}
		}
	}
	if (gamedata->getvarias("level2_1_npc") == 2) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				delete tempscr;

				PuzzleEntry* tempscr2 = new PuzzleEntry();
				tempscr2->Set("puzzle_5", "level2_1_npc");
				obj->setscript(tempscr2);
				break;
			}
		}
	}
	if (gamedata->getvarias("level2_1_npc") == 3) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			PuzzleEntry* tempscr = dynamic_cast<PuzzleEntry*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				delete tempscr;

				TextScript* tempscr2 = new TextScript();
				tempscr2->Set("dialog8_2", "level2_1_npc", 4);
				obj->setscript(tempscr2);
				break;
			}
		}
	}
	if (gamedata->getvarias("level2_1_npc") == 4) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				tempscr->Set("dialog8_3");
				break;
			}
		}
	}
}

void LevelUpdater::level2_2()
{
	GameData* gamedata = GameData::getInstance();
	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::level2_2);
	if (gamedata->getvarias("level2_2_npc") == 1) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				tempscr->Set("dialog7_1", "level2_2_npc", 2);
				break;
			}
		}
	}
	if (gamedata->getvarias("level2_2_npc") == 2) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				delete tempscr;

				PuzzleEntry* tempscr2 = new PuzzleEntry();
				tempscr2->Set("puzzle_4", "level2_2_npc");
				obj->setscript(tempscr2);
				break;
			}
		}
	}
	if (gamedata->getvarias("level2_2_npc") == 3) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			PuzzleEntry* tempscr = dynamic_cast<PuzzleEntry*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				delete tempscr;

				TextScript* tempscr2 = new TextScript();
				tempscr2->Set("dialog7_2", "level2_2_npc", 4);
				obj->setscript(tempscr2);
				break;
			}
		}
	}
	if (gamedata->getvarias("level2_2_npc") == 4) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				tempscr->Set("dialog7_3");
				break;
			}
		}
	}
}

void LevelUpdater::level2_3()
{
	GameData* gamedata = GameData::getInstance();
	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::level2_3);
	if (gamedata->getvarias("level2_1_npc") >= 3 &&
		gamedata->getvarias("level2_2_npc") >= 3) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				tempscr->Set("dialog6_1");
				break;
			}
		}
	}
}

void LevelUpdater::level2_4()
{
	GameData* gamedata = GameData::getInstance();
	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::level2_4);
	if (gamedata->getvarias("level2_1_npc") < 3 &&
		gamedata->getvarias("level2_2_npc") < 3) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				obj->setisActive(false);
				break;
			}
		}
	}
	if (gamedata->getvarias("level2_4_npc") < 3) {
		int sw = 0;
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				if (sw == 1) {
					obj->setisActive(false);
					break;
				}
				else {
					++sw;
				}
			}
		}
	}
	else {
		int sw = 0;
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;

			CollisonCompoenet* tempcom = dynamic_cast<CollisonCompoenet*>(obj->getcomponent(E_Component::CollisonCompoenet));
			if (tempcom != nullptr) {
				obj->setisActive(false);
			}

			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				if (sw == 1) {
					obj->setisActive(true);
					break;
				}
				else {
					++sw;
				}
			}
		}
	}
	if (gamedata->getvarias("level2_4_npc") == 1) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				tempscr->Set("dialog9_1", "level2_4_npc", 2);
				break;
			}
		}
	}
	if (gamedata->getvarias("level2_4_npc") == 2) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				delete tempscr;

				PuzzleEntry* tempscr2 = new PuzzleEntry();
				tempscr2->Set("puzzle_6", "level2_4_npc");
				obj->setscript(tempscr2);
				break;
			}
		}
	}
	if (gamedata->getvarias("level2_4_npc") == 3) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			PuzzleEntry* tempscr = dynamic_cast<PuzzleEntry*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				delete tempscr;

				TextScript* tempscr2 = new TextScript();
				tempscr2->Set("dialog9_2", "level2_4_npc", 4);
				obj->setscript(tempscr2);
				break;
			}
		}
	}
	if (gamedata->getvarias("level2_4_npc") == 4) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				tempscr->Set("dialog9_3");
				break;
			}
		}
	}
}

void LevelUpdater::level2_5()
{
	GameData* gamedata = GameData::getInstance();
	AllObject* allObject = AllObject::getInstance();
	pair<ObjIter, ObjIter> temp = allObject->getallObj(E_Objtype::level2_5);
	if (gamedata->getvarias("level2_5_npc") == 1) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				delete tempscr;

				PuzzleEntry* tempscr2 = new PuzzleEntry();
				tempscr2->Set("puzzle_7", "level2_5_npc");
				obj->setscript(tempscr2);
				break;
			}
		}
	}
	if (gamedata->getvarias("level2_5_npc") == 2) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;

			CollisonCompoenet* tempcom = dynamic_cast<CollisonCompoenet*>(obj->getcomponent(E_Component::CollisonCompoenet));
			if (tempcom != nullptr) {
				obj->setisActive(false);
			}

			PuzzleEntry* tempscr = dynamic_cast<PuzzleEntry*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				delete tempscr;

				TextScript* tempscr2 = new TextScript();
				tempscr2->Set("dialog10_1");
				obj->setscript(tempscr2);
				break;
			}
		}
	}
}

void LevelUpdater::level2_6()
{
	GameData* gamedata = GameData::getInstance();
	if (gamedata->getvarias("ending") == 1) {
		LevelData::DeleteLevel("level2_6");
		LevelData::DeleteLevel("character");
		LevelData::DeleteLevel("background");
		LevelData::LevelLode("titlescreen");
		gamedata->resetvarias();
	}

}