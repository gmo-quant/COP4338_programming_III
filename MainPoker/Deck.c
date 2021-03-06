#include"MainPoker.h"
#include<stdio.h> // used for printf("%s\n", );
#include<time.h> // used for rand() to create randomNum
#include<stdlib.h> //

/*-------------------------generateDeck-------------------------------
 *   function: generateDeck(TfDeck deck)
 *
 *    Purpose: generate a deck of card
 *
 * @param  a TfDeck array to store the deck of card generated
 *
 * @return void
 *
 *---------------------------------------------------------------*/
void generateDeck(TfDeck deck){
	unsigned suitArray[SUIT_T] = {DIAMOND, CLUB, HEART, SPADE};
	unsigned suit = DIAMOND; // counter for suit;
	unsigned rank = A; // counter for rank;
	unsigned suitStartLoc = DIAMOND; // the starting location of a new suit

	for (suit = DIAMOND; suit < SUIT_T; suit++){
		suitStartLoc = suit * RANK;
		for (rank = 1; rank <= RANK; rank++){
			deck[suitStartLoc + rank ] = generateCard(suitArray[suit], rank);
		}
	}
}// generateDeck() end

/*-------------------------displayDeck-------------------------------
 *   function: displayDeck(char* prompt, TfDeck deck)
 *
 *    Purpose: generate a deck of card
 *
 * @param  a TfDeck array to store the deck of card generated
 *
 * @return void
 *
 *---------------------------------------------------------------*/
void displayDeck(char* prompt, TfDeck deck){
	int counter = 1;
	printf("%s\n", prompt);
	for (counter = 1; counter < DECKSIZE; counter++){
		// card = deck[counter];
		displayCard(&deck[counter]);
		printf(", ");
		if ( (counter % MAX_RANK) == 0){
			printf("\n");
			printf("\n");
		}
	}	
	printf("\n");
}// displayDeck() end

/*-------------------------shuffleDeck-------------------------------
 *   function: shuffleDeck(TfDeck deck)
 *
 *    Purpose: sheffle the deck of cards
 *
 * @param  the deck generated
 *
 * @return void
 *
 *---------------------------------------------------------------*/
void shuffleDeck(TfDeck deck){
	int upperBound = DECKSIZE -1;
	int randomNum = 0;
	int lowerBound = 1;
	srand(time(NULL));
	for (upperBound = DECKSIZE -1; upperBound > 1; upperBound--){
		randomNum = (rand() + lowerBound ) % upperBound +1;
		swap(&deck[upperBound], &deck[randomNum]);
	}
}// sheffleDeck() end


/*-------------------------swap-------------------------------
 *   function: swap(unsigned * cardA, unsigned * cardB)
 *
 *    Purpose: helper function to swap two cards to implement 
 *				the shuffleDeck()
 *
 * @param  cardA and cardB to be swapped
 *
 * @return void
 *
 *---------------------------------------------------------------*/
void swap(Card * cardA, Card * cardB){
	Card tmp = *cardA;
	*cardA = *cardB;
	*cardB = tmp;
}
