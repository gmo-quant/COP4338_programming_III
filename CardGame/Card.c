#include"Card.h"
/*-------------------------getSuit-------------------------------
 *   function: unsigned getSuit(unsigned card)
 *
 *    Purpose: get the code of suit 
 *
 * @param  the representation of a card
 *
 * @return the code of the rank of a card
 *
 *---------------------------------------------------------------*/

SuitSymbolTf getSuitSymbol(unsigned card){
	SymbolTf suitSymbol = DIAMOND_SYMBOL;
	
	if(DIAMOND == suit){
		*suitSymbol = DIAMOND_SYMBOL;
	}else if(CLUB == suit){
		*suitSymbol = CLUB_SYMBOL;
	}else if(HEART == suit){
		*suitSymbol = HEART_SYMBOL;
	}else if(SPADE == suit){
		*suitSymbol = SPADE_SYMBOL;
	}
	return suit;
}

RankSymbolTf getRankSymbol(unsigned rank){
	RankSymbolTf rankSymbol = NULL;
	itoa(rank, rankSymbol, 10 );
	return rankSymbol;
}
/*-------------------------getSuit-------------------------------
 *   function: unsigned getSuit(unsigned card)
 *
 *    Purpose: get the code of suit 
 *
 * @param  the representation of a card
 *
 * @return the code of the rank of a card
 *
 *---------------------------------------------------------------*/

unsigned getSuit(unsigned card){
	return card & SUITMASK;
}

/*------------------------getRank-------------------------------
 *   function: unsigned getRank(unsigned card)
 *
 *    Purpose: get the code of rank
 *
 * @param  the representation of a card
 *
 * @return the code of the rank of a card
 *
 *---------------------------------------------------------------*/
unsigned getRank(unsigned card){
	return card & RANKMASK;
}

/*------------------------ decodeCard-------------------------------
 *   function: void decodeCard(unsigned card, 
 *							SymbolTf * suitSymbol, unsigned * rank)
 *
 *    Purpose: decode the card code
 *
 * @param  	card code, input for decode
 *			suitSymbol pointer, store the decoded suit symbol
 *			rank pointer, store the decoded rank 
 *
 * @return void
 *
 *---------------------------------------------------------------*/

void encodeCard(unsigned card, SymbolTf * suitSymbol, unsigned * rank){
	// determine the suit symbol
	SymbolTf suit = getSuit(card);
	// determin the card rank
	int rankVal = getRank(card);
	// encode the rank into string
	itoa(rankVal, rank, 10);
}

/*------------------------ displayCard-------------------------------
 *   function: void displayCard(unsigned card)
 *
 *    Purpose: display the card
 *
 * @param  the representation of a card
 *
 * @return void
 *
 *---------------------------------------------------------------*/
void displayCard(unsigned card){
	SymbolTf suitSymbol;
	char* rank;
	encodeCard(card, &suitSymbol, &rank );
	// form a string for presenting a card
	char * cardRep = "[ %s - %s ]";
	printf(cardRep, suitSymbol, rank);
}

