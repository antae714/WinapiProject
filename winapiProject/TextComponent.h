#pragma once
#include <string>
#include <vector>
#include "Component.h"
#include "UpdateFunction.h"

class Vector2;
class TextComponent : public Component, public UpdateFunction
{
private:
	Vector2* point;
	vector<string> Text;
	int nowLine;
	int nownum;
	double accumulateTime;
	bool isdialog;
public:
	TextComponent();
	TextComponent(const Vector2&, const string&);
	TextComponent(const Vector2&, const string&, bool);
	virtual ~TextComponent();

public:
	virtual void Update();
	//외부에서 텍스트 제어용 함수
	bool nextLine();
	bool beforeLine();
	void nextnownum();
	void FileSet(const string&);
	//겟셋
	Vector2 getpoint() const;
	string getText() const;
	int getnowLine() const;
	int getnownum() const;
	bool getisdialog() const;


	void setpoint(const Vector2&);
	//void setText(const string&);
	void setnowLine(const int&);

private:
	void directionset();
};

