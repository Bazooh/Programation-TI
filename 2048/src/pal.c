
#include "pal.h"

uint16_t gfx_pal[PAL_LENGTH] = {
        gfx_RGBTo1555(  0,  0,  0),     // transparent
        gfx_RGBTo1555(250,250,250),     // white
        gfx_RGBTo1555(200,200,200),     // grey
        gfx_RGBTo1555(150,150,150),     // dark_grey
        gfx_RGBTo1555(100,100,100),     // color_empty
        gfx_RGBTo1555(240,240,240),     // color_2
        gfx_RGBTo1555(250,250,230),     // color_4
        gfx_RGBTo1555(250,210,150),     // color_8
        gfx_RGBTo1555(250,200,150),     // color_16
        gfx_RGBTo1555(250,180,150),     // color_32
        gfx_RGBTo1555(250,100, 70),     // color_64
        gfx_RGBTo1555(250,250,190),     // color_128
        gfx_RGBTo1555(250,250,150),     // color_256
        gfx_RGBTo1555(250,250,110),     // color_512
        gfx_RGBTo1555(250,220,110),     // color_1024
        gfx_RGBTo1555(250,210,100),     // color_2048
        gfx_RGBTo1555(250,130,130),     // color_4096
        gfx_RGBTo1555( 90, 90, 90),     // color_8192
};