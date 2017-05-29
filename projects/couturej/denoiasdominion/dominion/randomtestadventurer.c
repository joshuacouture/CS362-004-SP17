#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Random Test for Adventurer
//Reveal cards from deck until 2 treasure cards are found.  place treasure cards in hand and discard the rest.

int main(int argc, char ** argv[]){
	printf("---Beginning Adventurer Card Test---\n");
	srand(time(NULL));  //randomize seed  - http://stackoverflow.com/questions/822323/how-to-generate-a-random-number-in-c
	int tests = 1000;  //if no command line argument supplied do 100 tests
	if (argc > 1)  //if command line argument is supplied do that number of tests
		tests = atoi(argv[1]);
	//declare variables.  note that there are no choices in this card but they are necessary to use cardEffect
	int seed, players, deckCount, handCount, t, totalCards, player, choice1, choice2, choice3 = 0;  
	struct gameState state;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, great_hall, smithy};

	for (t = 0; t < tests; t++) {
		
		//Initialize gamestate with random seed and # of players
		seed = rand()%10000;
		players = (rand()% MAX_PLAYERS+1);
		player = (rand() % players);
		initializeGame(players, k, seed, &state);
		
		//set deck count, hand count, and discard count for player
		handCount = numHandCards(&state);
		
		cardEffect(adventurer, choice1, choice2, choice3, &state, 0, NULL);
		
		//2 cards are moved from deck to hand.  1 card is moved from hand to discard. unknown number of cards moved from deck to discard
		//player hand count should be equal to hand count prior to playing card + 1 
		
		
		if (numHandCards(&state) != handCount+1)
			printf("Test failed with final player hand count %d, should be %d\n", numHandCards(&state), handCount+1);
		else
			printf("Test Succeeded!\n");
	}		
	
printf("---Adventure Card Test Completed---\n");
return 0; 
}