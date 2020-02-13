#include <iostream>
#include "Referee.h"
#include "Pegboard.h"

using namespace std;

int Referee::CountValidMoves(Game& game, Pegboard& pb)
{
	// the definition of a valid game is one where all moves pass
	// the following tests:
	//		there's a peg in the location specified by the beginning move
	//		there's not a peg in the location specified by the ending move
	//		there's a peg in between the beginning and ending move

	// a game consists of a collection of possible moves.  This function
	// will validate each move.

	PossibleMove** ppM = (PossibleMove**)&(*(game.begin()));

	int nSize = game.size();
	int ndx = 0;
	for(; ndx < nSize; ndx++)
	{
		PossibleMove& pm = *(*ppM);

		if(!(!pb.IsPegLoc(pm.ptend) &&
			pb.IsPegLoc(pm.ptbegin) &&
			pb.IsPegLoc(pm.ptkilled)) )
		{
			// try to find a valid beginning peg location,
			// replacing the PossibleMove object with a 
			// valid one if found
			if(!pb.FindValidNextMove(ppM))
				break;
		}

		// do the move
		pb.MovePeg(*(*ppM));

		ppM++;
	}
	return ndx;
}

void Referee::DisplayOfficialGame(Game& game)
{
	// this method should iterate through all the possible moves for the 
	// game and should display them to the console

	Game::const_iterator itMoves;

	for(itMoves = game.begin();
			itMoves != game.end();
			itMoves++)
	{
		const PossibleMove& pm = *(*itMoves);

    cout << "From: " << pm.ptbegin.x << ", " << pm.ptbegin.y
      << "\tto\t" << pm.ptend.x << ", " << pm.ptend.y << endl;
	}

	
}