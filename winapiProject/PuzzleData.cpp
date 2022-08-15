#include "PuzzleData.h"

PuzzleData::PuzzleData()
{
    isclear = false;
}

bool PuzzleData::getisclear()
{
    return isclear;
}

void PuzzleData::setisclear(bool p_isclear)
{
    isclear = p_isclear;
}
