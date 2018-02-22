#include"Deck.h"

#include<stdio.h>
#include<stdlib.h>
#

void generateDeck(TfDeck deck){
	// initialize cards of a deck to be blank, 
	// fill in 0;
	int i = 0;
	for (i = 0; i < DECKSIZE; i++){
		deck[i] = BLANK_CARD;
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
}

void displayDeck(TfDeck deck){
	unsigned card = BLANK_CARD;
	int counter = 1;
	for (counter = 1; counter < DECKSIZE; counter++){
		card = deck[counter];
		displayCard(card);
		if ( (counter % 13) == 0){
			printf("\n");
		}
	}	
	printf("\n");
}


// void shuffeDeck(TfDeck deck){

// 	srand(time(null));
// 	int start = DECKSIZE -1;
// 	int j = 0;
// 	for (start = DECKSIZE-1; start > 1; start--){

// 	}
// 	// generate random integer between 0 and i
// }
void DeckTester(){
	TfDeck deck;
	generateDeck(deck);
	displayDeck(deck);
}