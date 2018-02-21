
// encode for each suit
// 
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

#define DIAMOND_SYMBL	(wint_t)25C7
#define	CLUB_SYMBOL		(wint_t)2663
#define HEART_SYMBOL	(wint_t)2661
#define SPADE_SYMBOL	(wint_t)2664


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

// there are 52 cards in a deck, but we start from 1 instead of 0, 
// so it is 53
#define DECKSIZE	53

#define SYMBL_INIT 	0	
#define SYMBL_STEP	16

#define BLANK_CARD 	0


typedef unsigned TfDeck[DECKSIZE] ;
