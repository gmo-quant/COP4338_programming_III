#include"Card.h"
#include<stdio.h>
#include<stdlib.h>
#include<wchar.h>
// there are 52 cards in a deck, but we start from 1 instead of 0, 
// so it is 53
#define DECKSIZE	53
// typedef a a array for repesenting a deck of card 
typedef unsigned TfDeck[DECKSIZE] ;
void createDeck(TfDeck deck);
void displayDeck(TfDeck deck);