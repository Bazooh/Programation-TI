
#ifndef PROJETS_CORE_H
#define PROJETS_CORE_H

# include <stdint.h>
# include <keypadc.h>
# include <tice.h>

# include "display.h"
# include "game.h"

# define TRUE 1
# define FALSE 0

# define CASE_BLOCKED -2
# define CASE_USED -1
# define CASE_EMPTY 0

# define UP 0, -1
# define DOWN 0, 1
# define LEFT -1, 0
# define RIGHT 1, 0

# define WAITING_DELAY 250

void play(t_game game);
uint8_t isInMap(t_game *game, t_pos pos);

#endif //PROJETS_CORE_H
