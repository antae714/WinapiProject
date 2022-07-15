#include "BitmapManager.h"

BitmapManager::BitmapManager()
{
	
}

BitmapManager::~BitmapManager()
{
	for (map<pair<int, int>, HBITMAP> item1 : bitmaparr) {
		for (pair<pair<int, int>, HBITMAP>item2 : item1) {
			DeleteObject(item2.second);
		}
	}
}

HBITMAP BitmapManager::getBitmap(const E_Bitmap& p_enum, const int& p_x, const int& p_y)
{
	
	map<pair<int, int>, HBITMAP> tempMap = bitmaparr.at((int)p_enum);
	map<pair<int, int>, HBITMAP>::iterator iter = tempMap.find(pair<int, int>(p_x, p_y));
	if (iter != tempMap.end()) {
		return iter.operator*().second;
	}
	else {
		return Loadbmp(p_enum, p_x, p_y);
	}
}

HBITMAP BitmapManager::Loadbmp(const E_Bitmap& p_enum, const int& p_x, const int& p_y)
{
	HBITMAP tempbit = (HBITMAP)LoadImage(NULL, enumBitmap::toFile(p_enum).c_str(), IMAGE_BITMAP, p_x, p_y, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	pair<map<pair<int, int>, HBITMAP>::iterator, bool> iter;
	iter = bitmaparr.at((int)p_enum).emplace(pair<int, int>(p_x, p_y), tempbit);
	return iter.first.operator*().second;
}
