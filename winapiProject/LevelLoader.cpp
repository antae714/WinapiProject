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
            if (tempmap.find("Value") != tempmap.end())
            {
                temp = tempmap.find("Value")->second;
            }
            else
            {
                continue;
            }

            tempobj->setscript(AllocScript(enumScr::conversion(temp)));

            if ("MoveMap" == temp)
            {
                string src = enumObj::conversion(p_file), dest = "";
                int x = 0, y = 0;

                if (tempmap.find("Src") != tempmap.end())
                {
                    src = tempmap.find("Src")->second;
                }
                if (tempmap.find("Dest") != tempmap.end())
                {
                    dest = tempmap.find("Dest")->second;
                }
                if (tempmap.find("X") != tempmap.end())
                {
                    x = stoi(tempmap.find("X")->second);
                }
                if (tempmap.find("Y") != tempmap.end())
                {
                    y = stoi(tempmap.find("Y")->second);
                }

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

                if (tempmap.find("Top") != tempmap.end())
                {
                    top = stoi(tempmap.find("Top")->second);
                }
                if (tempmap.find("Bottom") != tempmap.end())
                {
                    bottom = stoi(tempmap.find("Bottom")->second);
                }
                if (tempmap.find("Left") != tempmap.end())
                {
                    left = stoi(tempmap.find("Left")->second);
                }
                if (tempmap.find("Right") != tempmap.end())
                {
                    right = stoi(tempmap.find("Right")->second);
                }

                PlayerScript* tempscr = dynamic_cast<PlayerScript*>(tempobj->getscriptptr());
                tempscr->SetMovableArea(top, bottom, left, right);
            }

            if ("LineScript" == temp)
            {
                int first = 0, second = 0;
                if (tempmap.find("first") != tempmap.end())
                {
                    first = stoi(tempmap.find("first").operator*().second);
                }
                if (tempmap.find("second") != tempmap.end())
                {
                    second = stoi(tempmap.find("second").operator*().second);
                }
                _ASSERT(first && "미할당");
                _ASSERT(second && "미할당");
                LineScript* tempscr = dynamic_cast<LineScript*>(tempobj->getscriptptr());
                tempscr->Set(first, second, true);
            }
        }

        else if (key == "Transform")
        {
            TransformComponent* tempcomp = new TransformComponent();
            int x = 0, y = 0;
            float rotate = 0.000000f;

            if (tempmap.find("X") != tempmap.end())
            {
                x = stoi(tempmap.find("X")->second);
            }
            if (tempmap.find("Y") != tempmap.end())
            {
                y = stoi(tempmap.find("Y")->second);
            }
            if (tempmap.find("Rotate") != tempmap.end())
            {
                rotate = stof(tempmap.find("Rotate")->second);
            }

            tempcomp->setpivot(Vector2(x, y));
            tempcomp->setrotate(rotate);

            tempobj->pushcomponent(E_Component::TransformComponent, tempcomp);
        }

        else if (key == "UITransform")
        {
        int x = 0, y = 0;

        if (tempmap.find("X") != tempmap.end())
        {
            x = stoi(tempmap.find("X")->second);
        }
        if (tempmap.find("Y") != tempmap.end())
        {
            y = stoi(tempmap.find("Y")->second);
        }

        UITransformComponent* tempcomp = new UITransformComponent(Vector2(x, y), 0);
        tempobj->pushcomponent(E_Component::UITransformComponent, tempcomp);
        }

        else if (key == "Texture")
        {
            TextureComponent* tempcomp = new TextureComponent();
            string bitmap;
            int x = 0, y = 0, width = 0, height = 0, twidth = 100, theight = 100;
            float rotate = 0.000000f;

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
            if (tempmap.find("ObjectWidth") != tempmap.end())
            {
                width = stoi(object->find(key)->second.find("ObjectWidth")->second);
            }
            if (tempmap.find("ObjectHeight") != tempmap.end())
            {
                height = stoi(object->find(key)->second.find("ObjectHeight")->second);
            }
            if (tempmap.find("TextureWidth") != tempmap.end())
            {
                twidth = stoi(object->find(key)->second.find("TextureWidth")->second);
            }
            if (tempmap.find("TextureHeight") != tempmap.end())
            {
                theight = stoi(object->find(key)->second.find("TextureHeight")->second);
            }
            if (tempmap.find("Bitmap") != tempmap.end())
            {
                bitmap = object->find(key)->second.find("Bitmap")->second;
            }
            if (tempmap.find("Rotate") != tempmap.end())
            {
                rotate = stof(tempmap.find("Rotate")->second);
            }

            tempcomp->setrect(Rect(rotate, (float)width, (float)height));
            tempcomp->setbitmap(bitmap, twidth, theight);

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

            if (tempmap.find("Interactive") != tempmap.end())
            {
                interactive = stoi(object->find(key)->second.find("Interactive")->second);
            }

            tempcomp->setkey(interactive);
            tempobj->pushcomponent(E_Component::KeyInputComponenet, tempcomp);
        }

        else if (key == "Collison")
        {
        int width = 0, height = 0;
        if (tempmap.find("Width") != tempmap.end())
        {
            width = stoi(object->find(key)->second.find("Width")->second);
        }
        if (tempmap.find("Height") != tempmap.end())
        {
            height = stoi(object->find(key)->second.find("Height")->second);
        }
        CollisonCompoenet* tempcomp = new CollisonCompoenet(Rect(0, width, height));
        tempobj->pushcomponent(E_Component::CollisonCompoenet, tempcomp);
        }

        else if (key == "Text")
        {
        int x = 0, y = 0;
        string filename;
        if (tempmap.find("X") != tempmap.end())
        {
            x = stoi(tempmap.find("X")->second);
        }
        if (tempmap.find("Y") != tempmap.end())
        {
            y = stoi(tempmap.find("Y")->second);
        }
        if (tempmap.find("Filename") != tempmap.end())
        {
            filename = tempmap.find("Filename")->second;
        }
        TextComponent* tempcomp = new TextComponent(Vector2(x, y), filename);
        tempobj->pushcomponent(E_Component::TextComponent, tempcomp);
 }
    }

    //AllObject::getInstance()->push(tempobj);
    tempobj->Start();
    return tempobj;
}