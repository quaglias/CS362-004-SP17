#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <assert.h>
#include "dominion.h"


int main (int argc, char** argv) 
{
    printf (":::: INITIALIZE GAME UNIT TEST START ::::\n");

	//Setup
	srand(time(NULL)); 
	int numPlayers = rand() % 3 + 2;
	int randomSeed = rand();
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	struct gameState G;

	/*initialize Game */
	int returnValue = initializeGame(numPlayers, k, randomSeed, &G);

	// assert initializeGame did not return error
	printf("Test 1 of 6, No errors on initialization assertion:\n");
	if( returnValue == 0)
	{
		printf("Test 1 of 6 Passed\n\n");		
	}
	else
	{
		printf("Test 1 of 6 Failed\n\n");
	}	
	
	// assert correct number of players
	printf("Test 2 of 6, Correct player amount assertion:\n");
	if( numPlayers == G.numPlayers)
	{
		printf("Test 2 of 6 Passed\n\n");		
	}
	else
	{
		printf("Test 2 of 6 Failed\n\n");
	}	
	
	// Verify correct card supplies
	printf("Test 3 of 6, Correct card amounts for 2 players (non-treasure) assertion:\n");
	if( numPlayers == 2 && G.supplyCount[curse] == 10 && G.supplyCount[estate] == 8 && G.supplyCount[duchy] == 8 && G.supplyCount[province] == 8)
	{
		printf("Test 3 of 6 Passed\n\n");		
	}
	else
	{
		printf("Test 3 of 6 Failed\n\n");
	}
	
	printf("Test 4 of 6, Correct card amounts for 3 players (non-treasure) assertion:\n");
	if( numPlayers == 3 && G.supplyCount[curse] == 20 && G.supplyCount[estate] == 8 && G.supplyCount[duchy] == 8 && G.supplyCount[province] == 8)
	{
		printf("Test 4 of 6 Passed\n\n");		
	}
	else
	{
		printf("Test 4 of 6 Failed\n\n");
	}
	
	printf("Test 5 of 6, Correct card amounts for 4 to 6 players (non-treasure) assertion:\n");
	if( numPlayers > 3 && numPlayers < 7 && G.supplyCount[curse] == 30 && G.supplyCount[estate] == 12 && G.supplyCount[duchy] == 12 && G.supplyCount[province] == 12)
	{
		printf("Test 5 of 6 Passed\n\n");		
	}
	else
	{
		printf("Test 5 of 6 Failed\n\n");
	}	

	printf("Test 6 of 6, Correct treasure card amounts assertion:\n");
	if( G.supplyCount[copper] == (60-(7*numPlayers)) && G.supplyCount[silver] == 40 && G.supplyCount[gold] == 30)
	{
		printf("Test 6 of 6 Passed\n\n");		
	}
	else
	{
		printf("Test 6 of 6 Failed\n\n");
	}	

    printf (":::: INITIALIZE GAME UNIT TEST END ::::\n");	

	return 0;
}
