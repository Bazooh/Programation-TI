# include <graphx.h>

# include "core.h"
# include "color.h"

void main() {
    gfx_Begin();
    gfx_SetPalette(gfx_pal, sizeof_gfx_pal, 0);
    gfx_FillScreen(BRIGHT_WHITE);
    gfx_SetTextConfig(gfx_text_noclip);
    srandom(rtc_Time());

    loop(chooseDifficulty());

    kb_Reset();
    gfx_End();
}

