#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Unit Test for Village
//Draws 1 cards and add 2 actions
int main(){

//Initialize gamestate
struct gameState state;
int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, great_hall, smithy};
int seed = 10;
int players = 2;
initializeGame(players, k, seed, &state);
state.handCount[0] = 5;
int choice1, choice2, choice3 = 0;  //no choices, but necessary to use cardEffect

//current player is 0, state->handCount[0] should be 5, state->numActions should be = 1

int fail = 0; //keep track of whether the test fails

//should add 0 cards (1 new card - 1 discarded village card) and 2 actions
cardEffect(village, choice1, choice2, choice3, &state, 0, NULL); 

//if hand count changes or number actions isn't incremented by 2 fail test
if (state.handCount[0] != 5 || state.numActions != 3)
	fail = 1;

//should add 1 action; state->numActions = 3
cardEffect(village, choice1, choice2, choice3, &state, 0, NULL);
//if hand count changes or number actions isn't incremented by 2 fail test
if (state.handCount[0] != 5 || state.numActions != 5)
	fail = 1;


//should add 1 action; state->numActions = 4
cardEffect(village, choice1, choice2, choice3, &state, 0, NULL);
//if hand count changes or number actions isn't incremented by 2 fail test
if (state.handCount[0] != 5 || state.numActions != 7)
	fail = 1;


//should add 1 action; state->numActions = 5
cardEffect(village, choice1, choice2, choice3, &state, 0, NULL);
//if hand count changes or number actions isn't incremented by 2 fail test
if (state.handCount[0] != 5 || state.numActions != 9)
	fail = 1;

if (fail == 0)
	printf("Village Card: TEST SUCCESSFULLY COMPLETED\n");
else
	printf("Village Card: TEST FAILED \n");


return 0;
}