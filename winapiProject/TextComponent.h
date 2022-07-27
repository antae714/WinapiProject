#pragma once
#include <string>
#include <vector>
#include "Component.h"

class Vector2;
class TextComponent : public Component
{
private:
	Vector2* point;
	vector<string> Text;
	int nowLine;
	/*int fontHeight;
	string fontName;*/

public:
	TextComponent();
	TextComponent(const Vector2&, const string&);
	virtual ~TextComponent();

public:
	//외부에서 텍스트 제어용 함수
	void nextLine();
	void beforeLine();
	void FileSet(const string&);
	//겟셋
	Vector2 getpoint() const;
	string getText() const;
	int getnowLine() const;


	void setpoint(const Vector2&);
	//void setText(const string&);
	void setnowLine(const int&);
};

