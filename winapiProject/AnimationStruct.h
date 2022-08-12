#pragma once

#include <string>
#include <vector>
#include "UpdateFunction.h"

using namespace std;
class AnimationStruct : public UpdateFunction
{
private:
	bool direction;
	double time;
	double maxtime;
	double breaktime;
	int count;
	int state;

	string name;
	vector<string> statename;
	vector<int> statecount;
public:
	AnimationStruct(double p_animation_time, string p_name, vector<string> p_statename, vector<int> statecount);
	virtual ~AnimationStruct();

public:
	virtual void Update();
	string getbitmapname();

	void setState(int);
	void setState(string);



	bool getdirection() const;
	void setdirection(bool);
};

