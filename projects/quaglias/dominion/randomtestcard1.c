#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_TEST 500

int main()
{
	struct gameState G;
	int result;
	int random = 0;
	int player = 1;
	int handCount;
	int deckCount;
	int passed = 0;
	int failed = 0;
	int i;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,	sea_hag, tribute, smithy};
	
    printf (":::: SALVAGER RANDOM TESTER START ::::\n");
	

	for(i = 0; i < MAX_TEST; i++)
	{
		//set basic information
		printf("Try #%d: \n", i);
		int numPlayers = rand() % 4;
		int gameSeed = rand() % 5000;

		//initializes gameState
		initializeGame(numPlayers, k, gameSeed, &G);

		random = rand() % 10;
		
		if(random == 5)
		{
			G.deckCount[player] = 0;
			deckCount = 0;
		}
		else
		{
			random = rand() % MAX_DECK;
			G.deckCount[player] = random;
			deckCount = random;
		}

		random = rand() % MAX_DECK;
		G.handCount[player] = rand() % MAX_HAND;
		handCount = random;

		G.discardCount[player] = rand() % MAX_DECK;

		result = Salvager(&G, player, 1, 1);
		
		if(result == 0)
		{
			printf("Test #%d Passed\n", i);
			passed++;
		}
		else
		{
			printf("Test #%d Failed\n", i);
			failed++;
		}
	}

	printf (":::: SALVAGER RANDOM TESTER END ::::\n");
}
