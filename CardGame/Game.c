#include"Game.h" 	// function  prototype  of Game.c and some MACRO important to implement Game.c
#include"Deck.h" 	// function prototype of Deck.c, dealing with cards and deck, need function in Deck.c
#include<stdio.h>	// to use printf
#include<stdlib.h>	// to use atoi for convient to handle argv
#include<string.h>	// to use atoi for convient to handle argv


/*-------------------------validation-------------------------------
 *   function: validation(int argc, char * argv[])
 *
 *    Purpose: 
 *			 validate the players amount and cardsperhand from the cmd arg
 *
 * @param  argc, argv[] same get from the main(argc, argv[])
 *
 * @return TRUE for valid palyer and cardperhand
 *			FALSE for any invalid argument
 *
 *---------------------------------------------------------------*/
boolean validation(int argc, char * argv[]){

	char* instruction = "\n \t please use the following  command:  \n\n\
	\t./MainHand <numbers of card> <number of plays> \n\n\
	to start the game,\n\n \
	for example : \n\n \
		./MainHand 7 5 \n\n \
	to indicate 7 cards per hand, 5 players\n";

	char* warning = RED"\n \
	WARNING: \n\n\
	the product of <number of card> and <number of players> should be no larger than 52\n"RESET;

	// check if the argument count is equal to ARG_AMT required.
	if (argc != ARG_AMT){
		printf("%s\n", instruction );
		return FALSE;
	}
	// if given player amount and card per hand amount 
	// is integer, atoi will return the converted integer,
	// else it will return 0, indicating it invalid argument
	int amtCardsEachHand = atoi(argv[1]);
	int amtPlayers = atoi(argv[2]);

	if (amtPlayers == 0 || amtCardsEachHand == 0){
		printf("%s\n", instruction );
		return FALSE;
	} 

	// make sure that the game can be played with 
	// this deck of cards
	if (amtCardsEachHand * amtPlayers > 52){
		printf("%s\n", instruction);
		printf("%s\n", warning );
		return FALSE;
	}
	// validate if the amount of players are within 
	// the range allowed.
	if (amtPlayers > MAX_PLAYERS){
		printf("%s\n", instruction);
		char * overMaxPlayer =  RED"\n \
	WARNING: \n\n\
	no more than ";
		printf("%s", overMaxPlayer);
		printf(" %d " , MAX_PLAYERS );
		printf("%s\n\n", "players"RESET);
		return FALSE;
	}
	// validate if the amount of card each hand are within 
	// the range allowed.
	if (amtCardsEachHand > MAX_CARD_PER_HAND ){
		printf("%s\n", instruction);
		char * overMaxPlayer =  RED"\n \
	WARNING: \n\n\
	no more than ";
		printf("%s", overMaxPlayer);
		printf(" %d " , MAX_CARD_PER_HAND );
		printf("%s\n\n", "cards per hand"RESET);
		return FALSE;
	}
	return TRUE;
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

void dealer(TfDeck deck, unsigned * playerArray, int players, int cardsPerHand){
	
	int playerCounter = 0;
	int cardCounter = 0;

	// initilize the playerArray
	// the array that hold hand of cards for each player
	for (playerCounter = 0; playerCounter < players; playerCounter++){
		for (cardCounter = 0; cardCounter< cardsPerHand; cardCounter++){
			*((playerArray + (playerCounter * cardsPerHand) ) +cardCounter)= playerCounter;
		}
	}
	// the first card in the deck array starting from index 1;
	int cardDealedCounter = 1; 
	// deal (from the top of the deck) the cardsPerHand of cards 
	// to the "players" of players 
	// starting from the top of the deck, 
	// player by player
	// for example, 5 players to play
	// one card to 1st player, 2nd player ...5th player in order
	// then the second card, until cardsPerHand
	for (cardCounter= 0; cardCounter< cardsPerHand; cardCounter++){
		for (playerCounter= 0; playerCounter< players; playerCounter++){
			*((playerArray + (playerCounter * cardsPerHand) ) +cardCounter) = deck[cardDealedCounter];
			cardDealedCounter++;
		}
	}
}

/*-------------------------displayHands-------------------------------
 *   function: displayHands(unsigned * playerArray, int players, int cardsPerHand)
 *
 *    Purpose: display hands of card for each player
 *
 * @param  the player array that hold hand of cards for each player
 *				amount of player, amount of cards per hand
 *
 * @return void
 *
 *---------------------------------------------------------------*/

void displayHands(unsigned * playerArray, int players, int cardsPerHand){

	int playerCounter= 0;
	int cardCounter= 0;
	unsigned card = BLANK_CARD;

	// display hands of card for each player
	for (playerCounter= 0; playerCounter< players; playerCounter++){
		printf("Hands of Player: %d \n\n", playerCounter + 1);
		for (cardCounter= 0; cardCounter< cardsPerHand; cardCounter++){
			card = *((playerArray + (playerCounter * cardsPerHand) ) + cardCounter);
			displayCard(card);
			printf(", ");
		}
		printf("\n\n");
	}
}


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
}


/*-------------------------game-------------------------------
 *   function:  game()
 *
 *    Purpose: start a game
 *
 * @param  none
 *
 * @return void
 *
 *---------------------------------------------------------------*/
void game(int argc, char* argv[]){
	boolean isValide = FALSE;
	// validation the command-line argument
	isValide = validation(argc, argv);

	if (isValide == FALSE){
		exit(EXIT_FAILURE);
	}
	
	int amtCardsEachHand = atoi(argv[1]);
	int amtPlayers = atoi(argv[2]);
	unsigned  playerArray[amtPlayers][amtCardsEachHand];

	TfDeck deck;
	displaySymbolExplaination();
	generateDeck(deck);
	displayDeck("original deck of card: \n" , deck);
	shuffleDeck(deck);
	displayDeck("shuffled deck of card: \n", deck);
	dealer(deck,  (unsigned *) playerArray, amtPlayers, amtCardsEachHand );
	displayHands(  (unsigned *) playerArray, amtPlayers, amtCardsEachHand);
}


// for testing purpose when developing Game.c

void GameTester(int argc, char* argv[]){
	game(argc, argv);
}

