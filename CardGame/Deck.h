#ifndef	DECK_H
#define DECK_H

#include"Card.h" 	// to create a deck and deal with a deck of card, 
					// need the MACRO and function provided of Card.c and Card.h

// there are 52 cards in a deck, but we start from 1 instead of 0, 
// so it is 53
#define DECKSIZE	53
// typedef an array for storing the repesentation a deck of cards
typedef unsigned TfDeck[DECKSIZE] ;

void generateDeck(TfDeck deck);
void displayDeck(char* prompt, TfDeck deck);
void shuffleDeck(TfDeck deck);
void swap(unsigned * cardA, unsigned * cardB); // helper function in shuffleDeck()

void DeckTester(); 	// for testing purpose when developing Deck.c

#endif