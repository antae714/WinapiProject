#include "AnimationStruct.h"
#include "GameTime.h"

AnimationStruct::AnimationStruct(double p_animation_time, string p_name, vector<string> p_statename, vector<int> p_statecount) :
	direction(false), time(0), maxtime(p_animation_time), count(1), state(0), name(p_name), statename(p_statename), statecount(p_statecount)
{
}

AnimationStruct::~AnimationStruct()
{
}

void AnimationStruct::Update()
{
	time += GameTime::getInstance()->getdeltaTime();
	if (time >= maxtime)
	{
		time -= maxtime;
		if (count >= statecount.at(state)) count = 0;
		++count;
	}
}

string AnimationStruct::getbitmapname()
{
	return name + "_" + statename.at(state) + "_" + to_string(count);
}

void AnimationStruct::setState(int p_state)
{
	state = p_state;
}

void AnimationStruct::setState(string p_str)
{
	for (int i = 0; i < statename.size(); ++i) {
		if (statename.at(i) == p_str) {
			state = i;
			return;
		}
	}
}

bool AnimationStruct::getdirection() const
{
	return direction;
}

void AnimationStruct::setdirection(bool p_direction)
{
	direction = p_direction;
}
