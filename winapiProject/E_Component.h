#pragma once

#include <string>

using namespace std;

enum class E_Component
{
	TransformComponent,
	TextureComponent,
	InputComponenet,

	MAX
};
//������Ʈ �̳��� ��Ʈ����ȯ �Լ��Դϴ�
namespace enumCom {;

string conversion(E_Component);

E_Component conversion(string);

}
