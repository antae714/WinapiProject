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
//컴포넌트 이넘의 스트링변환 함수입니다
namespace enumCom {;

string conversion(const E_Component&);

E_Component conversion(const string&);

}
