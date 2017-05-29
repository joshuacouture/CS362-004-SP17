#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Unit Test for Great Hall card
//Draws 1 Card (but discards Great Hall) and adds 1 action
int main(){

//Initialize gamestate
struct gameState state;
int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, great_hall, smithy};
int seed = 10;
int players = 2;
int choice1, choice2, choice3 = 0;  //no choices, but necessary to use cardEffect
initializeGame(players, k, seed, &state);

//current player is 0, state->handCount[0] should be 5, state->numActions should be = 1
state.handCount[0] = 5;

int fail = 0; //keep track of whether the test fails

//should add 1 action; state->numActions = 2
cardEffect(great_hall, choice1, choice2, choice3, &state, 0, NULL); 
//if hand count changes or number actions isn't incremented fail test
if (state.handCount[0] != 5 || state.numActions!=2)
	fail = 1;

if (fail == 0)
	printf("Great Hall Card: TEST SUCCESSFULLY COMPLETED\n");
else
	printf("Great Hall Card: TEST FAILED \n");



return 0;
}