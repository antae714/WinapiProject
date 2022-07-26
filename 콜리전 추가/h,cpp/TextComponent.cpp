#include "TextComponent.h"
#include "Vector2.h"

TextComponent::TextComponent() :
	point(new Vector2()), Text(""), nowLine(0), fontHeight(0), fontName("")
{
}

TextComponent::TextComponent(const Vector2& p_pint, const string& p_text, const int& p_height, const string& p_fontName) :
	point(new Vector2(p_pint)), Text(p_text), nowLine(0), fontHeight(p_height), fontName(p_fontName)
{
}

TextComponent::~TextComponent()
{
	delete point;
}

void TextComponent::nextLine()
{
	++nowLine;
}

void TextComponent::beforeLine()
{
	--nowLine;
}

Vector2 TextComponent::getpoint() const
{
	return *point;
}

string TextComponent::getText() const
{
	//라인 정보에맞게 출력
	return Text;
}

int TextComponent::getnowLine() const
{
	return nowLine;
}

int TextComponent::getfontHeight() const
{
	return fontHeight;
}

string TextComponent::getfontName() const
{
	return fontName;
}

void TextComponent::setpoint(const Vector2& p_point)
{
	*point = p_point;
}

void TextComponent::setText(const string& p_Text)
{
	Text = p_Text;
}

void TextComponent::setnowLine(const int& p_val)
{
	nowLine = p_val;
}

void TextComponent::setfontHeight(const int& p_val)
{
	fontHeight = p_val;
}

void TextComponent::setfontName(const string& p_fontName)
{
	fontName = p_fontName;
}
