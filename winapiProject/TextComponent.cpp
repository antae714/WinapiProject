#include "TextComponent.h"
#include "Vector2.h"
#include "E_Objtype.h"
#include <fstream>

TextComponent::TextComponent() :
	point(new Vector2()), nowLine(0), nownum(0)
{
}

TextComponent::TextComponent(const Vector2& p_pint, const string& p_text) :
	point(new Vector2(p_pint)), nowLine(0), nownum(0)
{
	FileSet(p_text);
}

TextComponent::~TextComponent()
{
	delete point;
}

bool TextComponent::nextLine()
{
	if (nowLine < Text.size() - 1) {
		++nowLine;
		nownum = 0;
		return true;
	}
	else {
		return false;
	}
}

bool TextComponent::beforeLine()
{
	if (nowLine >= Text.size()) {
		--nowLine;
		nownum = 0;
		return true;
	}
	else {
		return false;
	}
}

void TextComponent::nextnownum()
{
	if (nownum < Text.at(nowLine).size() -1) {
		++nownum;
		if(0 > Text.at(nowLine).at(nownum))
			++nownum;
	}
}

void TextComponent::FileSet(const string& p_text)
{
	ifstream file;
	file.open("./Resource/TextScript/" + p_text + ".txt");
	 
	if (file.fail()) return;

	while (!file.eof()) {
		string line;
		getline(file, line);
		if ('\0' == line[0]) continue;
		if ('/' == line[0]) continue;
		Text.push_back(line);
	}
	file.close();
}

Vector2 TextComponent::getpoint() const
{
	return *point;
}

string TextComponent::getText() const
{
	//라인 정보에맞게 출력
	if (nowLine > Text.size() - 1) return Text.at(nowLine);
	return Text.at(nowLine);
}

int TextComponent::getnowLine() const
{
	return nowLine;
}

int TextComponent::getnownum() const
{
	return nownum;
}

void TextComponent::setpoint(const Vector2& p_point)
{
	*point = p_point;
}

void TextComponent::setnowLine(const int& p_val)
{
	nowLine = p_val;
}
