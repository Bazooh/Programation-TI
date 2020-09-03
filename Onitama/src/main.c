
#include "main.h"

void main() {
    gfx_Begin();
    gfx_SetPalette(gfx_pal, sizeof_gfx_pal, 0);
    gfx_FillScreen(0x07);
    gfx_SetTextFGColor(0x02);
    gfx_SetColor(0x01);
    srandom(rtc_Time());

    play();

    gfx_End();
}