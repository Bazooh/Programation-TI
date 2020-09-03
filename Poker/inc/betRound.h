
#ifndef POKER_BETROUND_H
#define POKER_BETROUND_H

# include <stdint.h>

# include "player.h"
# include "gameInfo.h"
# include "bet.h"
# include "playerAction.h"
# include "display.h"

void betFirstRound(t_player *players, t_game *game);
void betRound(t_player *players, t_game *game);

#endif //POKER_BETROUND_H
