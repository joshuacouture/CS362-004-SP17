#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Unit Test for Adventurer
//Reveal cards from deck until 2 treasure cards are found.  place treasure cards in hand and discard the rest.
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

//should add 1 card (2 new cards and discard the adventurer card played)
cardEffect(adventurer, choice1, choice2, choice3, state, 0, NULL); 
//if hand count changes or number actions isn't incremented fail test
if (state->handCount[0] != 6)
	fail = 1;

if (fail == 0)
	printf("Adventurer Card: TEST SUCCESSFULLY COMPLETED\n");
else
	printf("Adventurer Card: TEST FAILED \n");


return 0;
}