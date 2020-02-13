#pragma once

#include "MoveGenerator.h"

class Pegboard;

typedef PossibleMoveColl Game;

class Referee
{
public:
	Referee() {};

	static void DisplayOfficialGame(Game&);
	static int CountValidMoves(Game&, Pegboard&);
};