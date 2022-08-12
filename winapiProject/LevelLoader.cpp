#include "LevelLoader.h"
#include "GameData.h"
#include "GameObject.h"
#include "E_Component.h"
#include "CompanentManager.h"
#include "TransformComponent.h"
#include "TextureComponent.h"
#include "AllObject.h"
#include "Rect.h"
#include "Vector2.h"
#include "InputComponenet.h"
#include "KeyInputComponent.h"
#include "E_Objtype.h"
#include "MoveMap.h"
#include "PlayerScript.h"
#include "LineScript.h"
#include "CollisonCompoenet.h"
#include "TextComponent.h"
#include "UITransformComponent.h"
#include "PuzzleEntry.h"
#include "AnimationStruct.h"
#include "Macro.h"


void LevelLoader::LoadLevel(E_Objtype p_file)
{
    ifstream file;
    file.open(enumObj::toFile(p_file));

    if (file.fail())
    {
        return;
    }

    while (!file.eof())
    {
        vector<string> comp;
        map<string, map<string, string>> object;
        string line;

        getline(file, line);
        if ('\0' == line[0]) continue;
        if ('/' == line[0]) continue;

        Parse(&comp, &object, line);

        AllObject::getInstance()->push(p_file, Initialize(p_file, &comp, &object));
    }

    file.close();
}

void LevelLoader::Parse(vector<string>* comp, map<string, map<string, string>>* object, string line)
{
    string value;

    while (0 != line.length())
    {
        for (int i = 0; i < line.length(); ++i)
        {
            if (',' == line[i])
            {
                value = line.substr(0, i);
                comp->push_back(value);
                line = line.substr(i + 1);
                break;
            }

            else if ('{' == line[i])
            {
                value = line.substr(0, i);
                comp->push_back(value);
                line = Layer2(value, object, line.substr(i + 1));
                break;
            }
        }
    }
}

string LevelLoader::Layer2(string key, map<string, map<string, string>>* object, string line)
{
    int instant_key = 0;
    bool intstant_sw = true;
    string key2, value;
    map<string, string> temp;

    while (1)
    {
        for (int i = 0; i < line.length(); ++i)
        {
            if (':' == line[i])
            {
                key2 = line.substr(0, i);
                line = line.substr(i + 1);
                intstant_sw = false;
                break;
            }

            else if (',' == line[i] || '}' == line[i])
            {
                value = line.substr(0, i);

                if (intstant_sw)
                {
                    if ("Script" == key)
                    {
                        key2 = "Value";
                    }
                    else
                    {
                        key2 = to_string(++instant_key);
                    }
                }
                else
                {
                    intstant_sw = true;
                }

                temp.insert(make_pair(key2, value));

                if ('}' == line[i])
                {
                    object->insert(make_pair(key, temp));
                    return line.substr(i + 1);
                }

                line = line.substr(i + 1);
                break;
            }
        }
    }
}

// 수정 필요
GameObject* LevelLoader::Initialize(E_Objtype p_file, vector<string>* comp, map<string, map<string, string>>* object)
{
    GameObject* tempobj = new GameObject();
    map<string, string> tempmap;

    for (int i = 0; i < comp->size(); i++)
    {
        string key = comp->at(i);
        if (object->find(key) != object->end())
        {
            tempmap = object->find(key)->second;
        }

        if (key == "Script")
        {
            string temp;

            GETDATA(Value, temp)
            else
            {
                continue;
            }

            tempobj->setscript(AllocScript(enumScr::conversion(temp))); 

            if ("MoveMap" == temp)
            {
                string src = enumObj::conversion(p_file), dest = "";
                int x = 0, y = 0;

                GETDATA(Src, src);
                GETDATA(Dest, dest);
                GETDATA(X, x, stoi);
                GETDATA(Y, y, stoi);

                MoveMap* tempscr = dynamic_cast<MoveMap*>(tempobj->getscriptptr());
                tempscr->Set(src, dest, x, y);
            }

            if ("PlayerScript" == temp)
            {
                TextureComponent* tempcom = dynamic_cast<TextureComponent*>(tempobj->getcomponent(E_Component::TextureComponent));
                
                int top = WINDOWY / 2 - tempcom->getySize() / 2;
                int bottom = WINDOWY / -2 + tempcom->getySize() / 2;
                int left = WINDOWX / -2 + tempcom->getxSize() / 2;
                int right = WINDOWX / 2 - tempcom->getxSize() / 2;

                GETDATA(Top, top, stoi);
                GETDATA(Bottom, bottom, stoi);
                GETDATA(Left, left, stoi);
                GETDATA(Right, right, stoi);

                PlayerScript* tempscr = dynamic_cast<PlayerScript*>(tempobj->getscriptptr());
                tempscr->SetMovableArea(top, bottom, left, right);
            }

            if ("LineScript" == temp)
            {
                int first = 0, second = 0;
                GETDATA(first, first, stoi);
                GETDATA(second, second, stoi);

                LineScript* tempscr = dynamic_cast<LineScript*>(tempobj->getscriptptr());
                tempscr->Set(first, second, true);
            }

            if ("PuzzleEntry" == temp)
            {
                string typestr;

                GETDATA(typestr, typestr);
                PuzzleEntry* tempscr = dynamic_cast<PuzzleEntry*>(tempobj->getscriptptr());
                tempscr->Set(typestr);
            }
        }

        else if (key == "Transform")
        {
            TransformComponent* tempcomp = new TransformComponent();
            int x = 0, y = 0;
            float rotate = 0.000000f;
            GETDATA(X, x, stoi);
            GETDATA(Y, y, stoi);
            GETDATA(Rotate, rotate, stoi);


            tempcomp->setpivot(Vector2(x, y));
            tempcomp->setrotate(rotate);

            tempobj->pushcomponent(E_Component::TransformComponent, tempcomp);
        }

        else if (key == "UITransform")
        {
        int x = 0, y = 0;

        GETDATA(X, x, stoi);
        GETDATA(Y, y, stoi);

        UITransformComponent* tempcomp = new UITransformComponent(Vector2(x, y), 0);
        tempobj->pushcomponent(E_Component::UITransformComponent, tempcomp);
        }

        else if (key == "Texture")
        {
            string bitmap;
            int x = 0, y = 0, width = 0, height = 0, twidth = 100, theight = 100;

            if (tempmap.find("Width") != tempmap.end())
            {
                width = stoi(object->find(key)->second.find("Width")->second);
                twidth = width;
            }
            if (tempmap.find("Height") != tempmap.end())
            {
                height = stoi(object->find(key)->second.find("Height")->second);
                theight = height;
            }
            GETDATA(ObjectWidth, width, stoi);
            GETDATA(ObjectHeight, height, stoi);
            GETDATA(TextureWidth, twidth, stoi);
            GETDATA(TextureHeight, theight, stoi);
            GETDATA(Bitmap, bitmap);

            string name = "";
            vector<string> stateName;
            vector<int> stateCount;
            double time = 0;
            GETDATA(AnimationName, name);
            GETDATA(Time, time, stod);

            for (int j = 0; tempmap.find("state_" + to_string(j)) != tempmap.end(); ++j) {
                stateName.push_back(object->find(key)->second.find("state_" + to_string(j))->second);
            }
            for (int j = 0; tempmap.find("count_" + to_string(j)) != tempmap.end(); ++j) {
                stateCount.push_back(stoi(object->find(key)->second.find("count_" + to_string(j))->second));
            }

            TextureComponent* tempcomp;
            if ("" == name)
                tempcomp = new TextureComponent(bitmap,Rect((float)width, (float)height), twidth, theight);
            else
                tempcomp = new TextureComponent(AnimationStruct(time, name, stateName, stateCount), Rect((float)width, (float)height), twidth, theight);

            tempobj->pushcomponent(E_Component::TextureComponent, tempcomp);
        }

        else if (key == "Input")
        {
            InputComponenet* tempcomp = new InputComponenet();
            tempobj->pushcomponent(E_Component::InputComponenet, tempcomp);
        }

        else if (key == "KeyInput")
        {
            KeyInputComponenet* tempcomp = new KeyInputComponenet();
            int interactive = 0x5A;

            GETDATA(Interactive, interactive, stoi);

            tempcomp->setkey(interactive);
            tempobj->pushcomponent(E_Component::KeyInputComponenet, tempcomp);
        }

        else if (key == "Collison")
        {
        int width = 0, height = 0;

        GETDATA(Width, width, stoi);
        GETDATA(Height, height, stoi);

        CollisonCompoenet* tempcomp = new CollisonCompoenet(Rect(width, height));
        tempobj->pushcomponent(E_Component::CollisonCompoenet, tempcomp);
        }

        else if (key == "Text")
        {
        int x = 0, y = 0;
        string filename;
        GETDATA(X, x, stoi);
        GETDATA(Y, y, stoi);
        GETDATA(Filename, filename);
        TextComponent* tempcomp = new TextComponent(Vector2(x, y), filename);
        tempobj->pushcomponent(E_Component::TextComponent, tempcomp);
 }
    }

    //AllObject::getInstance()->push(tempobj);
    tempobj->Start();
    return tempobj;
}