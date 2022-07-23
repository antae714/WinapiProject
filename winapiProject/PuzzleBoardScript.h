#pragma once
#include <vector>
#include <utility>
#include "Script.h"
using namespace std;
class PuzzleBoardScript : public Script
{
private:
	vector<bool> answercheck;
	vector<pair<int, int>> answerVec;
public:
	PuzzleBoardScript();
public:
	virtual void Start();
	bool isAnswer(const GameObject*, const GameObject*);

	void answer(int);
};