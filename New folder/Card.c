#include<stdio.h>
#include<stdlib.h>
#include<wchar.h>

#include"Card.h"


/*-------------------------createDeck()-------------------------------
 *   function: createDeck()
 *
 *    Purpose: create a new Deck of cards, there 
 *
 * @param 
 *
 * @return TfDeck a 1-d array of size DECKSIZE 
 *
 *---------------------------------------------------------------*/



unsigned getSuit(unsigned card){
	unsigned suit = DIAMOND;
	suit = card & SUITMASK;
	return suit;
}

unsigned getRank(unsigned card){
	unsigned rank = A;
	rank = card & RANKMASK;
	return rank;
}

