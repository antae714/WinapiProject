#include "TextComponent.h"
#include "Vector2.h"
#include "E_Objtype.h"
#include <fstream>

TextComponent::TextComponent() :
	point(new Vector2()), nowLine(0)
{
}

TextComponent::TextComponent(const Vector2& p_pint, const string& p_text) :
	point(new Vector2(p_pint)), nowLine(0)
{
	FileSet(p_text);
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
	if (nowLine > Text.size() - 1) return Text.at(nowLine % Text.size());
	return Text.at(nowLine);
}

int TextComponent::getnowLine() const
{
	return nowLine;
}

void TextComponent::setpoint(const Vector2& p_point)
{
	*point = p_point;
}

void TextComponent::setnowLine(const int& p_val)
{
	nowLine = p_val;
}
