#pragma once

#include <string>

using namespace std;

enum class E_Component
{
	TransformComponent,
	TextureComponent,
	TextComponent,
	InputComponenet,
	KeyInputComponenet,

	MAX
};
//������Ʈ �̳��� ��Ʈ����ȯ �Լ��Դϴ�
namespace enumCom {;

string conversion(const E_Component&);

E_Component conversion(const string&);

}
