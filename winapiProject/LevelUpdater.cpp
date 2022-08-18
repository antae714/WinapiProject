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
#include "Tutorial.h"
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
	(this->*FNptr)();
}
void LevelUpdater::Set(int p_level)
{
	//level = p_level;
	switch (p_level) {
	case 0: FNptr = &LevelUpdater::level1_1; break;
	case 1: FNptr = &LevelUpdater::level1_2; break;
	case 2: FNptr = &LevelUpdater::level1_3; break;
	case 3: FNptr = &LevelUpdater::level1_4; break;
	case 4: FNptr = &LevelUpdater::level1_5; break;
	case 5: FNptr = &LevelUpdater::level1_6; break;
	case 6: FNptr = &LevelUpdater::level2_1; break;
	case 7: FNptr = &LevelUpdater::level2_2; break;
	case 8: FNptr = &LevelUpdater::level2_3; break;
	case 9: FNptr = &LevelUpdater::level2_4; break;
	case 10: FNptr = &LevelUpdater::level2_5; break;
	case 11: FNptr = &LevelUpdater::level2_6; break;
	}
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

				obj->deletescript();

				Tutorial* tempscr2 = new Tutorial();
				obj->setscript(tempscr2);
				break;
			}
		}
	}
	if (gamedata->getvarias("level1_3_npc") == 3) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			Tutorial* tempscr2 = dynamic_cast<Tutorial*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				tempscr->Set("dialog2_2", "level1_3_npc", 4);
				break;
			}
			if (tempscr2 != nullptr) {
				
				obj->deletescript();

				tempscr = new TextScript();
				tempscr->Set("dialog2_2", "level1_3_npc", 4);
				obj->setscript(tempscr);
				break;
			}
		}
	}
	if (gamedata->getvarias("level1_3_npc") == 4) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			if (tempscr != nullptr) {

				obj->deletescript();

				PuzzleEntry* tempscr2 = new PuzzleEntry();
				tempscr2->Set("puzzle_1", "level1_3_npc");
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
			PuzzleEntry* tempscr2 = dynamic_cast<PuzzleEntry*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				tempscr->Set("dialog2_3", "level1_3_npc", 6);
				break;
			}
			if (tempscr2 != nullptr) {

				obj->deletescript();

				tempscr = new TextScript();
				tempscr->Set("dialog2_3", "level1_3_npc", 6);
				obj->setscript(tempscr);
				break;
			}
		}
	}
	if (gamedata->getvarias("level1_3_npc") == 6) {
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

				obj->deletescript();

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
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			PuzzleEntry* tempscr2 = dynamic_cast<PuzzleEntry*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				tempscr->Set("dialog3_2", "level1_4_npc", 4);
				break;
			}
			if (tempscr2 != nullptr) {

				obj->deletescript();

				tempscr = new TextScript();
				tempscr->Set("dialog3_2", "level1_4_npc", 4);
				obj->setscript(tempscr);
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
			PuzzleEntry* tempscr2 = dynamic_cast<PuzzleEntry*>(obj->getscriptptr());
			if (tempscr2 != nullptr) {
				break;
			}
			if (tempscr != nullptr) {

				obj->deletescript();

				tempscr2 = new PuzzleEntry();
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
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			PuzzleEntry* tempscr2 = dynamic_cast<PuzzleEntry*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				tempscr->Set("dialog4_2");
				break;
			}
			if (tempscr2 != nullptr) {

				obj->deletescript();

				tempscr = new TextScript();
				tempscr->Set("dialog4_2");
				obj->setscript(tempscr);
				break;
			}
		}
	}
	if (gamedata->getvarias("level1_3_npc") >= 5 &&
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
					tempscr->Set("dialog4_2");
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
				obj->deletescript();

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
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			PuzzleEntry* tempscr2 = dynamic_cast<PuzzleEntry*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				tempscr->Set("dialog8_2", "level2_1_npc", 4);
				break;
			}
			if (tempscr2 != nullptr) {
				obj->deletescript();

				tempscr = new TextScript();
				tempscr->Set("dialog8_2", "level2_1_npc", 4);
				obj->setscript(tempscr);
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
				obj->deletescript();

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
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			PuzzleEntry* tempscr2 = dynamic_cast<PuzzleEntry*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				tempscr->Set("dialog7_2", "level2_2_npc", 4);
				break;
			}
			if (tempscr2 != nullptr) {

				obj->deletescript();

				tempscr = new TextScript();
				tempscr->Set("dialog7_2", "level2_2_npc", 4);
				obj->setscript(tempscr);
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
			PuzzleEntry* tempscr2 = dynamic_cast<PuzzleEntry*>(obj->getscriptptr());
			if (tempscr2 != nullptr) {
				break;
			}
			if (tempscr != nullptr) {

				obj->deletescript();

				tempscr2 = new PuzzleEntry();
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
			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			PuzzleEntry* tempscr2 = dynamic_cast<PuzzleEntry*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				tempscr->Set("dialog9_2", "level2_4_npc", 4);
				break;
			}
			if (tempscr2 != nullptr) {

				obj->deletescript();

				tempscr = new TextScript();
				tempscr->Set("dialog9_2", "level2_4_npc", 4);
				obj->setscript(tempscr);
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

				obj->deletescript();

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

			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			PuzzleEntry* tempscr2 = dynamic_cast<PuzzleEntry*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				tempscr->Set("dialog10_1", "level2_5_npc", 3);
				TextureComponent* tempcom2 = dynamic_cast<TextureComponent*>(obj->getcomponent(E_Component::TextureComponent));
				tempcom2->setbitmap("npc_assistant", 115, 146);
				tempcom2->setrect(Rect(115, 146));
				break;
			}
			if (tempscr2 != nullptr) {

				obj->deletescript();

				tempscr = new TextScript();
				tempscr->Set("dialog10_1", "level2_5_npc", 3);
				TextureComponent* tempcom2 = dynamic_cast<TextureComponent*>(obj->getcomponent(E_Component::TextureComponent));
				tempcom2->setbitmap("npc_assistant", 115, 146);
				tempcom2->setrect(Rect(115, 146));
				obj->setscript(tempscr);
				break;
			}
		}
	}
	if (gamedata->getvarias("level2_5_npc") == 3) {
		for (ObjIter iter = temp.first; iter != temp.second; ++iter)
		{
			GameObject* obj = iter.operator*().second;

			CollisonCompoenet* tempcom = dynamic_cast<CollisonCompoenet*>(obj->getcomponent(E_Component::CollisonCompoenet));
			if (tempcom != nullptr) {
				obj->setisActive(false);
			}

			TextScript* tempscr = dynamic_cast<TextScript*>(obj->getscriptptr());
			if (tempscr != nullptr) {
				obj->setisActive(false);
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