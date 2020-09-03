
#ifndef POKER_BET_H
#define POKER_BET_H

# include "player.h"
# include "gameInfo.h"

void setFold(t_player *players, uint8_t number_of_player);
void setReady(t_player *players, uint8_t number_of_player);
void betPlayer(t_player *player, t_game *game, uint32_t bet);
uint8_t checkReady(t_player *players, uint8_t number_of_player);
void initPlayersBet(t_player *players, t_game game);

#endif //POKER_BET_H