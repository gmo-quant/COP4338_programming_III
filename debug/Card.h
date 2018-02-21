
// encode for representation of each suit
#define DIAMOND	0
#define CLUB	16
#define HEART	32
#define SPADE	48

#define DIAMOND_SYMBOL	"Diamond"
#define	CLUB_SYMBOL		"Club"
#define HEART_SYMBOL	"Heart"
#define SPADE_SYMBOL	"Spade"


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

#define CardSymbolLEN 	10
typedef char CardSymbolTf[CardSymbolLEN];

unsigned generateCard(unsigned suit, unsigned rank);
unsigned getSuit(unsigned card);
unsigned getRank(unsigned card);
SuitSymbolTf getSuitSymbol(unsigned suit);
RankSymbolTf getRankSymbol(unsigned rank);
void getCardSymbol(unsigned card, CardSymbolTf cardSymbol);
void displayCard(unsigned card);

void CardTester();