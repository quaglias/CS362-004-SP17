#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main(int argc, char ** argv)
{
	//setup
	struct gameState G;
	int result, rando = 0;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy};
	rando = rand() % 10;
	
	//initialize Game
	result = initializeGame(2, k, rando, &G);
	assert(result == 0);
    printf (":::: SHUFFLE UNIT TEST START ::::\n");

	printf("Test 1 of 2, Negative deck assertion:\n");
	G.deckCount[1] = -10;
	result = shuffle(1, &G);
	
	if( result < 0)
	{
		printf("Test 1 of 2 Passed\n\n");		
	}
	else
	{
		printf("Test 1 of 2 Failed\n\n");
	}	
	
	printf("Test 1 of 2, Valid deck assertion:\n");
	G.deckCount[1] = 3;
	result = shuffle(1, &G);

	if( result >= 0 && result <= 3)
	{
		printf("Test 1 of 2 Passed\n\n");		
	}
	else
	{
		printf("Test 1 of 2 Failed\n\n");
	}	

    printf (":::: SHUFFLE UNIT TEST END ::::\n");
	return 0;
}
