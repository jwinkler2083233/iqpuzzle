#pragma once

#include <vector>

#include "Point.h"

struct PossibleMove
	{
		POINT ptbegin;
		POINT ptend;
		POINT ptkilled;
	};


typedef std::vector<PossibleMove*> PossibleMoveColl;
