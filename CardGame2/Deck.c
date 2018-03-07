#include"Deck.h"

void createDeck(TfDeck deck){
	// initialize cards of a deck to be blank, 
	// fill in 0;
	int i = 0;
	for (i = 0; i < DECKSIZE; i++){
		deck[i] = 0;
	}

	unsigned suit_symbol = SYMBL_INIT;
	unsigned suit = DIAMOND; // counter for suit;
	unsigned rank = 1; // counter for rank;
	unsigned suitStartLoc = DIAMOND; // the starting location of a new suit

	for (suit = DIAMOND; suit < SUIT_T; suit++){
		suitStartLoc = suit * RANK;
		
		for (rank = 1; rank <= RANK; rank++){
			deck[suitStartLoc + rank ] = suit_symbol + rank;
		}
		suit_symbol += SYMBL_STEP;
	}
}

void displayDeck(TfDeck deck){
	unsigned suit_symbol = SYMBL_INIT;
	int suit = 0;
	int rank = 1;
	unsigned card = BLANK_CARD;
	unsigned suitStartLoc = DIAMOND; // the starting location of a new suit
	for (suit = DIAMOND; suit < SUIT_T; suit++){
		suitStartLoc = suit * RANK;
		printf("\n");
		for (rank = 1; rank <= RANK; rank++){
			card = deck[suitStartLoc + rank];
			printf("%4u," , card);
		}
printf("\n");
printf("\n");
		for (rank = 1; rank <= RANK; rank++){
			card = deck[suitStartLoc + rank];

			printf("%4u, %4u; %4lc " , getSuit(card), getRank(card), HEART_SYMBOL);
		}
		printf("\n");
		suit_symbol += SYMBL_STEP;
	}
}