#include <iostream>
#include <algorithm>

#include "MoveGenerator.h"
#include "PossibleMove.h"
#include "Peg.h"

PossibleMove MoveGenerator::s_AllMoves[] = 
{
	// begin, end, killed
	{{0,4}, {0,2}, {0,3}},
	{{0,4}, {2,2}, {1,3}},
	{{0,3}, {0,1}, {0,2}},
	{{0,3}, {2,1}, {1,2}},
	{{1,3}, {3,1}, {2,2}},
	{{1,3}, {1,1}, {1,2}},
	{{0,2}, {0,4}, {0,3}},
	{{0,2}, {2,2}, {1,2}},
	{{0,2}, {2,0}, {1,1}},
	{{0,2}, {0,0}, {0,1}},
	{{1,2}, {1,0}, {1,1}},
	{{1,2}, {3,0}, {2,1}},
	{{2,2}, {4,0}, {3,1}},
	{{2,2}, {2,0}, {2,1}},
	{{2,2}, {0,0}, {1,1}},
	{{2,2}, {0,2}, {1,2}},
	{{2,2}, {0,4}, {1,3}},
	{{0,1}, {0,3}, {0,2}},
	{{0,1}, {2,1}, {1,1}},
	{{1,1}, {1,3}, {1,2}},
	{{1,1}, {3,1}, {2,1}},
	{{2,1}, {0,1}, {1,1}},
	{{2,1}, {0,3}, {1,2}},
	{{3,1}, {1,1}, {2,1}},
	{{3,1}, {1,3}, {2,2}},
	{{0,0}, {0,2}, {0,1}},
	{{0,0}, {2,2}, {1,1}},
	{{0,0}, {2,0}, {1,0}},
	{{1,0}, {3,0}, {2,0}},
	{{1,0}, {1,2}, {1,1}},
	{{2,0}, {0,0}, {1,0}},
	{{2,0}, {4,0}, {3,0}},
	{{2,0}, {2,2}, {2,1}},
	{{3,0}, {1,0}, {2,0}},
	{{3,0}, {1,2}, {2,1}},
	{{4,0}, {2,0}, {3,0}},
	{{4,0}, {2,2}, {3,1}}
};


void MoveGenerator::GenerateRandomGame(PossibleMoveColl& pmc)
{
	static const int nSize = sizeof(s_AllMoves) / sizeof(s_AllMoves[0]);

	// generate 14 random numbers between 0 and nSize

	static const int nPegs = 14;

	int nCount = nPegs - 1;
	while(nCount--)
	{
		int ndx = rand() % nSize;
		pmc.push_back(  &s_AllMoves[ndx]  );
	}
}

void MoveGenerator::GetMovesThatStartWith(POINT* ppt, PossibleMoveColl& pmc)
{
	int nSize = sizeof(s_AllMoves) / sizeof(s_AllMoves[0]);

	while(nSize--)
	{
		if(s_AllMoves[nSize].ptbegin.x == ppt->x &&
			s_AllMoves[nSize].ptbegin.y == ppt->y)
		{
			pmc.push_back(&s_AllMoves[nSize]);
		}
	}

	// now shuffle before returning
	random_shuffle(pmc.begin(), pmc.end());
}











