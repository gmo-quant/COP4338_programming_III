#ifndef MainPoker_h
#define MainPoker_h


/*
	declarations of functionalities of Card.c
*/

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

#define CardSymbolLEN 	10
typedef char* SuitSymbolTf;
typedef char* RankSymbolTf;
typedef char CardSymbolTf[CardSymbolLEN]; 
							// CardSymbolTf is an array 
							// to store the string representation of a card
typedef struct Card{
	unsigned suit; // use numbers to represent the suit, make it easy for comparison
	unsigned rank; // same reason as suit.
	SuitSymbolTf suitSym; // non-number representation of suit
	RankSymbolTf rankSym; // non-number representation of rank
} Card ; 



Card generateCard(unsigned suit, unsigned rank);
void displayCard(Card* const card);

/*
	declarations of functionalities of Deck.c
*/

// there are 52 cards in a deck, but we start from 1 instead of 0, 
// so it is 53
#define DECKSIZE	53
// typedef an array for storing the repesentation of a deck of cards
typedef Card TfDeck[DECKSIZE] ;

void generateDeck(TfDeck deck);
void displayDeck(char* prompt, TfDeck deck);
void shuffleDeck(TfDeck deck);
void swap(Card * cardA, Card * cardB); // helper function in shuffleDeck()

/*
	declarations of functionalities of PokerGame.c
*/

// color the output 
#define RESET   "\033[0m"
#define RED     "\033[31m" 
#define YELLOW  "\033[33m" 
#define BUFF_LEN 256
// macro for cmd arg
#define ARG_AMT	3
#define ARG_PLAYERS	2
#define ARG_CARD_PER_HAND 1

#define CARD_PER_HAND 	5
#define MIN_PLAYER_AMT 	1
#define MAX_PLAYER_AMT	7
// macro for selection of display method
#define DEALT	0
#define SORTED	1
#define RANKED 	2
#define WINNER	3
#define TEST 	4
// macro for kind of hand
#define STRAIGHT_FLUSH	"Straight Flush"
#define FOUR_KIND	"Four of a Kind"
#define FULL_HOUSE	"Full House"
#define FLUSH 		"Flush"
#define	STRAIGHT 	"Straight"
#define THREE_kIND	"Three of a Kind"
#define	TWO_PAIR	"Two Pair"
#define	ONE_PAIR	"One  Pair"
#define	HIGH_CARD	"High Card"
// Macro for the index of the array of kind of hand
#define IDX_STRAIGHT_FLUSH	0
#define IDX_FOUR_KIND	1
#define IDX_FULL_HOUSE	2
#define IDX_FLUSH 		3
#define	IDX_STRAIGHT 	4
#define IDX_THREE_kIND	5
#define	IDX_TWO_PAIR	6
#define	IDX_ONE_PAIR	7
#define	IDX_HIGH_CARD	8

#define TYPE_OF_HANDS	9

// macro for determining the winner using bit operations
#define WIN 1
#define LOSS 0
#define WINNER_MASK 1

typedef enum {TRUE = 1, FALSE = 0} boolean ;
typedef Card Hand[CARD_PER_HAND];

boolean validation(const int argc, char* const argv[]); // validate the cmd arg
boolean validPlayerAmt(const int playerAmt); // validate the amount of player in a game
boolean validCardsPerHand(const int cardPerHand ); // validate the amount of cards 
										//for each hand required by the user
void displaySymbolExplaination();

void dealer(TfDeck deck, Hand* playerArray, int players);
					// handle the game and deal card to each players

void sortHandsByRank(Hand* playerArray, int amtPlayers); // sort hand of each player in the game, 
														// by the rank of card.
void sortHandByRank(Hand hand); // sort a hand by the rank of card
void Gswap(Card* card1, Card * card2); // helper function to implement the sorthandByRank()
										// swap card1 and card2

void displayHands(Hand* playerArray, int players, int type);
								// display hand of each player
void displayHand(Hand hand); // display a hand of card
void dealt(Hand hand); // display hands that just dealt by the dealer
void sorted(Hand hand); // display the hand that had been sorted
void ranked(Hand hand); // dispaly the hand that had been ranked
void winner(Hand hand); // dispaly the hands with the 
void test(Hand hand); // display the the example of each kinds of hands, required by the assignment.
void displayWinner(Hand *playerArray, int playerAmt); // dispaly the hands with the "winner" market attached to the winner
int  rankJudge(Hand hand); // judge the rank of a hand 
int winnerJudge(Hand* playerArray, int playerAmt); // judge  whose is the winner in a game


boolean straightFlush(Hand hand); // determine if a hand is straight flush
boolean fourOfAKind(Hand hand);// determine if a hand is four of a kind
boolean fullHouse(Hand hand); // determin if a hand is full house
boolean flush(Hand hand); // determine if a hand is flush
boolean straight(Hand hand); // determine if a hand is traight
boolean threeOfAKind(Hand hand); // determine if a hand is three of a kind
boolean twoPair(Hand hand); // determine if  a hand is two  pair
boolean onePair(Hand hand); // determine if a hand is one pair
boolean highCard(Hand hand); // dtermine if a hand is high card
boolean AceStraight(Hand hand); // determine a hand is a striaight of 10, J, Q, K, A

#endif