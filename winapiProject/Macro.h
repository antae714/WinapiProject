#pragma once

#define SAFEDELETE(name) if(name){delete name; name = nullptr;}

#define ENUMTOSTRING(type, name) case type::name: return #name;
#define STRINGTOENUM(type, name) if (#name == p_str) return type::name;
//#define STRINGTOENUM(name, type) if (#name == p_str) return type::name;

#define GETCOMPONENT(obj, component) dynamic_cast<component*>(obj->getcomponent(E_Component::component))
#define GETSCRIPT(obj, Script) dynamic_cast<Script*>(obj->getscriptptr())


