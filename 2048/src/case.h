
#ifndef PROJETS_CASE_H
#define PROJETS_CASE_H

# include <stdint.h>

# include "info.h"

# define CASE_WIDTH 40
# define CASE_HEIGHT 40
# define CASE_SIZE (CASE_WIDTH * CASE_HEIGHT) + 2

extern uint8_t sprite_empty[CASE_SIZE];
#define SPRITE_EMPTY ((gfx_sprite_t*)sprite_empty)
extern uint8_t sprite_2[CASE_SIZE];
#define SPRITE_2 ((gfx_sprite_t*)sprite_2)
extern uint8_t sprite_4[CASE_SIZE];
#define SPRITE_4 ((gfx_sprite_t*)sprite_4)
extern uint8_t sprite_8[CASE_SIZE];
#define SPRITE_8 ((gfx_sprite_t*)sprite_8)
extern uint8_t sprite_16[CASE_SIZE];
#define SPRITE_16 ((gfx_sprite_t*)sprite_16)
extern uint8_t sprite_32[CASE_SIZE];
#define SPRITE_32 ((gfx_sprite_t*)sprite_32)
extern uint8_t sprite_64[CASE_SIZE];
#define SPRITE_64 ((gfx_sprite_t*)sprite_64)
extern uint8_t sprite_128[CASE_SIZE];
#define SPRITE_128 ((gfx_sprite_t*)sprite_128)
extern uint8_t sprite_256[CASE_SIZE];
#define SPRITE_256 ((gfx_sprite_t*)sprite_256)
extern uint8_t sprite_512[CASE_SIZE];
#define SPRITE_512 ((gfx_sprite_t*)sprite_512)
extern uint8_t sprite_1024[CASE_SIZE];
#define SPRITE_1024 ((gfx_sprite_t*)sprite_1024)
extern uint8_t sprite_2048[CASE_SIZE];
#define SPRITE_2048 ((gfx_sprite_t*)sprite_2048)
extern uint8_t sprite_4096[CASE_SIZE];
#define SPRITE_4096 ((gfx_sprite_t*)sprite_4096)
extern uint8_t sprite_8192[CASE_SIZE];
#define SPRITE_8192 ((gfx_sprite_t*)sprite_8192)

#endif //PROJETS_CASE_H
