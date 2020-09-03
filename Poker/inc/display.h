
#ifndef PROJETS_DISPLAY_H
#define PROJETS_DISPLAY_H

#include <stdio.h>

#include "deck.h"
#include "players.h"

void printDeck(t_deck *deck);
void printPlayer(t_player player);
void printAllPlayers(t_player *players, uint8_t number_of_player);
void printGameInfo( t_player *players, t_game game);
void printPossibleBet(uint32_t *possible_bet);
void printBoard(t_card *board);
void printWinner(t_player winner);

#endif //PROJETS_DISPLAY_H
