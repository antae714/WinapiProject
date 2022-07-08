#include "LevelLoader.h"
#include "GameObject.h"
#include "E_Component.h"
#include "CompanentManager.h"
#include "TransformComponent.h"
#include "TextureComponent.h"
#include "AllObject.h"
#include "Rect.h"
#include "Vector2.h"
#include "TestScript.h"
#include "TestScript2.h"
#include "TestScript3.h"
#include "InputComponenet.h"

void LevelLoader::LoadLevel(string p_file)
{
    ifstream file;
    file.open(p_file);

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

        Parse(&comp, &object, line);

        AllObject::getInstance()->push(p_file, Initialize(&comp, &object));
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
GameObject* LevelLoader::Initialize(vector<string>* comp, map<string, map<string, string>>* object)
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

            if (temp == "TestScript")
            {
                tempobj->setscript(new TestScript());
            }
            if (temp == "TestScript2")
            {
                tempobj->setscript(new TestScript2());
            }
            if (temp == "TestScript3")
            {
                tempobj->setscript(new TestScript3());
            }
        }

        if (key == "Transform")
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

        if (key == "Texture")
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

        if (key == "Input")
        {
            InputComponenet* tempcomp = new InputComponenet();
            tempobj->pushcomponent(E_Component::InputComponenet, tempcomp);
        }
    }

    //AllObject::getInstance()->push(tempobj);
    tempobj->Start();
    return tempobj;
}