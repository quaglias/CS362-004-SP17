#include "dominion.h"
#include "dominion_helpers.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "rngs.h"
#define MAX_TESTS 100
// Tests council room card
int main (int argc, char** argv) 
{
    printf (":::: COUNCIL ROOM RANDOM TESTER START ::::\n");

    srand(time(NULL));
	
	int i;
    int j = 0;
    int bad = 0;
    for( i = 0; i < MAX_TESTS; i++){
        int numplayers = rand() % (MAX_PLAYERS - 1) + 2; // Value between 2 and 4.
        j += numplayers;
        struct gameState G;
        int k[10] = {adventurer, gardens, embargo, village, steward, mine, cutpurse, sea_hag, tribute, smithy};

        initializeGame(numplayers, k, rand(), &G);

        int player = rand() % numplayers;
        G.whoseTurn = player;
        
        int bonus = rand() % 50;
        int choice1 = rand() % 50;
        int choice2 = rand() % 50;
        int choice3 = rand() % 50;
        int handPos = rand() % MAX_HAND;

        struct gameState orig;
        memcpy(&orig, &G, sizeof(struct gameState));

        cardEffect(council_room, choice1, choice2, choice3, &G, handPos, &bonus);

        for(int i = 0; i < numplayers; i++){
            if(i == player){
                if(G.handCount[i] != orig.handCount[i] + 3){
                    printf("TEST FAILED: Player %d didn't get 3 more cards.\n", i);
                    bad++;
                }
            }else{
                if(G.handCount[i] != orig.handCount[i] + 1){
                    printf("TEST FAILED: Player %d didn't draw 1 card.\n", i);
                    bad++;
                }
            }
        }
    }

    printf("%d of %d TESTS PASSED\n", j - bad, j);
	printf (":::: COUNCIL ROOM RANDOM TESTER END ::::\n");
}