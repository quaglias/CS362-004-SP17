#include "dominion.h"
#include <assert.h>
#include <stdlib.h>

int main()
{
    printf (":::: BUY CARD UNIT TEST START ::::\n");
	
	struct gameState G;
  	int players = 2;
	int i = 0;
	int randseed = 3;
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, smithy, sea_hag, tribute};

  	initializeGame(players, k, randseed, &G);

	G.hand[0][0] = gold;

	buyCard(village, &G);
	printf("Cards in hand: %d \n",G.handCount[0]);
	printf("Cards in deck: %d \n",G.deckCount[0]);
	printf("Discard Cards: %d \n",G.discardCount[0]);

	while(G.hand[0][i] != NULL)
	{
		printf("%d | ",G.hand[0][i]);
		i++;
	}
	
    printf ("\n:::: BUY CARD UNIT TEST END ::::\n");
	return 0;
}
