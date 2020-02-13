#pragma once


#include <vector>
#include <list>
#include "Peg.h"
#include "Point.h"

#include "MoveGenerator.h"

class Pegboard
{
public:
	Pegboard();

	static POINT s_holes[];

	typedef std::vector<POINT> HoleColl;

	void RemovePeg(const POINT& peg)
	{
		HoleColl::const_iterator itBegin = m_PegLocations.begin();
		POINT* pts = (POINT*)&(*itBegin);
		int nsize = m_PegLocations.size();
		while(nsize--)
		{
			if(peg.x == pts->x &&
				peg.y == pts->y)
			{
				// set the flag for 'unused'
				pts->x = -1;
				return;
			}
			pts++;
		}
	}

	void AddPeg(const POINT& ptDest)
	{
		HoleColl::const_iterator itBegin = m_PegLocations.begin();
		POINT* pts = (POINT*)&(*itBegin);
		int nsize = m_PegLocations.size();
		while(nsize--)
		{
			// look for the unused marker
			if(pts->x == -1)
			{
				pts->x = ptDest.x;
				pts->y = ptDest.y;
				return;
			}
			pts++;
		}
	}

	bool FindValidNextMove(PossibleMove** ppM)
	{
		HoleColl::const_iterator itBegin = m_PegLocations.begin();
		POINT* pts = (POINT*)&(*itBegin);
		int nsize = m_PegLocations.size();
		while(nsize--)
		{
			// look for the unused marker
			if(pts->x != -1)
			{
				// found a valid peg location.  look for this in the
				// possible moves array, and check for validity.
				
				PossibleMoveColl pmc;
				MoveGenerator::GetMovesThatStartWith(pts, pmc);

				// iterate through this pre-shuffled array, looking
				// for a valid move.  If found, fill the double
				// pointer with the move pointer (it points to the
				// static array location) and return.
				
				PossibleMove** ppMoves = (PossibleMove**)&(*(pmc.begin()));
				int pmndx = pmc.size();
				while(pmndx--)
				{
					PossibleMove* pPossible = *ppMoves;
					if(IsPossibleMoveValid(*pPossible))
					{
						*ppM = pPossible;
						return true;
					}
					ppMoves++;
				}
			}
			pts++;
		}
		// didn't find any
		return false;
	}

	bool IsPossibleMoveValid(const PossibleMove& pm)
	{
		if(!(!IsPegLoc(pm.ptend) &&
			IsPegLoc(pm.ptbegin) &&
			IsPegLoc(pm.ptkilled)) )
		{
			return false;
		}

		return true;
	}

	void MovePeg(const PossibleMove& ptDest);
	bool IsPegLoc(const POINT& ptLoc) const
	{
		// this method is used for rule checking
		// return values:
		//		true if there is a peg at the given location

		HoleColl::const_iterator itBegin = m_PegLocations.begin();
		POINT* pts = (POINT*)&(*itBegin);
		int nsize = m_PegLocations.size();
		while(nsize--)
		{
			if(ptLoc.x == pts->x &&
				ptLoc.y == pts->y)
				return true;

			pts++;
		}
			
		return false;
	}
private:
	HoleColl m_PegLocations;
};