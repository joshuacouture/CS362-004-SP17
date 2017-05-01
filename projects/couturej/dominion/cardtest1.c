#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Unit Test for Smithy
//Draws 3 cards and discards smithy card
int main(){

//Initialize gamestate
struct gameState* state = newGame();
int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, great_hall, smithy};
int seed = 10;
int players = 2;
initializeGame(players, k, seed, state);

int choice1, choice2, choice3 = 0;  //no choices, but necessary to use cardEffect

//current player is 0, state->handCount[0] should be 5, state->numActions should be = 1

int fail = 0; //keep track of whether the test fails

//should add 2 cards - (3 new cards and discard smithy)
cardEffect(smithy, choice1, choice2, choice3, state, 0, NULL); 

if (state->handCount[0] != 7)
	fail = 1;

if (fail == 0)
	printf("Smithy Card: TEST SUCCESSFULLY COMPLETED\n");
else
	printf("Smithy Card: TEST FAILED \n");

return 0;
}