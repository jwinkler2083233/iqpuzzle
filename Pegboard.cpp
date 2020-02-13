#include <iostream>
#include <string.h>
#include <algorithm>

#include "Pegboard.h"
#include "Peg.h"
#include "PossibleMove.h"

POINT Pegboard::s_holes[] = 
{
	{0,4},
	{0,3}, {1,3},
	{0,2}, {1,2}, {2,2},
	{0,1}, {1,1}, {2,1}, {3,1},
	{0,0}, {1,0}, {2,0}, {3,0}, {4,0}
};

Pegboard::Pegboard()
: m_PegLocations(14)
{
	POINT* pLayout = (POINT*)&(*(m_PegLocations.begin()));
	memcpy(pLayout, &s_holes[1], sizeof(POINT) * 14);
}


void Pegboard::MovePeg(const PossibleMove& move)
{
	RemovePeg(move.ptbegin);
	RemovePeg(move.ptkilled);
	AddPeg(move.ptend);
}



























