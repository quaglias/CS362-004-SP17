#include <stdio.h> // printf, puts
#include <stdlib.h> // rand, srand
#include <time.h> // time
#include <assert.h>
#include "dominion.h"

int assurancesFailed = 0;

inline void _assure(const char* expression, const char* file, int line) {
	assurancesFailed++;
	printf("Assertion failed: {%s}, file %s, line %d.\n", expression, file, line);
}

void testStatus() {
	if (!assurancesFailed) puts("[Test passes]");
	else printf("[Test failed] (%d assertions failed)\n", assurancesFailed);
}

int main (int argc, char** argv) {
	puts("Testing initializeGame()...");

	srand(time(NULL)); // Seed rand function
	/* Prepare arguments for initializeGame */
	int numPlayers = rand() % 3 + 2;
	int randomSeed = rand();
	int k[10] = {adventurer, gardens, embargo, village, minion,
							 mine, cutpurse, sea_hag, tribute, smithy};
	struct gameState G;

	/* Run initializeGame function */
	int returnValue = initializeGame(numPlayers, k, randomSeed, &G);

	// assert initializeGame did not return error
	assert(returnValue == 0);
	// assert correct number of players
	assert(numPlayers == G.numPlayers);
	// Verify correct card supplies
	if (numPlayers == 2) {
		assert(G.supplyCount[curse] == 10);
		assert(G.supplyCount[estate] == 8);
		assert(G.supplyCount[duchy] == 8);
		assert(G.supplyCount[province] == 8);
	} else if (numPlayers == 3) assert(G.supplyCount[curse] == 20);
	else {
		assert(G.supplyCount[curse] == 30);
		assert(G.supplyCount[estate] == 12);
		assert(G.supplyCount[duchy] == 12);
		assert(G.supplyCount[province] == 12);
	}
	assert(G.supplyCount[copper] == 60-(7*numPlayers));
	assert(G.supplyCount[silver] == 40);
	assert(G.supplyCount[gold] == 30);

	testStatus();

	return 0;
}
