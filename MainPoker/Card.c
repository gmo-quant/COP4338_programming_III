#include"MainPoker.h"
#include<stdio.h> // used for printf("%s\n", );

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

Card generateCard(unsigned suit, unsigned rank){
	static SuitSymbolTf suitSymbol[] = 
		{
			DIAMOND_SYMBOL, 
			CLUB_SYMBOL,
			HEART_SYMBOL,
			SPADE_SYMBOL 
		}; 

	static RankSymbolTf rankSymbol[] = 
			{"", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

	return (Card) {suit, rank, suitSymbol[suit/SUITSTEP], rankSymbol[rank]};
}// generateCard() end

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
void displayCard(Card* const card){
	char str[12];
	sprintf(str, "[%s - %s]", card->rankSym, card->suitSym);
	printf("%10s", str);
}
