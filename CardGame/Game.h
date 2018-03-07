#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#define RESET   "\033[0m"
#define RED     "\033[31m" 
#define YELLOW  "\033[33m" 

#define MAX_PLAYERS	13
#define MAX_CARD_PER_HAND	13

#define ARG_AMT	3

typedef enum {TRUE = 1, FALSE = 0} boolean ;

// validate the players amount and cardsperhand from the cmd arg
boolean validation(int argc, char* argv[]);

void dealer(TfDeck deck, unsigned * playerArray, int players, int cardsPerHand);
void displayHands(unsigned * playerArray, int players, int cardsPerHand);

void game(int argc, char* argv[]); 	// start a game

void displaySymbolExplaination();

void GameTester(int argc, char* argv[]);

#endif