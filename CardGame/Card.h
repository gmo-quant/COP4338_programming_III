#ifndef CARD_H
#define CARD_H


// encode for representation of each suit
#define DIAMOND	0
#define CLUB	16
#define HEART	32
#define SPADE	48

#define DIAMOND_SYMBOL	"D"
#define	CLUB_SYMBOL		"C"
#define HEART_SYMBOL	"H"
#define SPADE_SYMBOL	"S"


#define SUIT_T 	4
#define RANK 	13

#define JACK 	11
#define QUEEN 	12
#define KING 	13
#define A 		1

// bitwise operation to determine the suit, rand and card
// mainly bitwise and
// each card is encoded by 6 bit,
// for example,  Diamond A will be 00 0001, 
// the first 2 bits, that is 00,  is suit bits
// the  last 4 bits, that is 0001,  is rank bits'
// the whole 6 bits, that is 00 0001, is the card bits
// that is in decimal Diamond A is 1
// use bitwise operation 'and' to decode its meaning 
#define SUITMASK	48	// use to get suit bit 
#define RANKMASK	15	// use to get rank bit
#define CARDMASK	63	// use to get card bit
	
#define SYMBL_STEP	16	// used in generateCard to create cards suit by suit
#define BLANK_CARD 	0


typedef char* SuitSymbolTf;
typedef char* RankSymbolTf;


// CardSymbolTf is an array 
// to store the string representation of a card
#define CardSymbolLEN 	10
typedef char CardSymbolTf[CardSymbolLEN];

unsigned generateCard(unsigned suit, unsigned rank);
unsigned getSuit(unsigned card); 	// get suit bits of a card
unsigned getRank(unsigned card);	// get rank bits of a card
SuitSymbolTf getSuitSymbol(unsigned suit); 
		// get the string representation of s suit
RankSymbolTf getRankSymbol(unsigned rank);
		// get the string representation of a rank
void getCardSymbol(unsigned card, CardSymbolTf cardSymbol);
		// get the string representation of a card
void displayCard(unsigned card);

void CardTester(); 	// for testing purpose when developing
					//

#endif