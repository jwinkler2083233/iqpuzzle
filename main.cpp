#include <cstdio>
#include <iostream>

#include "MoveGenerator.h"
#include "Pegboard.h"
#include "Referee.h"

using namespace std;

int main()
{
  // design notes:
  //	This program will:
  //		Generate a set of a set of 15 random numbers, 0-15
  //		Create a pegboard for each.
  //		Evaluate the random numbers for validity
  //		Output the moves if the game was valid

  cout << "IQPuzzle shows the moves to win the game with the golf tees on a wooden triangle."
    << endl;


  // seed the random number 
  srand(1234);

  MoveGenerator mg;

  double niter = 0;
  int niter2 = 0;
  int mostvalid = 0;
  PossibleMoveColl coll;

  // loop, generating a set of 15 random numbers each iteration
  while (1)
  {
    Pegboard pb;
    coll.clear();
    mg.GenerateRandomGame(coll);

    int nValid = Referee::CountValidMoves(coll, pb);

    if (nValid > mostvalid)
    {
      Referee::DisplayOfficialGame(coll);

      cout << "*" << endl << endl;
      if (nValid == 13)
      {
        cout << "******\n";

        // if this is a perfect game, stop everything.
        PossibleMove& pback = *(coll[12]);
        if (pback.ptend.x == 0 &&
          pback.ptend.y == 4)
        {
          cout << "**************\n";
          return 1;
        }
      }
      else {
        mostvalid = nValid;
      }
    }

    niter2++;
    if( (niter2 & 0xffffff) == 0xffffff)
    {
      niter += niter2;
      cout << niter << "\t\tMost Valid Moves:  " << mostvalid << endl;
      niter2 = 0;
    }
  }
  return 0;
}