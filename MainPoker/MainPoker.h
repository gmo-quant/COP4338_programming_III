#ifndef MainPoker_h
#define MainPoker_h

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
#define SUITSTEP 	16

typedef char* SuitSymbolTf;
typedef char* RankSymbolTf;

// CardSymbolTf is an array 
// to store the string representation of a card
#define CardSymbolLEN 	10
typedef char CardSymbolTf[CardSymbolLEN];

typedef struct Card{
	unsigned suit;
	unsigned rank;
	SuitSymbolTf suitSym;
	RankSymbolTf rankSym;
} Card ;

// there are 52 cards in a deck, but we start from 1 instead of 0, 
// so it is 53
#define DECKSIZE	53
// typedef an array for storing the repesentation a deck of cards
typedef Card TfDeck[DECKSIZE] ;

Card generateCard(unsigned suit, unsigned rank);
void displayCard(Card* const card);
void cardTester(); // for testing purpose only, when developing.
void generateDeck(TfDeck deck);
void displayDeck(char* prompt, TfDeck deck);
void shuffleDeck(TfDeck deck);
void swap(Card * cardA, Card * cardB); // helper function in shuffleDeck()

void DeckTester(); 	// for testing purpose when developing Deck.c

#define RESET   "\033[0m"
#define RED     "\033[31m" 
#define YELLOW  "\033[33m" 

#define ARG_AMT	3
#define ARG_PLAYERS	2
#define ARG_CARD_PER_HAND 1



typedef enum {TRUE = 1, FALSE = 0} boolean ;

#define CARD_PER_HAND 	5
#define MIN_PLAYER_AMT 	1
#define MAX_PLAYER_AMT	7

typedef Card Hand[CARD_PER_HAND];

boolean validation(const int argc, char* const argv[]);
boolean validPlayerAmt(const int playerAmt);
boolean validCardsPerHand(const int cardPerHand );
void dealer(TfDeck deck, Hand* playerArray, int players);
void sortHandsByRank(Hand* playerArray, int amtPlayers);
void sortHandByRank(Hand hand);
void Gswap(Card* card1, Card * card2);

void displayHands(Hand* playerArray, int players, int type);
void displayHand(Hand hand);
void displayRanked(Hand hand);


boolean straightFlush(Hand hand);
boolean fourOfAKind(Hand hand);
boolean fullHouse(Hand hand);
boolean flush(Hand hand);
boolean straight(Hand hand);
boolean threeOfAKind(Hand hand);
boolean twoPair(Hand hand);
boolean onePair(Hand hand);
boolean highCard(Hand hand);


void ranker(Hand* playerArray, int playerAmt);
char *  rankJudge(Hand hand);

void PokerGameTester(const int argc, char* const argv[]);
void PokerRankTester();



#define DEALT	0
#define SORTED	1
#define RANKED 	2
#define WINNER	3

void dealt(Hand hand);
void sorted(Hand hand);
void 
#endif