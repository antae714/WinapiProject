#pragma once
#include <string>
#include "Component.h"

class TextComponent : public Component
{
private:
	string Text;
	int nowLine;
	int fontHeight;
	string fontName;
public:
	TextComponent();
	TextComponent(const string&, const int&, const string&);
	virtual ~TextComponent();

public:
	//외부에서 텍스트 제어용 함수
	void nextLine();
	void beforeLine();

	//겟셋
	string getText();
	int getnowLine();
	int getfontHeight();
	string getfontName();


	void setText(const string&);
	void setnowLine(const int&);
	void setfontHeight(const int&);
	void setfontName(const string&);
};

