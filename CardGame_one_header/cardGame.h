/*
macro for cards
and function prototype for operating on cards
*/
// encode for representation of each suit
#define DIAMOND	0
#define CLUB	16
#define HEART	32
#define SPADE	48

// marcro of symbol for each suit
#define DIAMOND_SYMBOL	"D"
#define	CLUB_SYMBOL		"C"
#define HEART_SYMBOL	"H"
#define SPADE_SYMBOL	"S"

#define SUIT_T 	4	// number of suit type
#define RANK 	13	// number of rank

#define JACK 	11
#define QUEEN 	12
#define KING 	13
#define A 		1
/*
bitwise operation to determine the suit, rand and card
mainly bitwise and
each card is encoded by 6 bit,
for example,  Diamond A will be 00 0001, 
the first 2 bits, that is 00,  is suit bits
the  last 4 bits, that is 0001,  is rank bits'
the whole 6 bits, that is 00 0001, is the card bits
that is in decimal Diamond A is 1
use bitwise operation 'and' to decode its meaning 
*/
#define SUITMASK	48	// use to get suit bit 
#define RANKMASK	15	// use to get rank bit
#define CARDMASK	63	// use to get card bit
	
#define SYMBL_STEP	16	// used in generateCard to create cards suit by suit
#define BLANK_CARD 	0

#define CardSymbolLEN 	10
#define DECKSIZE	53
		// there are 52 cards in a deck, but we start from 1 instead of 0, 
		// so it is 53
/* 
	macro for a card game
*/
// #define RESET   "\033[0m"
// #define RED     "\033[31m" 
// #define YELLOW  "\033[33m" 

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#define MAX_PLAYERS	13
#define MIN_PLAYERS 1
#define MAX_CARD_PER_HAND	13
#define MIN_CARD_PER_HAND	1

#define ARG_AMT	3
#define ARG_CARD_PER_HAND 1
#define ARG_PLAYERS	2

#define MAX_RANK	13

typedef enum {TRUE = 1, FALSE = 0} boolean ;


typedef char* SuitSymbolTf;		// typedef a type to represent suit symbol
typedef char* RankSymbolTf;		// typedef a type to represent rank symbol
typedef char CardSymbolTf[CardSymbolLEN];
		// CardSymbolTf is an array 
		// to store the string representation of a card
typedef unsigned TfDeck[DECKSIZE] ;	
		// typedef an array for storing the repesentation a deck of cards

/*
	function prototype for operating on cards
*/
unsigned generateCard(unsigned suit, unsigned rank);
unsigned getSuit(unsigned card); 	
		// get suit bits of a card
unsigned getRank(unsigned card);	
		// get rank bits of a card
SuitSymbolTf getSuitSymbol(unsigned suit); 
		// get the string representation of s suit
RankSymbolTf getRankSymbol(unsigned rank);
		// get the string representation of a rank
void getCardSymbol(unsigned card, CardSymbolTf cardSymbol);
		// get the string representation of a card
void displayCard(unsigned card);
/*
	 function prototype for operating on a deck of card
*/
void generateDeck(TfDeck deck);
void displayDeck(char* prompt, TfDeck deck);
void shuffleDeck(TfDeck deck);
void swap(unsigned * cardA, unsigned * cardB); 
		// helper function in shuffleDeck()
// validate the players amount and cardsperhand from the cmd arg
boolean validation(int argc, char* argv[]);
void dealer(TfDeck deck, unsigned * playerArray, int players, int cardsPerHand);
void displayHands(unsigned * playerArray, int players, int cardsPerHand);
void displaySymbolExplaination();
