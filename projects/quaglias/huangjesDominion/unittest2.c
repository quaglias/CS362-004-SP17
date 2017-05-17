#include "assert.h"
#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int getCost(int);

int main(int argc, char ** argv)
{
	//Setup
	struct gameState G;
	int result, value, rando = 0;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy};
	rando = rand() % 10;
	
	// Initialize game
	result = initializeGame(2, k, rando, &G);

	assert(result == 0);
    printf (":::: GET COST UNIT TEST START ::::\n");

	printf("Test 1 of 3, Negative value assertion:\n");
	value = -1;
	result = getCost(value);

	if( value == result )
	{
		printf("Test 1 of 3 Passed\n\n");		
	}
	else
	{
		printf("Test 1 of 3 Failed\n\n");
	}	
	
	printf("Test 2 of 3, '1' value assertion:\n");
	value = 1;
	result = getCost(value);
	
	if( value == result )
	{
		printf("Test 2 of 3 Passed\n\n");		
	}
	else
	{
		printf("Test 2 of 3 Failed\n\n");
	}	
	
	printf("Test 3 of 3, '2' value assertion:\n");
	value = 2;
	result = getCost(value);
	
	if( value == result )
	{
		printf("Test 3 of 3 Passed\n\n");		
	}
	else
	{
		printf("Test 3 of 3 Failed\n\n");
	}	

    printf (":::: GET COST UNIT TEST END ::::\n");
	return 0;
}
