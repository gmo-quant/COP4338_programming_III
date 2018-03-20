/* ===========================================================
|
|  
| 	 date: 2018-03-15 10:17:58
| Source code: MainPoker.c 
|      Author: Guangzhuan Mo
| Student ID : 5920187
| Assignment : Program#  4  MainPoker.c 
|      Course: COP 4338 (Advanced Programming) 
|    Section : U01 
|  Instructor: William Feild 
|    Due Date: 
|    
|      I hereby certify that this collcetive work is my own 
|      and none of it is the work of any other person or entiry. 
|      _________________________________________[Guangzhuan Mo]
|
|    Language: C
| Compile/Run:
| 	use make file:
| 		go to the folder MainPoker
| 		$ make
|	use gcc cmd:
|		gcc -std=c99 -o MainPoker Card.c Deck.c PokerGame.c MainPoker.c
|	to run the program:
|		$ ./MainPoker <number of card each hand> < nubmer of players>
|		for example:
| 		$ ./MainPoker 5 4
|		it will deal cards  4 players, each play have a hand of 5 cards
|
| +---------------------------------------------------------------
|
| Description:
|	simulate a deck of cards.
|	shuffled a deck of cards
|	deal hands of cards.
|	simulate a game of stud poker
|	operations:
|		* create a deck of cards 
|		* display the original deck,
|		* shuffle the deck
|		* display the shuffled deck
|		* deal(from the top of the deck) the 
|		  specified number of cards to the 
|		  specified number of players
|		  as per the command-line
|		* display each of the hands of cards.
|
| 	a deck of cards has 52 card:
| 		13 ranks
|		4 suits
|	
| 	Input:
|		cmd input.
| 		1st arg : # of cards per hand , will default to 5 cards per hand
|		2nd arg : # of hands(players), it should be in the range of [MIN_PLAYER_AMT,MAX_PLAYER_AMT]
|
|      Output:
|		* display the original deck(ordered) 
|		* display the shuffled deck()
|		* display each of the player's hands of cards.
|		* display each of the player's hands of cards, sorted
|		* display each of the player's hands of cards, ranked
|		* display each of the player's hands of cards, ranked, mark the winner
|		* display pre-set hands of cards, ranked
|		
|	example output:
| 		
|		
|     Process:
|	the program's steps are as follows:
|		1. generate a deck of card 
|		2. display the deck of card generated
|		3. shuffle the deck of card
|		4. display the deck of card shuffled
|		5. deal(from the top of the deck) the 
|			specified number of cards to the 
|			specified number of players
|			as per the command-line
|		6. display each of the hands of cards.
|			dealt, sorted, ranked, mark with winner(s)
|
| Required Features Not Included: 
|	All required features are included.
|
| Known Bugs:
| 	None;
|	the program operates correctly
|
 * ===========================================================*/

#include "MainPoker.h" // for the use of functionalities to play a game
#include<stdio.h> // for the use of printf("%s\n", );
#include<stdlib.h> // for the use of the macro EXIT_SUCCESS, EXIT_FAILURE
int main(int argc, char* argv[]){

	boolean isValide = FALSE;
	// validation the command-line argument
	isValide = validation(argc, argv);

	if (isValide == FALSE){
		exit(EXIT_FAILURE);
	}

	int amtPlayers = atoi(argv[2]);
	Hand  playerArray[amtPlayers];

	TfDeck deck;
	displaySymbolExplaination();
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
	Hand hand;
	printf("\n");
	test(hand); // display pre-set hand of kind


	return EXIT_SUCCESS;
}