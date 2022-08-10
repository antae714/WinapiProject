#pragma once
#include <vector>
#include <utility>
#include <string>
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
	virtual void Set(const string&);
	bool isAnswer(const GameObject*, const GameObject*);

	void answer(int);
};