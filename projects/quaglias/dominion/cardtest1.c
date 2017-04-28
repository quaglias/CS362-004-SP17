#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <time.h>


int main (int argc, char** argv)
{
    // Setup
    struct gameState G;
    int choice1 = 0, choice2 = 0, choice3 = 0;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
	       sea_hag, tribute, smithy};

    printf (":::: ADVENTURER CARD TEST START ::::\n");

    // Start an instance
    initializeGame(2, k, 4, &G);

	printf("Test 1 of 1, Adventurer effect:\n");
    if (cardEffect(adventurer, choice1, choice2, choice3, &G, 0, NULL) == 0)
	{
      printf("Test 1 of 1, Passed\n\n");
    }
	else
	{
      printf("Test 1 of 1 FAILED!\n");
    }

    printf (":::: ADVENTURER CARD TEST END ::::\n");


}
