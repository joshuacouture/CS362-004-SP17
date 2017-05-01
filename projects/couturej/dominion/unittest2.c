#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Unit Test for supplycount()

int main(){


//initialize standard game state with 2 players and random seed = 10
struct gameState* state = newGame();
int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
int seed = 10;
int players = 2;
initializeGame(players, k, seed, state);

//from dominion.c when there are 2 players supplyCount for estate, duchy, and provice should = 8:

      //state->supplyCount[estate] = 8;
      //state->supplyCount[duchy] = 8;
      //state->supplyCount[province] = 8;
	  //state->supplyCount[curse] = 10;
	  

if (supplyCount(estate, state) == 8 && supplyCount(duchy, state) == 8 && supplyCount(province, state) == 8 && supplyCount(curse, state) == 10)
	printf("supplycount(): TEST SUCCESSFULLY COMPLETED\n");
else
	printf("supplycount(): TEST FAILED\n"); 


//alternate form with specific failure message
/* if (supplyCount(estate, state) != 8)
{
	printf("supplyCount(): TEST FAILED - estate card count incorrect\n");
}
else if(supplyCount(province, state) != 8)
{
	printf("supplyCount(): TEST FAILED - province card count incorrect\n");
}
else if(supplyCount(duchy, state) != 8)
{
	printf("supplyCount(): TEST FAILED - duchy card count incorrect\n");
}
else if(supplyCount(curse, state) != 10)
{
	printf("supplyCount(): TEST FAILED - curse card count incorrect\n");
}
else
{
	printf("supplycount(): TEST SUCCESSFULLY COMPLETED\n"); 
}*/

return 0;
}