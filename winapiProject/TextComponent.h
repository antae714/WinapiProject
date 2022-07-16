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
	//�ܺο��� �ؽ�Ʈ ����� �Լ�
	void nextLine();
	void beforeLine();

	//�ټ�
	string getText();
	int getnowLine();
	int getfontHeight();
	string getfontName();


	void setText(const string&);
	void setnowLine(const int&);
	void setfontHeight(const int&);
	void setfontName(const string&);
};

