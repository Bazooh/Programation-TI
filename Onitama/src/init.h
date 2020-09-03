
#ifndef SRC_INIT_H
#define SRC_INIT_H

# include <stdint.h>
# include <tice.h>

# include "game.h"
# include "card.h"

void initCursor(t_pos *cursor);
void initDeck(t_game *game);
void initMatrix(MATRIX);

#endif //SRC_INIT_H