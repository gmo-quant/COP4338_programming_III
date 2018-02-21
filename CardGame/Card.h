#include<stdio.h>
#include<stdlib.h>
#include<wchar.h>
// encode for representation of each suit
#define DIAMOND	0
#define CLUB	16
#define HEART	32
#define SPADE	48



/*
Linux systems typically use UTF-8 encoding, in which:

♠ = U+2660 = "\xE2\x99\xA0"
♣ = U+2663 = "\xE2\x99\xA3"
♥ = U+2665 = "\xE2\x99\xA5"
♦ = U+2666 = "\xE2\x99\xA6"

*/

// #define DIAMOND_SYMBOL	'\u25C7'
// #define	CLUB_SYMBOL		'\u2663'
// #define HEART_SYMBOL	'\u2661'
// #define SPADE_SYMBOL	'\u2664'


#define DIAMOND_SYMBOL	"Diamond"
#define	CLUB_SYMBOL		"Club"
#define HEART_SYMBOL	"Heart"
#define SPADE_SYMBOL	"Spade"

/*
#define DIAMOND_SYMBL	"\xE2\x99\xA0"
#define	CLUB_SYMBOL		"\xE2\x99\xA3"
#define HEART_SYMBOL	"\xE2\x99\xA5"
#define SPADE_SYMBOL	"\xE2\x99\xA6"
*/
/*
#define SPADE   "\xE2\x99\xA0"
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"

*/
#define SUIT_T 	4
#define RANK 	13

#define JACK 	11
#define QUEEN 	12
#define KING 	13
#define A 		1

// bitwise operation to determine the suit, rand and card
// mainly bitwise and
#define SUITMASK	48
#define RANKMASK	15
#define CARDMASK	63

#define SYMBL_INIT 	0	
#define SYMBL_STEP	16
#define BLANK_CARD 	0

typedef char* SuitSymbolTf;
typedef char* RankSymbolTf;

unsigned getSuit(unsigned card);
unsigned getRank(unsigned card);
SuitSymbolTf getSuitSymbol(unsigned suit);
RankSymbolTf getRankSymbol(unsigned rank);
void encodeCard(unsigned card, SymbolTf * suitSymbol, char* rank);
void displayCard(unsigned card);