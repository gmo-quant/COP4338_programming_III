#include "MainPoker.h"
#include<stdio.h> // used for printf("%s\n", );
#include<stdlib.h>	// to use atoi for convient to handle argv
#include<string.h> // used for atoi() in validation()

// An array used for rankJudge() to determine 
// the type of the hand
static char*  rankJudgement[TYPE_OF_HANDS] = 
	{
		STRAIGHT_FLUSH, FOUR_KIND, FULL_HOUSE, FLUSH, 
		STRAIGHT, THREE_kIND, TWO_PAIR, ONE_PAIR, HIGH_CARD
	};

/*-------------------------validation-------------------------------
 *   function: boolean validation(const int argc, char* const argv[])
 *
 *    Purpose: determine whether the cmd of the user is valide 
 *				argc should be ARG_AMT
 *				player should be in the range of [MIN_PLAYER_AMT, MAX_PLAYER_AMT]
 * @param  argc, argv[]
 *
 * @return TRUE if valide, else FALSE
 *
 *---------------------------------------------------------------*/
boolean validation(const int argc, char* const argv[]){

	char* instruction = "\n \t please use the following  command:  \n\n\
	\t./MainPoker <numbers of card> <number of players> \n\n\
	to start the game,\n\n\
	number of players should be in the range of [1,7],\n\n\
	number of cards will be changed to 5 no matter what user inputs, \n\n\
	for example : \n\n\
		./MainPoker 7 5 \n\n\
	indicates 5  cards per hand, 5 players\n";

	char warning[BUFF_LEN] ; 
	sprintf(warning, 
		RED"\n \tWARNING: \n\n \tnumber of players should be in the range of [%d,%d] \n"RESET, 
		MIN_PLAYER_AMT, MAX_PLAYER_AMT);

	// check if the argument count is equal to ARG_AMT as required.
	if (argc != ARG_AMT){
		printf("%s\n", instruction );
		return FALSE;
	}

	const int amtPlayers = atoi(argv[ARG_PLAYERS]);
	if (validPlayerAmt(amtPlayers) ){
		return TRUE;
	}else{
		// warn the user that 
		printf(" %s\n", warning);
		return FALSE;
	}
}// validation() end



/*-------------------------validPlayerAmt-------------------------------
 *   function: boolean validPlayerAmt(const int playerAmt )
 *    Purpose: determine whether the cmd of the user is valide 
 *				playerAmt should be in the range of [MIN_PLAYER_AMT, MAX_PLAYER_AMT]
 * @param  playerAmt
 *
 * @return TRUE if valide, else FALSE
 *
 *---------------------------------------------------------------*/
boolean validPlayerAmt(const int playerAmt ){
	if ( (playerAmt >= MIN_PLAYER_AMT) && (playerAmt <= MAX_PLAYER_AMT) ){
		return TRUE;
	}else{
		return FALSE;
	}
} //validatePlayer() end

/*-------------------------validCardsPerHand-------------------------------
 *   function: boolean validCardsPerHand(const int cardPerHand ){
 *    Purpose: determine whether the cmd of the user is valide 
 *				cardPerHand should be CARD_PER_HAND
 * @param  const int cardPerHand
 *
 * @return TRUE if valide, else FALSE
 *
 *---------------------------------------------------------------*/
boolean validCardsPerHand(const int cardPerHand ){
	if ( CARD_PER_HAND != cardPerHand ){
		return FALSE;
	}else{
		return TRUE;
	}
}// validaeHandAmt() end


/*-------------------------displaySymbolExplaination-------------------------------
 *   function:  displaySymbolExplaination()
 *
 *    Purpose: display the explaination of the symbol of a card
 *
 * @param  none
 *
 * @return void
 *
 *---------------------------------------------------------------*/
void displaySymbolExplaination(){
	char * instruction = YELLOW"\
	Instruction for the meaning of the Symbol for each suit\n\
	\n\
	D represent Diamond \n \
	C represent Club \n \
	H represent Heart \n \
	S represent SPADE \n "RESET;
	printf("\n%s\n", instruction);
} // displaySymbolExplaination() end


/*-------------------------dealer-------------------------------
 *   function: dealer(TfDeck deck, unsigned * playerArray, 
 * 						int players, int cardsPerHand)
 *
 *    Purpose: deal (from the top of the deck) 
 * 				the specified number of cards 
 *				to the specified number of players 
 * 				(as per the command-line) 
 *	
 * @param  		the shuffled deck of card 
 *				the player array that hold hand of cards for each player
 *				amount of player, amount of cards per hand
 *
 * @return void
 *
 *---------------------------------------------------------------*/

void dealer(TfDeck deck, Hand* playerArray, int players){
	
	int playerCounter = 0;
	int cardCounter = 0;

	// the first card in the deck array starting from index 1;
	int cardDealedCounter = 1; 

	for (cardCounter= 0; cardCounter< CARD_PER_HAND; cardCounter++){
		for (playerCounter= 0; playerCounter< players; playerCounter++){
			playerArray[playerCounter][cardCounter] = deck[cardDealedCounter];
			cardDealedCounter++;
		}
	}
}// dealer() end

/*-------------------------sortHandsByRank-------------------------------
 *   function:void sortHandsByRank(Hand* playerArray, int amtPlayers)
 *    Purpose: sort hand of each player in the game, 
 * @param  Hand* playerArray, hand of each player in the game
 * 			int amtPlayers, the amount of players in the game
 *
 * @return none
 *
 *---------------------------------------------------------------*/
void sortHandsByRank(Hand* playerArray, int amtPlayers){
	for(int i = 0; i < amtPlayers; i++){
		sortHandByRank(playerArray[i]);
	}
}

/*-------------------------sortHandByRank-------------------------------
 *   function:void sortHandsByRank(Hand* playerArray, int amtPlayers)
 *    Purpose: sort hand of each player in the game, 
 * @param  Hand* playerArray, hand of each player in the game
 * 			int amtPlayers, the amount of players in the game
 *
 * @return none
 *
 *---------------------------------------------------------------*/
void sortHandByRank(Hand hand){
	for (int i = 0; i < CARD_PER_HAND; i++ ){
		for (int j = 0; j < CARD_PER_HAND; j++){
			if (hand[j].rank > hand[i].rank){
				Gswap(&hand[j] , &hand[i]);
			}
		}
	}
}// sortHandByRank() end
/*-------------------------Gswap-------------------------------
 *   function:void Gswap(Card* card1, Card * card2)
 *    Purpose: swap card1 and card2
 * @param  card1, card2
 * @return none
 *
 *---------------------------------------------------------------*/
void Gswap(Card* card1, Card * card2){
	Card tmp = *card1;
	*card1 = *card2;
	*card2 = tmp;
}

/*-------------------------displayHands-------------------------------
 *   function: void displayHands(Hand* playerArray, int players, int type)
 *
 *    Purpose: display hand of each player in the game, depending on the type
 * 				it can display 
 * 					the hand just dealt
 *					the hand sorted by rank of each card
 * 					the hand ranked by the type of hand  
 *	
 * @param  		playerArray, 
 *				players,
 *				type, display type: DEALT, SORTED,RANKED
 * @return void
 *
 *---------------------------------------------------------------*/
void displayHands(Hand* playerArray, int players, int type){

	void (*display[])(Hand) = {dealt, sorted, ranked, winner, test};
	char * pormpt[] = {
		"(dealt from top/front of deck)",
		"sorted",
		"ranked",
		"winner",
		"test"
	};
	int playerCounter= 0;
	printf(YELLOW"%s%s\n"RESET, "Player Hands: " , pormpt[type]);
	for (playerCounter= 0; playerCounter< players; playerCounter++){
		printf("Player %d] - ", playerCounter + 1);
		display[type](playerArray[playerCounter]);
		printf("\n");
	}
} // displayHands() end

/*-------------------------displayHand-------------------------------
 *   function: void displayHand(Hand hand)
 *
 *    Purpose: display the hand of a player 
 * @param  		Hand hand
 * @return void
 *
 *---------------------------------------------------------------*/
void displayHand(Hand hand){
	int cardIdx = 0;
	for (cardIdx = 0; cardIdx < CARD_PER_HAND; cardIdx++){
		displayCard(&hand[cardIdx]); 
	}
}

/*-------------------------dealt-------------------------------
 *   function: void dealt(Hand hand)
 *
 *    Purpose: display the hand of a player 
 * @param  		Hand hand
 * @return void
 *
 *---------------------------------------------------------------*/
void dealt(Hand hand){
	displayHand(hand);
	printf("\n");
}
/*-------------------------sorted-------------------------------
 *   function: void sorted(Hand hand)
 *
 *    Purpose: display the sorted hand of a player 
 * @param  		Hand hand
 * @return void
 *
 *---------------------------------------------------------------*/
void sorted(Hand hand){
	dealt(hand);
}
/*-------------------------ranked-------------------------------
 *   function: void ranked(Hand hand)
 *
 *    Purpose: display the sorted hand of a player 
 * @param  		Hand hand
 * @return void
 *
 *---------------------------------------------------------------*/
void ranked(Hand hand){
	displayHand(hand);
	printf(YELLOW" - %-15s"RESET, rankJudgement[rankJudge(hand)] );
}
// empty function, use displayWinner instead
void winner(Hand hand){
	// winnerJudge()
}


/*-------------------------test-------------------------------
 *   function: void test(Hand handfake)
 *
 *    Purpose: Display each of the pre-set hands 
 * 			   and the results of the tests
 * @param  		Hand handfake , it is not used here
 * @return void
 *
 *---------------------------------------------------------------*/
void test(Hand handfake){
	printf(YELLOW"%s%s\n"RESET, "Player Hands: " , "TEST");

	// High Card
	Hand hand;
	hand[0] = generateCard(DIAMOND, 2);
	hand[1] = generateCard(CLUB, 3);
	hand[2] = generateCard(DIAMOND, 4);
	hand[3] = generateCard(SPADE, 6);
	hand[4] = generateCard(HEART, QUEEN);
	printf("%s", "Hand :  "); 
	ranked(hand);
	printf("\n");

	// One Pair
	hand[0] = generateCard(DIAMOND, 4);
	hand[1] = generateCard(CLUB, 5);
	hand[2] = generateCard(DIAMOND, 5);
	hand[3] = generateCard(SPADE, 7);
	hand[4] = generateCard(HEART, 10);
	printf("%s", "Hand :  "); 
	ranked(hand);
	printf("\n");

	// Two Pair
	hand[0] = generateCard(DIAMOND, 3);
	hand[1] = generateCard(CLUB, 3);
	hand[2] = generateCard(DIAMOND, 10);
	hand[3] = generateCard(SPADE, 10);
	hand[4] = generateCard(HEART, QUEEN);
	printf("%s", "Hand :  "); 
	ranked(hand);
	printf("\n");

	// Three of a Kind
	hand[0] = generateCard(DIAMOND, 3);
	hand[1] = generateCard(CLUB, 3);
	hand[2] = generateCard(DIAMOND, 3);
	hand[3] = generateCard(SPADE, 6);
	hand[4] = generateCard(HEART, QUEEN);
	printf("%s", "Hand :  "); 
	ranked(hand);
	printf("\n");


	// Straight
	hand[0] = generateCard(DIAMOND, 1);
	hand[1] = generateCard(CLUB, 2);
	hand[2] = generateCard(DIAMOND, 3);
	hand[3] = generateCard(SPADE, 4);
	hand[4] = generateCard(HEART, 5);
	printf("%s", "Hand :  "); 
	ranked(hand);
	printf("\n");

	// Flush
	hand[0] = generateCard(DIAMOND, 10);
	hand[1] = generateCard(CLUB, JACK);
	hand[2] = generateCard(DIAMOND, QUEEN);
	hand[3] = generateCard(SPADE, KING);
	hand[4] = generateCard(HEART, A);
	printf("%s", "Hand :  "); 
	ranked(hand);
	printf("\n");	

	// Full House
	hand[0] = generateCard(DIAMOND, 3);
	hand[1] = generateCard(CLUB, 3);
	hand[2] = generateCard(DIAMOND, 3);
	hand[3] = generateCard(SPADE, QUEEN);
	hand[4] = generateCard(HEART, QUEEN);
	printf("%s", "Hand :  "); 
	ranked(hand);
	printf("\n");

	// Four of a Kind
	hand[0] = generateCard(DIAMOND, 3);
	hand[1] = generateCard(CLUB, 3);
	hand[2] = generateCard(DIAMOND, 3);
	hand[3] = generateCard(SPADE, 3);
	hand[4] = generateCard(HEART, QUEEN);
	printf("%s", "Hand :  "); 
	ranked(hand);
	printf("\n");

	// Straight Flush
	hand[0] = generateCard(DIAMOND, 10);
	hand[1] = generateCard(DIAMOND, JACK);
	hand[2] = generateCard(DIAMOND, QUEEN);
	hand[3] = generateCard(DIAMOND, KING);
	hand[4] = generateCard(DIAMOND, A);
	printf("%s", "Hand :  "); 
	ranked(hand);
	printf("\n");
}// test() end

/*-------------------------displayWinner-------------------------------
 *   function: void displayWinner(Hand *playerArray, int playerAmt)
 *
 *    Purpose: display  hand of each player in a gmae, 
 * 				with a mark of "winner" to the winner in the game
 * @param  		Hand *playerArray, 
 *				int playerAmt
 * @return void
 *
 *---------------------------------------------------------------*/
void displayWinner(Hand *playerArray, int playerAmt){
	int winner = winnerJudge(playerArray, playerAmt);
	int tag = winner;
	int shfitCounter = 0;
	printf(YELLOW"%s%s\n"RESET, "Player Hands: " , "winner(s)");
	for (int i = 0;  i < playerAmt; i++){
		if  ( (tag = winner & ( WINNER_MASK << ( shfitCounter) ))){
			printf("Player %d] - ", shfitCounter + 1);
			ranked(playerArray[shfitCounter]);
			printf(RED"%s\n"RESET," - winner");
		}else{
			printf("Player %d] - ", shfitCounter + 1);
			ranked(playerArray[shfitCounter]);
			printf("\n");
		}
		shfitCounter++;
	}
} // displayWinner() end
/*-------------------------rankJudge-------------------------------
 *   function: int rankJudge(Hand hand)
 *
 *    Purpose: judge the rank of a hand 
 * @param  		Hand hand, 
 *				
 * @return int the index of the type of rank of a hand
 *
 *---------------------------------------------------------------*/
int rankJudge(Hand hand){
	if (straightFlush(hand)){
		return IDX_STRAIGHT_FLUSH;
	}else if(fourOfAKind(hand)){
		return IDX_FOUR_KIND;
	}else if(fullHouse(hand)){
		return IDX_FULL_HOUSE;
	}else if (flush(hand) && !AceStraight(hand)){
		return IDX_FLUSH;
	}else if(straight(hand)){
		return IDX_STRAIGHT;
	}else if(threeOfAKind(hand)){
		return IDX_THREE_kIND;
	}else if (twoPair(hand)){
		return IDX_TWO_PAIR;
	}else if(onePair(hand)){
		return IDX_ONE_PAIR;
	}else{
		sortHandByRank(hand);
		if( (hand[0].rank == A) && (hand[1].rank == 10) && (hand[2].rank == JACK) 
			&& ( hand[3].rank == QUEEN ) && ( hand[4].rank == KING ) )
		{

			if( (hand[0].suit == hand[1].suit)  && ( hand[1].suit == hand[2].suit )
				&& ( hand[2].suit == hand[3].suit) && ( hand[3].suit == hand[4].suit) )
			{
				return IDX_STRAIGHT_FLUSH;
			}
			else
			{
				return IDX_FLUSH;
			}

		}else{
			return IDX_HIGH_CARD;
		}		
	}
} // rankJudge() end

/*-------------------------winnerJudge-------------------------------
 *   function: int winnerJudge(Hand* playerArray, int playerAmt)
 *
 *    Purpose: determine whose is the winnder(s) of a game
 *				
 * @param  		Hand hand, 
 *				
 * @return int the index of the type of rank of a hand
 *
 *---------------------------------------------------------------*/
int winnerJudge(Hand* playerArray, int playerAmt){
	// use bit wise operation on the winner to handle 
	// who is the winner(s)
	int highesrank = IDX_HIGH_CARD;
	int winner = LOSS ;
	int t_rank = highesrank;
	// figure out what is the higest rank
	for (int playerCounter= 0; playerCounter< playerAmt; playerCounter++){
		t_rank = rankJudge(playerArray[playerCounter]);
		if ( t_rank < highesrank ){
			highesrank = t_rank;
		}
	}
	// figure which player(s) has the highest rank
	for (int playerCounter= 0; playerCounter< playerAmt; playerCounter++){
		t_rank = rankJudge(playerArray[playerCounter]);
		if ( t_rank == highesrank ) {
			winner ^= ( WINNER_MASK << ( playerCounter) ); 
		}
	}
	return winner;
}// winnerJudge() end

/*-------------------------straightFlush-------------------------------
 *   function: boolean straightFlush(Hand hand){
 *
 *    Purpose: determine if a hand is straight flush
 * @param  		Hand hand
 * @return TRUE if it is a hand of straight flush
 *
 *---------------------------------------------------------------*/
boolean straightFlush(Hand hand){
	// five cards in sequnce and
	// all of identical suits.
	boolean identicalSuit = FALSE;
	boolean inSequence = FALSE;
	// determine if the suit of each card in the hand is the same
	for (int idx = 0; idx < CARD_PER_HAND -1 ; idx++){
		if (hand[idx].suit != hand[idx+1].suit){
			return FALSE;
		}else{
			identicalSuit = TRUE;
		}
	}
	// determine if the rank of each card in the hand is in sequence
	if( TRUE == identicalSuit){
		for(int idx = CARD_PER_HAND - 1; idx > 0; idx--){
			if( (hand[idx].rank - hand[idx-1].rank) != 1){
				return FALSE;
			}else{
				inSequence = TRUE;
			}
		}
	}
	// determine if it is a straight flush
	if( TRUE == (inSequence && identicalSuit) ){
		return TRUE;
	}else{
		return FALSE;
	}
}//straightFlush end

/*-------------------------fourOfAKind-------------------------------
 *   function: boolean fourOfAKind(Hand hand)
 *
 *    Purpose: determine if a hand is four of a kind
 * @param  		Hand hand
 * @return TRUE if it is a hand of four of a kind
 *
 *---------------------------------------------------------------*/
boolean fourOfAKind(Hand hand){
	// four card of the same rank
	int sameRankCounter = 0;
	for (int idx = 0; idx < CARD_PER_HAND; idx++){
		for (int j = 0; j < CARD_PER_HAND; j++){
			if (hand[idx].rank == hand[j].rank ){
				sameRankCounter++;
				}
			}
		// if there are four card of same rank	
		if(4 == sameRankCounter){
			return TRUE;
		}
		sameRankCounter = 0;
	}
	return FALSE;
} // fourOfAKind() end

boolean fullHouse(Hand hand){
	// Three cards of the same rank, and two cards of a different, matching rank
	// so it combines of a three of a kind and a pair
	if (threeOfAKind(hand) && onePair(hand)){
			return TRUE;
	}
	return FALSE;
} //fullHouse() end

/*-------------------------flush-------------------------------
 *   function: boolean flush(Hand hand)
 *
 *    Purpose: determine if a hand is flush
 * @param  		Hand hand
 * @return TRUE if it is a hand of flush
 *---------------------------------------------------------------*/
boolean flush(Hand hand){
	// five card of same suit
	boolean identicalSuit = FALSE;	
	for (int idx = 0; idx < CARD_PER_HAND -1 ; idx++){
		if (hand[idx].suit != hand[idx+1].suit){
			return FALSE;
		}else{
			identicalSuit = TRUE;
		}
	}
	return identicalSuit;
} // flush() end

/*-------------------------straight-------------------------------
 *   function: boolean straight(Hand hand)
 *
 *    Purpose: determine if a hand is straight
 * @param  		Hand hand
 * @return TRUE if it is a hand of straight
 *---------------------------------------------------------------*/
boolean straight(Hand hand){
	// Five cards in sequence.
	boolean inSequence = FALSE;
	for(int idx = CARD_PER_HAND - 1; idx > 0; idx--){
			if( (hand[idx].rank - hand[idx-1].rank) != 1){
				return FALSE;
			}else{
				inSequence = TRUE;
			}
		}
}// straight() end
/*-------------------------threeOfAKind-------------------------------
 *   function: boolean threeOfAKind(Hand hand)
 *
 *    Purpose: determine if a hand is three of a kind
 * @param  		Hand hand
 * @return TRUE if it is a hand of three of a kind
 *---------------------------------------------------------------*/
boolean threeOfAKind(Hand hand){
	// three card of the same rank
	int sameRankCounter = 0;
	for (int idx = 0; idx < CARD_PER_HAND; idx++){
		for (int j = 0; j < CARD_PER_HAND; j++){
			if (hand[idx].rank == hand[j].rank ){
				sameRankCounter++;
				
			}
		}
		// if there are three card of same rank	
		if(3 == sameRankCounter){
			return TRUE;
		}
		sameRankCounter=0;
	}
	return FALSE;
} // threeOfAKind() end

/*-------------------------threeOfAKind-------------------------------
 *   function: boolean threeOfAKind(Hand hand)
 *
 *    Purpose: determine if a hand is three of a kind
 * @param  		Hand hand
 * @return TRUE if it is a hand of three of a kind
 *---------------------------------------------------------------*/
boolean twoPair(Hand hand){
	int pairCounter = 0;
	int sameRankCounter = 0;
	for (int idx = 0; idx < CARD_PER_HAND; idx++){
		for (int j = 0; j < CARD_PER_HAND; j++){
			if (hand[idx].rank == hand[j].rank ){
				sameRankCounter++;
			}
		}
		if(2 == sameRankCounter){
			pairCounter++;
		}
		sameRankCounter = 0;
	}
	// comparing with 4 because if it is two, it means one pair
	if( 4 == pairCounter ){
		return TRUE;
	}else{
		return FALSE;
	}
} // twoPair() end
/*-------------------------onePair-------------------------------
 *   function: boolean onePair(Hand hand)
 *
 *    Purpose: determine if a hand is onePair
 * @param  		Hand hand
 * @return TRUE if it is a hand of onePair
 *---------------------------------------------------------------*/
boolean onePair(Hand hand){
	int sameRankCounter = 0;
	for (int idx = 0; idx < CARD_PER_HAND; idx++){
		for (int j = 0; j < CARD_PER_HAND; j++){
			if (hand[idx].rank == hand[j].rank ){
				sameRankCounter++;
			}
		}
		if(2 == sameRankCounter){
			return TRUE;
		}
		sameRankCounter = 0;
	}
	return FALSE;
}// onePair() end
// empty function, 
boolean highCard(Hand hand){

} // highCard
/*-------------------------AceStraight-------------------------------
 *   function: boolean AceStraight(Hand hand)
 *
 *    Purpose: determine if a hand is determine a hand is a striaight of 10, J, Q, K, A
 * @param  		Hand hand
 * @return TRUE if it is a hand of determine a hand is a striaight of 10, J, Q, K, A
 *---------------------------------------------------------------*/
boolean AceStraight(Hand hand){
	sortHandByRank(hand);
	if( (hand[0].rank == A) && (hand[1].rank == 10) && (hand[2].rank == JACK) 
			&& ( hand[3].rank == QUEEN ) && ( hand[4].rank == KING ) 

			&& (hand[0].suit == hand[1].suit)  && ( hand[1].suit == hand[2].suit )
				&& ( hand[2].suit == hand[3].suit) && ( hand[3].suit == hand[4].suit) ){
		return TRUE;
	}
	else{
		return FALSE;
	}	
}// AceStraight() end


void tieBreaking(Hand* playerArray, int playerAmt){
	int winner = winnerJudge(playerArray, playerAmt);
	int *players = NULL;
	players = (int*)malloc(sizeof(int) * playerAmt);
	players[0] = 6;
	printf("%d\n", players[0] );
	int tag = winner;
	int shfitCounter = 0;
	for (int i = 0;  i < playerAmt; i++){
		if  ( (tag = winner & ( WINNER_MASK << ( shfitCounter) ))){
			players[shfitCounter] = 1;
		}else{
			players[shfitCounter] = 0;
		}
		shfitCounter++;
	}
	
}
