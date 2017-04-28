#include <stdio.h> // printf, puts
#include <stdlib.h> // rand, srand
#include <time.h> // time
#include "assert.h"
#include "dominion.h"

int main (int argc, char** argv)
{
    printf (":::: SALVAGER CARD TEST START ::::\n");

	srand(time(NULL)); // Seed rand

	/* Setup */
	int numPlayers = rand() % 3 + 2;
	int randomSeed = rand();
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	struct gameState G;

	/* initialize game */
	initializeGame(numPlayers, k, randomSeed, &G);

	G.hand[0][0] = salvager;
	int numBuysPrior = G.numBuys;
	int handCountPrior = numHandCards(&G);
	int actionCountPrior = G.numActions;

	int returnValue = playCard(0, 0, 0, 0, &G);
	assert(returnValue == 0);

	int numBuysPost = G.numBuys;
	int handCountPost = numHandCards(&G);
	int actionCountPost = G.numActions;

	printf("Test 1 of 3, + 1 'buy' added:\n");
    if (numBuysPost == (numBuysPrior + 1))
	{
      printf("Test 1 of 3, Passed\n\n");
    }
	else
	{
      printf("Test 1 of 3 FAILED!\n");
    }

	printf("Test 2 of 3, + 1 card & discard 'village':\n");
    if (handCountPost == (handCountPrior + 1))
	{
      printf("Test 2 of 3, Passed\n\n");
    }
	else
	{
      printf("Test 2 of 3 FAILED!\n");
    }

	printf("Test 3 of 3, + 2 'actions' & discard 'village':\n");
    if (actionCountPost == (actionCountPrior + 1))
	{
      printf("Test 3 of 3, Passed\n\n");
    }
	else
	{
      printf("Test 3 of 3 FAILED!\n");
    }

    printf (":::: SALVAGER CARD TEST END ::::\n");

	return 0;
}
