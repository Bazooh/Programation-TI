
#include "minesweeper.h"

int main(void) {
    gfx_Begin();
    gfx_SetPalette(mines_weeper_gfx_pal, sizeof_mines_weeper_gfx_pal, 0);
    gfx_FillScreen(4);

    play();

    kb_Reset();
    gfx_End();
    return (0);
}
