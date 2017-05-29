#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Random Test for Smithy
//Dra

int main(int argc, char ** argv[]){
	printf("---Beginning Adventurer Card Test---\n");
	srand(time(NULL));  //randomize seed  - http://stackoverflow.com/questions/822323/how-to-generate-a-random-number-in-c
	int tests = 1000;  //if no command line argument supplied do 100 tests
	if (argc > 1)  //if command line argument is supplied do that number of tests
		tests = atoi(argv[1]);
	//declare variables.  note that there are no choices in this card but they are necessary to use cardEffect
	int seed, players, deckCount, handCount, t, totalCards, player, choice1, choice2, choice3;  
	struct gameState state;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, great_hall, smithy};

	for (t = 0; t < tests; t++) {
		
		//Initialize gamestate with random seed and # of players
		seed = rand()%10000;
		players = (rand()% MAX_PLAYERS+1);
		player = rand()%players+1;
		initializeGame(players, k, seed, &state);
		
		//set deck count, hand count, and discard count for player
		handCount = numHandCards(&state);
		//make sure that completing the card will not cause a new player turn
		cardEffect(smithy, choice1, choice2, choice3, &state, 0, NULL);
		
		//3 cards are moved from deck to hand.  1 card is moved from hand to discard. 
		//player hand count should be equal to hand count prior to playing card + 2 
		
		if (numHandCards(&state) != handCount+2)
			printf("Test failed with final player hand count %d, should be %d.  Seed: %d Players: %d Player: %d\n", numHandCards(&state), handCount+2, seed, players, player);
		else
			printf("Test Succeeded!\n");
	}
printf("---Smithy Card Test Completed---\n");
return 0; 
}