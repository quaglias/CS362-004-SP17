#include "dominion_helpers.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{

	struct gameState G;
	int bonus = 0;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, steward, tribute, smithy};

    printf (":::: COUNCIL ROOM CARD TEST START ::::\n");
	
	int r = initializeGame(3, k, 205, &G);

	G.hand[0][0] = village;
	G.hand[0][1] = silver;
	G.hand[0][2] = silver;
	G.hand[0][3] = silver;
	G.hand[0][4] = silver;

	G.hand[1][0] = gold;
	G.hand[1][1] = gold;
	G.hand[1][2] = gold;
	G.hand[1][3] = gold;
	G.hand[1][4] = gold;

	G.hand[2][0] = copper;
	G.hand[2][1] = copper;
	G.hand[2][2] = copper;
	G.hand[2][3] = copper;
	G.hand[2][4] = copper;

	int test_buy = G.numBuys;
	int test_hand1 = G.handCount[0];
	int test_hand2 = G.handCount[1];
	int test_hand3 = G.handCount[2];

	printf("Test 1 of 3, Main hand + 4 cards:\n");
	cardEffect(council_room, 1, 2, 3, &G, 0, &bonus);
	
	if( test_hand1+3 == G.handCount[0] )
	{
		printf("Test 1 of 3 Passed\n\n");		
	}
	else
	{
		printf("Test 1 of 3 Failed\n\n");
	}	

	printf("Test 2 of 3, One 'buy' is added:\n");
	
	if( test_buy+1 == G.numBuys )
	{
		printf("Test 2 of 3 Passed\n\n");
	}
	else
	{
		printf("Test 2 of 3 Failed\n\n");
	}
		
	printf("Test 3 of 3, Other players hand are given +1 card:\n");
	
	if(( test_hand2+1 == G.handCount[1] ) && ( test_hand3+1 == G.handCount[2] ))
	{
		printf("Test 3 of 3 Passed\n\n");
	}
	else
	{
		printf("Test 3 of 3 Failed\n\n");
	}

    printf (":::: COUNCIL ROOM CARD TEST END ::::\n");

	assert(r == 0);
	return 0;
}
