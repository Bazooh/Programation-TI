
#ifndef PROJETS_GAMESTARTINGINFO_H
#define PROJETS_GAMESTARTINGINFO_H

# include <stdint.h>

# include "player.h"
# include "deck.h"

# define NUMBER_OF_CARD_IN_BOARD 5

typedef struct s_round {
    uint32_t bet;
    uint8_t last_raise_id;
    t_card board[NUMBER_OF_CARD_IN_BOARD];
    uint8_t round_id;
}              t_round;

typedef struct s_param {
    uint8_t number_of_player;
    uint32_t money;
    uint32_t small_blind;
}              t_param;

typedef struct s_game {
    uint32_t pot;
    uint8_t small_blind_id;
    t_round round;
    t_param param;
}              t_game;

typedef struct s_hand_info {
    uint8_t color[NUMBER_OF_COLOR];
    uint8_t value[NUMBER_OF_VALUE];
}              t_hand_info;

#endif //PROJETS_GAMESTARTINGINFO_H