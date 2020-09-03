// this file contains all the graphics sources for easy inclusion in a project
#ifndef CASE_GFX_H
#define CASE_GFX_H

# include <stdint.h>
# include <graphx.h>

#define case_gfx_transparent_color_index 0

#define CASE_INNER_WIDTH 9
#define CASE_OUTER_WIDTH 10
#define CASE_INNER_HEIGHT 9
#define CASE_OUTER_HEIGHT 10

#define CASE_SIZE 83

#define MARGE 5
#define HUD_HEIGHT 30

extern uint8_t sprite_hidden_case[CASE_SIZE];
#define SPRITE_HIDDEN_CASE ((gfx_sprite_t*)sprite_hidden_case)
extern uint8_t sprite_cursor[CASE_SIZE];
#define SPRITE_CURSOR ((gfx_sprite_t*)sprite_cursor)
extern uint8_t sprite_flag[CASE_SIZE];
#define SPRITE_FLAG ((gfx_sprite_t*)sprite_flag)
extern uint8_t sprite_bomb[CASE_SIZE];
#define SPRITE_BOMB ((gfx_sprite_t*)sprite_bomb)
extern uint8_t sprite_case_0[CASE_SIZE];
#define SPRITE_CASE_0 ((gfx_sprite_t*)sprite_case_0)
extern uint8_t sprite_case_1[CASE_SIZE];
#define SPRITE_CASE_1 ((gfx_sprite_t*)sprite_case_1)
extern uint8_t sprite_case_2[CASE_SIZE];
#define SPRITE_CASE_2 ((gfx_sprite_t*)sprite_case_2)
extern uint8_t sprite_case_3[CASE_SIZE];
#define SPRITE_CASE_3 ((gfx_sprite_t*)sprite_case_3)
extern uint8_t sprite_case_4[CASE_SIZE];
#define SPRITE_CASE_4 ((gfx_sprite_t*)sprite_case_4)
extern uint8_t sprite_case_5[CASE_SIZE];
#define SPRITE_CASE_5 ((gfx_sprite_t*)sprite_case_5)
extern uint8_t sprite_case_6[CASE_SIZE];
#define SPRITE_CASE_6 ((gfx_sprite_t*)sprite_case_6)
extern uint8_t sprite_case_7[CASE_SIZE];
#define SPRITE_CASE_7 ((gfx_sprite_t*)sprite_case_7)
extern uint8_t sprite_case_8[CASE_SIZE];
#define SPRITE_CASE_8 ((gfx_sprite_t*)sprite_case_8)



#define LENGTH_PAL 10
#define sizeof_mines_weeper_gfx_pal LENGTH_PAL * 2
extern uint16_t mines_weeper_gfx_pal[LENGTH_PAL];

#endif
