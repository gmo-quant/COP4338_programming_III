#include"cardGame.h"

#include<stdio.h>	// to use printf

/*-------------------------generateCard-------------------------------
 *   function: unsigned generateCard(unsigned suit, unsigned rank)
 *
 *    Purpose: get the encoded representation of a card
 *
 * @param  suit  code, rank  code
 *
 * @return card  code
 *
 *---------------------------------------------------------------*/

unsigned generateCard(unsigned suit, unsigned rank){
	return suit + rank;	
}

/*-------------------------getSuitSymbol-------------------------------
 *   function: SuitSymbolTf getSuitSymbol(unsigned suit)
 *
 *    Purpose: get the string representation of suit
 *
 * @param  suit code
 *
 * @return string representation of suit
 *
 *---------------------------------------------------------------*/

SuitSymbolTf getSuitSymbol(unsigned suit){
	SuitSymbolTf suitSymbol[] = 
								{
									DIAMOND_SYMBOL, 
									CLUB_SYMBOL,
									HEART_SYMBOL,
									SPADE_SYMBOL 
								}; 
	int suitStep = 16; // for getting the index of suitsymbol
	return suitSymbol[suit/suitStep];
}


/*-------------------------getRankSymbol-------------------------------
 *   function: RankSymbolTf getRankSymbol(unsigned rank)
 *
 *    Purpose: get the string representation of rank 
 *
 * @param  rank code
 *
 * @return string representation of
 *
 *---------------------------------------------------------------*/

RankSymbolTf getRankSymbol(unsigned rank){

	RankSymbolTf rankSymbol[] = 
			{" ", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
	return rankSymbol[rank];
}


/*-------------------------getCardSymbol-------------------------------
 *   function: getCardSymbol(unsigned card, CardSymbolTf cardSymbol)
 *
 *    Purpose: get the string representation of a card
 *
 * @param  card code, and an CardSymbolTf array to store the 
 *					string representation of the card
 *
 * @return void, 
 *
 *---------------------------------------------------------------*/

void getCardSymbol(unsigned card, CardSymbolTf cardSymbol){
	unsigned suit = getSuit(card);
	unsigned rank = getRank(card);
	SuitSymbolTf suitSymbol = getSuitSymbol(suit);
	RankSymbolTf rankSymbol = getRankSymbol(rank);
	sprintf(cardSymbol, "[%s - %s]", suitSymbol , rankSymbol);
}

/*-------------------------getSuit-------------------------------
 *   function: unsigned getSuit(unsigned card)
 *
 *    Purpose: get the code of suit 
 * 				or get the suit bit as reference in Card.h
 *
 * @param  the code of a card
 *
 * @return suit bit of card
 *
 *---------------------------------------------------------------*/

unsigned getSuit(unsigned card){
	return card & SUITMASK;
}

/*------------------------getRank-------------------------------
 *   function: unsigned getRank(unsigned card)
 *
 *    Purpose: get the code of rank 
 * 				or get the rank bit as reference in Card.h
 * @param  the representation of a card
 *
 * @return the code of the rank of a card
 *
 *---------------------------------------------------------------*/
unsigned getRank(unsigned card){
	return card & RANKMASK;
}


/*------------------------ displayCard-------------------------------
 *   function: void displayCard(unsigned card)
 *
 *    Purpose: display the card
 *
 * @param  the code of a card
 *
 * @return void
 *
 *---------------------------------------------------------------*/
void displayCard(unsigned card){
	CardSymbolTf cardSymbol;
	getCardSymbol(card,cardSymbol);
	printf("%s", cardSymbol);

}


// for testing purpose when developing
void CardTester(){
	unsigned card = generateCard(0, 1);
	displayCard(card);
}
