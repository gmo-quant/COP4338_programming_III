#include"Card.h"

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
	switch(suit){
		case DIAMOND: 
			return DIAMOND_SYMBOL;
			break;
		case CLUB:
			return CLUB_SYMBOL;
			break;
		case HEART:
			return HEART_SYMBOL;
			break;
		case SPADE: 
			return SPADE_SYMBOL;
			break;
		default:
			return NULL;
		}
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

	switch(rank){
		case A: 
			return "A";
			break;
		case 2:
			return "2";
			break;
		case 3:
			return "3";
			break;
		case 4: 
			return "4";
			break;
		case 5:
			return "5";
			break;
		case 6:
			return "6";
			break;
		case 7: 
			return "7";
			break;
		case 8:
			return "8";
			break;
		case 9:
			return "9";
			break;
		case 10: 
			return "10";
			break;
		case JACK:
			return "J";
			break;
		case QUEEN:
			return "Q";
			break;
		case KING:
			return "K";
			break;
		default:
			return NULL;
	}
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
