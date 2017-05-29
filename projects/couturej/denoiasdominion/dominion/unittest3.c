#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Unit Test for whoseTurn()

int main(){


//initialize standard game state with 4 players and random seed = 10
struct gameState* state = newGame();
int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
int seed = 10;
int players = 4;
initializeGame(players, k, seed, state);

//start at player 0
int i = 0;
int fail = 0;


//simulate 25 turn changes to make sure that the appropriate value for whoseTurn() is returned
//player turns should go from 0 to 3 repeating; 0,1,2,3,0,1,2,3
for (i = 0; i < 25; i++)
	{
		if (whoseTurn(state) != i%4)
			fail = 1;
		endTurn(state);
	}
	
if (fail == 0)
	printf("whoseTurn(): TEST SUCCESSFULLY COMPLETED\n");
else
	printf("whoseTurn(): TEST FAILED \n");

return 0;
}