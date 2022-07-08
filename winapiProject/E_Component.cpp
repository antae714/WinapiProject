#include "E_Component.h"


string enumCom::conversion(E_Component p_enum) {
	switch (p_enum)
	{
	case E_Component::TransformComponent:
		return "TransformComponent";
	case E_Component::TextureComponent:
		return "TextureComponent";
	case E_Component::InputComponenet:
		return "InputComponenet";
	case E_Component::MAX:
		return "";
	}
}


E_Component enumCom::conversion(string p_str) {
	
	if ("TransformComponent" == p_str) {
		return E_Component::TransformComponent;
	}
	else if ("TextureComponent" == p_str) {
		return E_Component::TextureComponent;
	}
	else if ("InputComponenet" == p_str) {
		return E_Component::InputComponenet;
	}
	return E_Component::MAX;
}
