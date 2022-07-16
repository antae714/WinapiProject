#include "TextComponent.h"

TextComponent::TextComponent() :
	Text(""), nowLine(0), fontHeight(0), fontName("")
{
}

TextComponent::TextComponent(const string& p_text, const int& p_height, const string& p_fontName) :
	Text(p_text), nowLine(0), fontHeight(p_height), fontName(p_fontName)
{
}

TextComponent::~TextComponent()
{

}

void TextComponent::nextLine()
{
	++nowLine;
}

void TextComponent::beforeLine()
{
	--nowLine;
}

string TextComponent::getText()
{
	//라인 정보에맞게 출력
	return Text;
}

int TextComponent::getnowLine()
{
	return nowLine;
}

int TextComponent::getfontHeight()
{
	return fontHeight;
}

string TextComponent::getfontName()
{
	return fontName;
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
