
#ifndef POKER_PLAYER_H
#define POKER_PLAYER_H

# include <stdint.h>

# include "card.h"

# define MAX_CHAR_IN_NAME 10
# define NUMBER_OF_CARD_IN_HAND 2
# define NUMBER_OF_ROUND 4

typedef struct s_player {
    uint8_t number;
    char name[MAX_CHAR_IN_NAME + 1];
    uint16_t password;
    uint32_t bankroll;
    t_card hand[NUMBER_OF_CARD_IN_HAND];
    uint8_t fold;
    uint32_t bet[NUMBER_OF_ROUND];
    uint8_t ready;
}              t_player;

void initPlayer(t_player *player, uint32_t start_money);

#endif //POKER_PLAYER_H
