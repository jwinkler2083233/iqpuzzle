#pragma once

#include "Point.h"
#include "Peg.h"
#include "PossibleMove.h"

class MoveGenerator
{
public:
	MoveGenerator(){};

	static void GenerateRandomGame(PossibleMoveColl&);
	static void GetMovesThatStartWith(POINT* ppt, PossibleMoveColl& pmc);

	static PossibleMove s_AllMoves[];

};