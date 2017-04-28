#include "dominion_helpers.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	// Setup
	struct gameState G;
	int bonus = 0;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, steward, tribute, smithy};

    printf (":::: SMITHY CARD TEST START ::::\n");

	/* Initialize game */
	int r = initializeGame(2, k, 205, &G);

	G.hand[0][0] = village;
	G.hand[0][1] = copper;
	G.hand[0][2] = silver;
	G.hand[0][3] = copper;
	G.hand[0][4] = silver;

	int test_handCount = G.handCount[0];

	printf("Test 1 of 1, + 3 cards current player\n");

	cardEffect(smithy, 1, 2, 3, &G, 0, &bonus);

	if( test_handCount+2 == G.handCount[0])
	{
		printf("Test 1 of 1 Passed\n\n");
	}
	else
	{
		printf("Test 1 of 1 Failed\n\n");
	}

    printf (":::: SMITHY CARD TEST END ::::\n");
	return 0;
}
