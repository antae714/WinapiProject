#pragma once
#include <string>
#include "Component.h"

class Vector2;
class TextComponent : public Component
{
private:
	Vector2* point;
	string Text;
	int nowLine;
	int fontHeight;
	string fontName;

public:
	TextComponent();
	TextComponent(const Vector2&, const string&, const int&, const string&);
	virtual ~TextComponent();

public:
	//�ܺο��� �ؽ�Ʈ ����� �Լ�
	void nextLine();
	void beforeLine();

	//�ټ�
	Vector2 getpoint() const;
	string getText() const;
	int getnowLine() const;
	int getfontHeight() const;
	string getfontName() const;


	void setpoint(const Vector2&);
	void setText(const string&);
	void setnowLine(const int&);
	void setfontHeight(const int&);
	void setfontName(const string&);
};

