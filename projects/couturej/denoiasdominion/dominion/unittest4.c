#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Unit Test for isGameOver()
//isGameOver() returns 1 for over, 0 for not over

int main(){


//initialize standard game state with 2 players and random seed = 10
struct gameState* state = newGame();
int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
int seed = 10;
int players = 2;
initializeGame(players, k, seed, state);


int fail = 0; //keep track of whether the test fails

//fresh game - should not be over
if (isGameOver(state) != 0)
	fail = 1;

//game is over if supplyCount[province] == 0
state->supplyCount[province] == 5;
//game should not be over!
if (isGameOver(state) !=0)
	fail = 1;

//game should be over!
state->supplyCount[province] = 0;

//supplyCount[province] == 0 so game should be over!
if (isGameOver(state) !=1)
	fail = 1;


if (fail == 0)
	printf("isGameOver(): TEST SUCCESSFULLY COMPLETED\n");
else
	printf("isGameOver(): TEST FAILED \n");


return 0;
}