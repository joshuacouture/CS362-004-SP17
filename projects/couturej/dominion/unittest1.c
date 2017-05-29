#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Unit Test for shuffle()

int main(){


//create two identical states with identical player 0 decks
struct gameState* state = newGame();
struct gameState* tempState = newGame();
state->deckCount[0]  = 0; //player 0 deck = 0 in state
tempState->deckCount[0] = 0; //player 0 deck = 0 in tempState
//fill player 0's deck in state and tempState states

int i = 0;
for (i = 0; i < 3; i++)
	{
		state->deck[0][i] = estate;
		state->deckCount[0]++;
		tempState->deck[0][i] = estate;
		tempState->deckCount[0]++;
	}
for (i = 3; i < 6; i++)
	{
	  state->deck[0][i] = copper;
	  state->deckCount[0]++;		
	  tempState->deck[0][i] = copper;
	  tempState->deckCount[0]++;
	}

for (i = 6; i < 10; i++)
	{
		state->deck[0][i] = mine;
		state->deckCount[0]++;
		tempState->deck[0][i] = mine;
		tempState->deckCount[0]++;
	}

//shuffle() on state - tempstate remains unchanged to verify that state changes
shuffle(0, state);

//verify that at least one card is different in player 0's deck in state and tempstate
int matchcount = 0;

for (i = 0; i < 10; i++)
{
	if (state->deck[0][i] == tempState->deck[0][i])
	{matchcount++;
	}
}


if (matchcount == 10 )
	printf("shuffle(): TEST FAILED\n");
else
	printf("shuffle(): TEST SUCCESSFULLY COMPLETED\n");


return 0;
}