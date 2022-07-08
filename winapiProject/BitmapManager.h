#pragma once

#include <Windows.h>
#include <array>
#include <map>
#include "SingletonCls.h"
#include "E_Bitmap.h"

using namespace std;

class BitmapManager : public SingletonCls<BitmapManager>
{
public:
	array<map<pair<int, int>, HBITMAP>, (int)E_Bitmap::MAX> bitmaparr;

public:
	BitmapManager();
	~BitmapManager();

public:
	HBITMAP getBitmap(const E_Bitmap&, const int&, const int&);


private:
	HBITMAP Loadbmp(const E_Bitmap&, const int&, const int&);

};

