#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Random Test for Village
////Draws 1 cards and add 2 actions

int main(int argc, char ** argv[]){
	printf("---Beginning village Card Test---\n");
	srand(time(NULL));  //randomize seed  - http://stackoverflow.com/questions/822323/how-to-generate-a-random-number-in-c
	int tests = 1000;  //if no command line argument supplied do 100 tests
	if (argc > 1)  //if command line argument is supplied do that number of tests
		tests = atoi(argv[1]);
	//declare variables.  note that there are no choices in this card but they are necessary to use cardEffect
	int seed, players, deckCount, handCount, t, totalCards, player, choice1, choice2, choice3, numActions= 0;  
	struct gameState state;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, great_hall, smithy};

	for (t = 0; t < tests; t++) {
		
		//Initialize gamestate with random seed and # of players
		seed = rand()%10000;
		players = (rand()% MAX_PLAYERS+1);
		player = rand()%players+1;
		initializeGame(players, k, seed, &state);
		numActions = state.numActions;
		//set deck count, hand count, and discard count for player
		deckCount = state.deckCount[player] = rand() % MAX_DECK; 
		state.handCount[player] = rand() %MAX_DECK;
		handCount = numHandCards(&state);
		cardEffect(village, choice1, choice2, choice3, &state, 0, NULL);
		//1 card is moved from deck to hand.  1 card is moved from hand to discard
		//player hand count should be equal to hand count prior to playing card 
		//player deck count should be reduced by 1
		//player discard count should be increased by 1
		if (numHandCards(&state) != handCount || state.numActions != numActions +2)   
			printf("Test failed with final player hand count %d, should be %d.  Action count is %d, should be %d.  Seed: %d Players: %d Player: %d\n", numHandCards(&state), handCount, state.numActions, numActions, seed, players, player);
		else
			printf("Test Success!\n");
						
    }
	
printf("---Village Card Test Completed---\n");
return 0; 
}