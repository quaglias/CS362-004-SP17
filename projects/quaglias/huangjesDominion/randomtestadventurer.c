#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define MAX_TESTS 100

int main()
{
    printf (":::: ADVENTURER RANDOM TESTER START ::::\n");

	struct gameState G;
  	int players1;
  	int players2;
  	int random_seed;
  	int pre_handCount = 0;
  	int post_handCount = 0;
  	int card = 0;
  	int i = 0;
  	int j = 0;
  	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, smithy, sea_hag, tribute};

    for(i = 0; i < MAX_TESTS; i++)
    {
        //Initialize variables
        players1 = rand() % 4;
        players2 = rand() % 4;
        random_seed = rand();

        initializeGame(players1, k, random_seed, &G);

        //Initialize game state information
        G.deckCount[players2] = rand() % MAX_DECK;
        G.discardCount[players2] =  rand() % MAX_DECK;
        G.handCount[players2] =  rand() % MAX_HAND;

        G.hand[players2][0] = adventurer;

        for(j = 1; j < G.handCount[players2]; j++)
        {
            card = rand() % treasure_map;
            if(G.supplyCount[card] > -1)
            {
                G.hand[players2][j] = card;
            }
        }

        for(j = 0; j < G.deckCount[players2]; j++)
        {
            card = rand() % treasure_map;
            if(G.supplyCount[card] > -1)
            {
                G.deck[players2][j] = card;
            }
        }

        pre_handCount = G.handCount[players2];


        playCard(0,0,0,0, &G);  //Call adventurer

        post_handCount = G.handCount[players2];

        printf ("handCount prior: %d\n", pre_handCount);
        printf ("handCount after: %d\n", post_handCount);

        if(pre_handCount == post_handCount)
        {
            printf("handCount prior and handCount post are equal, test passed.\n");
        }
        else
        {
            printf("handCount prior and handCount post are not equal, test failed.\n");
        }



    }
    printf (":::: ADVENTURER RANDOM TESTER END ::::\n");
	return 0;
}
