
#ifndef POKER_PLAYERACTION_H
#define POKER_PLAYERACTION_H

# include <stdint.h>
# include <stdlib.h>

# include "player.h"
# include "initGame.h"
# include "display.h"
# include "bet.h"

# define FOLD -1
# define CALL 0

void playerAction(t_player *players, t_game *game, uint8_t number);

#endif //POKER_PLAYERACTION_H
