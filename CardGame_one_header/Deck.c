#include"cardGame.h"

#include<stdio.h> 	// to use printf,
#include<stdlib.h>	// to use srand and rand to generate random number
					// when shuffling the deck
#include<time.h>	// to use srand and rand to generate random number
					// when shuffling the deck


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
	// initialize cards of a deck to be blank, 
	// fill in 0;
	int idx_card = 0;
	for (idx_card = 0; idx_card < DECKSIZE; idx_card++){
		deck[idx_card] = BLANK_CARD;
	}

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
	unsigned card = BLANK_CARD;
	int counter = 1;
	printf("%s\n", prompt);
	for (counter = 1; counter < DECKSIZE; counter++){
		card = deck[counter];
		displayCard(card);
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
void swap(unsigned * cardA, unsigned * cardB){
	unsigned tmp = *cardA;
	*cardA = *cardB;
	*cardB = tmp;
}// swap() end
