
#include "color.h"

uint16_t gfx_pal[LENGTH_PAL] = {

        gfx_RGBTo1555(250,250,250), // BRIGHT_WHITE
        gfx_RGBTo1555(225,225,225), // WHITE
        gfx_RGBTo1555(200,200,200), // DARK_WHITE

        gfx_RGBTo1555(100,255,255), // BRIGHT_CYAN
        gfx_RGBTo1555(0,255,255),   // CYAN
        gfx_RGBTo1555(0,155,155),   // DARK_CYAN

        gfx_RGBTo1555(100,100,255), // BLUE
        gfx_RGBTo1555(0,0,255),     // DARK_BLUE
        gfx_RGBTo1555(0,0,155),     // DARK_DARK_BLUE

        gfx_RGBTo1555(255,150,100), // BRIGHT_ORANGE
        gfx_RGBTo1555(255,150,0),   // ORANGE
        gfx_RGBTo1555(155,50,0),    // DARK_ORANGE

        gfx_RGBTo1555(255,255,100), // BRIGHT_YELLOW
        gfx_RGBTo1555(255,255,0),   // YELLOW
        gfx_RGBTo1555(155,155,0),   // DARK_YELLOW

        gfx_RGBTo1555(100,255,100), // BRIGHT_GREEN
        gfx_RGBTo1555(0,255,0),     // GREEN
        gfx_RGBTo1555(0,155,0),     // DARK_GREEN

        gfx_RGBTo1555(150,100,255), // BRIGHT_PURPLE
        gfx_RGBTo1555(150,0,255),   // PURPLE
        gfx_RGBTo1555(50,0,155),    // DARK_PURPLE

        gfx_RGBTo1555(255,100,100), // BRIGHT_RED
        gfx_RGBTo1555(255,0,0),     // RED
        gfx_RGBTo1555(155,0,0),     // DARK_RED

        gfx_RGBTo1555(0,0,0),       // BRIGHT_BLACK
        gfx_RGBTo1555(0,0,0),       // BLACK
        gfx_RGBTo1555(0,0,0),       // DARK_BLACK
};
