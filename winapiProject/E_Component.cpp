#include "E_Component.h"


string enumCom::conversion(const E_Component& p_enum) {
	switch (p_enum)
	{
	case E_Component::TransformComponent:
		return "TransformComponent";
	case E_Component::TextureComponent:
		return "TextureComponent";
	case E_Component::TextComponent:
		return "TextComponent";
	case E_Component::InputComponenet:
		return "InputComponenet";
	case E_Component::KeyInputComponenet:
		return "KeyInputComponenet";
	case E_Component::MAX:
		return "";
	}
}


E_Component enumCom::conversion(const string& p_str) {
	
	if ("TransformComponent" == p_str) {
		return E_Component::TransformComponent;
	}
	else if ("TextureComponent" == p_str) {
		return E_Component::TextureComponent;
	}
	else if ("TextComponent" == p_str) {
		return E_Component::TextComponent;
	}
	else if ("InputComponenet" == p_str) {
		return E_Component::InputComponenet;
	}
	else if ("KeyInputComponenet" == p_str)
	{
		return E_Component::KeyInputComponenet;
	}
	return E_Component::MAX;
}
