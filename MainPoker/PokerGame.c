#include "MainPoker.h"
#include<stdio.h>
#include<stdlib.h>	// to use atoi for convient to handle argv
#include<string.h>

static char*  rankJudgement[9] = 
	{
		STRAIGHT_FLUSH, FOUR_KIND, FULL_HOUSE, FLUSH, 
		STRAIGHT, THREE_kIND, TWO_PAIR, ONE_PAIR, HIGH_CARD
	};

boolean validation(const int argc, char* const argv[]){

	char* instruction = "\n \t please use the following  command:  \n\n\
	\t./MainPoker <numbers of card> <number of players> \n\n\
	to start the game,\n\n\
	number of players should be in the range of [1,7],\n\n\
	number of cards will be changed to 5 no matter what user inputs, \n\n\
	for example : \n\n\
		./MainPoker 7 5 \n\n\
	indicates 5  cards per hand, 5 players\n";

	char* warning = RED"\n \
	WARNING: \n\n\
	number of players should be in the range of [1,7] \n"RESET;

	// check if the argument count is equal to ARG_AMT required.
	if (argc != ARG_AMT){
		printf("%s\n", instruction );
		return FALSE;
	}

	const int amtPlayers = atoi(argv[ARG_PLAYERS]);

	if ( TRUE == validPlayerAmt(amtPlayers) ){
		return TRUE;
	}else{
		//the player amount from the user
		// is out of range
		printf(" %s\n", warning);
		return FALSE;
	}
}// validation

boolean validPlayerAmt(const int playerAmt ){
	// it is validate player amount 
	// if it is in the range of [1,7]
	// return true
	if ( (playerAmt >= MIN_PLAYER_AMT) && (playerAmt <= MAX_PLAYER_AMT) ){
		return TRUE;
	}else{
		return FALSE;
	}
} //validatePlayer

boolean validCardsPerHand(const int cardPerHand ){
	if ( CARD_PER_HAND != cardPerHand ){
		return FALSE;
	}else{
		return TRUE;
	}
}// validaeHandAmt


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
	/*
		deal (from the top of the deck) the cardsPerHand of cards 
		to the "players" of players 
		starting from the top of the deck, 
		player by player
		for example, 5 players to play
		one card to 1st player, 2nd player ...5th player in order
		then the second card, until cardsPerHand
	*/

	for (cardCounter= 0; cardCounter< CARD_PER_HAND; cardCounter++){
		for (playerCounter= 0; playerCounter< players; playerCounter++){
			playerArray[playerCounter][cardCounter] = deck[cardDealedCounter];
			cardDealedCounter++;
		}
	}
}

void sortHandsByRank(Hand* playerArray, int amtPlayers){
	for(int i = 0; i < amtPlayers; i++){
		sortHandByRank(playerArray[i]);
	}
}


void sortHandByRank(Hand hand){
	for (int i = 0; i < CARD_PER_HAND; i++ ){
		for (int j = 0; j < CARD_PER_HAND; j++){
			if (hand[j].rank > hand[i].rank){
				Gswap(&hand[j] , &hand[i]);
			}
		}
	}
}

void Gswap(Card* card1, Card * card2){
	Card tmp = *card1;
	*card1 = *card2;
	*card2 = tmp;
}


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
}

void dealt(Hand hand){
	displayHand(hand);
	printf("\n");
}

void sorted(Hand hand){
	dealt(hand);
}
void ranked(Hand hand){
	displayHand(hand);
	printf(YELLOW" - %-15s"RESET, rankJudgement[rankJudge(hand)] );
}
void winner(Hand hand){
	// winnerJudge()
}
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
}

void displayHand(Hand hand){
	int cardIdx = 0;
	for (cardIdx = 0; cardIdx < CARD_PER_HAND; cardIdx++){
		displayCard(&hand[cardIdx]); 
	}
}


boolean straightFlush(Hand hand){

	// ONE MORE CASE TO THINK ABOUT
	// T J Q K A 


	// five cards in sequnce and
	// all of identical suits.
	boolean identicalSuit = FALSE;
	boolean inSequence = FALSE;
	for (int idx = 0; idx < CARD_PER_HAND -1 ; idx++){
		if (hand[idx].suit != hand[idx+1].suit){
			return FALSE;
		}else{
			identicalSuit = TRUE;
		}
	}
	if( TRUE == identicalSuit){
		for(int idx = CARD_PER_HAND - 1; idx > 0; idx--){
			if( (hand[idx].rank - hand[idx-1].rank) != 1){
				return FALSE;
			}else{
				inSequence = TRUE;
			}
		}
	}
	if( TRUE == (inSequence && identicalSuit) ){
		return TRUE;
	}else{
		return FALSE;
	}
}//straightFlush

boolean fourOfAKind(Hand hand){
	// four card of the same rank
	int sameRankCounter = 0;
	for (int idx = 0; idx < CARD_PER_HAND; idx++){
		for (int j = 0; j < CARD_PER_HAND; j++){
			if (hand[idx].rank == hand[j].rank ){
				sameRankCounter++;
				}
			}
		if(4 == sameRankCounter){
			return TRUE;
		}
		sameRankCounter = 0;
	}
	return FALSE;
} // fourOfAKind

boolean fullHouse(Hand hand){
	// Three cards of the same rank, and two cards of a different, matching rank
	// so it combines of a three of a kind and a pair
	if (threeOfAKind(hand) && onePair(hand)){
			return TRUE;
	}
	return FALSE;
} //fullHouse

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
} // flush

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
}// straight

boolean threeOfAKind(Hand hand){
	// three card of the same rank
	int sameRankCounter = 0;
	for (int idx = 0; idx < CARD_PER_HAND; idx++){
		for (int j = 0; j < CARD_PER_HAND; j++){
			if (hand[idx].rank == hand[j].rank ){
				sameRankCounter++;
				
			}
		}
		if(3 == sameRankCounter){
			return TRUE;
		}
		sameRankCounter=0;
	}
	return FALSE;
} // threeOfAKind

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
	if( 4 == pairCounter ){
		return TRUE;
	}else{
		return FALSE;
	}
} // twoPair

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
}// onePair

boolean highCard(Hand hand){

} // highCard


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


void ranker(Hand* playerArray, int playerAmt){
	for (int i = 0; i < playerAmt; i++ ){

	}
}

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
}

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
}

int winnerJudge(Hand* playerArray, int playerAmt){
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
}

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
} 


void PokerGameTester(const int argc, char* const argv[]){

	
	boolean isValide = FALSE;
	// validation the command-line argument
	isValide = validation(argc, argv);

	if (isValide == FALSE){
		exit(EXIT_FAILURE);
	}

	int amtPlayers = atoi(argv[2]);
	Hand  playerArray[amtPlayers];

	TfDeck deck;
	// displaySymbolExplaination();
	generateDeck(deck);
	displayDeck("original deck of card: \n" , deck);
	shuffleDeck(deck);
	displayDeck("shuffled deck of card: \n", deck);

	dealer(deck,  playerArray, amtPlayers );
	printf("\n");
	displayHands(playerArray, amtPlayers, DEALT);
	sortHandsByRank(playerArray, amtPlayers);
	printf("\n");
	displayHands(playerArray, amtPlayers, SORTED);
	printf("\n");
	displayHands(playerArray, amtPlayers, RANKED);
	printf("\n");
	displayWinner(playerArray, amtPlayers);
	// displayHands(playerArray, amtPlayers, WINNER);
	Hand hand;
	printf("\n");
	test(hand);

	tieBreaking(playerArray, amtPlayers);

}// PokerGameTester


void PokerRankTester(){
	Hand hand;
	// hand of straight flush
	hand[0] = generateCard(DIAMOND, 3);
	hand[1] = generateCard(CLUB, 4);
	hand[2] = generateCard(SPADE, 8);
	hand[3] = generateCard(DIAMOND, 6);
	hand[4] = generateCard(DIAMOND, 7);
	displayHand(hand);

	printf("%s\n",rankJudge(hand) );

}

