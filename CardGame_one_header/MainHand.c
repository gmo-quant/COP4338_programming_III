/* ===========================================================
|
|  
| 	 date: 2018-02-15 10:17:58
| Source code: MainHand.c 
|      Author: Guangzhuan Mo
| Student ID : 5920187
| Assignment : Program#  3  MainHand.c 
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
| 		go to the folder CardGame
| 		$ make
|	use gcc cmd:
|		gcc -std=c99 -o MainHand Card.c Deck.c Game.c MainHand.c
|	to run the program:
|		$ ./MainHand <number of card each hand> < nubmer of players>
|		for example:
| 		$ ./MainHand 7 4
|		it will deal cards 4 players, each play have a hand of 7 cards
|
| +---------------------------------------------------------------
|
| Description:
|	simulate a deck of cards.
|	and
|	deal hands of cards.
|	
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
| 		1st arg : # of cards per hand 
|		2nd arg : # of hands(players)
|
|      Output:
|		* display the original deck(ordered) 
|		* display the shuffled deck()
|		* display each of the player's hands of cards.
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
|
| Required Features Not Included: 
|	All required features are included.
|
| Known Bugs:
| 	None;
|	the program operates correctly
|
 * ===========================================================*/


#include"cardGame.h" 	// when invoke game to play the a game, 
					// need this file
#include<stdlib.h>	// to use the MACRO EXIT_SUCCESS,

int main(int argc, char * argv[]){
	game(argc,  argv);
	return EXIT_SUCCESS;
}