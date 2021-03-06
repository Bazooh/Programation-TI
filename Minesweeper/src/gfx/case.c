#include <stdint.h>
#include "case_gfx.h"

uint8_t sprite_hidden_case[CASE_SIZE] = {
        9,	// tile_width
        9,	// tile_height
        0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
        0x01,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x03,
        0x01,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x03,
        0x01,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x03,
        0x01,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x03,
        0x01,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x03,
        0x01,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x03,
        0x01,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x03,
        0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,
};

uint8_t sprite_cursor[CASE_SIZE] = {
        9,	// tile_width
        9,	// tile_height
        0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,
        0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,
        0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,
        0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,
        0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,
        0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,
        0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,
        0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,
        0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,
};

uint8_t sprite_flag[CASE_SIZE] = {
        9,	// tile_width
        9,	// tile_height
        0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
        0x01,0x02,0x02,0x04,0x02,0x02,0x02,0x02,0x03,
        0x01,0x02,0x02,0x04,0x05,0x02,0x02,0x02,0x03,
        0x01,0x02,0x02,0x04,0x05,0x05,0x02,0x02,0x03,
        0x01,0x02,0x02,0x04,0x05,0x05,0x05,0x02,0x03,
        0x01,0x02,0x02,0x04,0x02,0x02,0x02,0x02,0x03,
        0x01,0x02,0x02,0x04,0x02,0x02,0x02,0x02,0x03,
        0x01,0x02,0x04,0x04,0x04,0x04,0x02,0x02,0x03,
        0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x03,
};

uint8_t sprite_bomb[CASE_SIZE] = {
        9,	// tile_width
        9,	// tile_height
        0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,
        0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,
        0x05,0x05,0x05,0x04,0x04,0x04,0x05,0x05,0x05,
        0x05,0x05,0x04,0x01,0x04,0x04,0x04,0x05,0x05,
        0x05,0x05,0x04,0x04,0x04,0x04,0x04,0x05,0x05,
        0x05,0x05,0x04,0x04,0x04,0x04,0x04,0x05,0x05,
        0x05,0x05,0x05,0x04,0x04,0x04,0x05,0x05,0x05,
        0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,
        0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,0x05,
};

uint8_t sprite_case_0[CASE_SIZE] = {
        9,	// tile_width
        9,	// tile_height
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
};

uint8_t sprite_case_1[CASE_SIZE] = {
        9,	// tile_width
        9,	// tile_height
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x07,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x07,0x07,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x07,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x07,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x07,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x07,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
};

uint8_t sprite_case_2[CASE_SIZE] = {
        9,	// tile_width
        9,	// tile_height
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x06,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x06,0x02,0x06,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x06,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x06,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x06,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x06,0x06,0x06,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
};

uint8_t sprite_case_3[CASE_SIZE] = {
        9,	// tile_width
        9,	// tile_height
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x05,0x05,0x05,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x05,0x02,0x02,
        0x02,0x02,0x02,0x02,0x05,0x05,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x05,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x05,0x02,0x02,
        0x02,0x02,0x02,0x05,0x05,0x05,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
};

uint8_t sprite_case_4[CASE_SIZE] = {
        9,	// tile_width
        9,	// tile_height
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x08,0x02,0x08,0x02,0x02,0x02,
        0x02,0x02,0x02,0x08,0x02,0x08,0x02,0x02,0x02,
        0x02,0x02,0x02,0x08,0x08,0x08,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x08,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x08,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x08,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
};

uint8_t sprite_case_5[CASE_SIZE] = {
        9,	// tile_width
        9,	// tile_height
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x09,0x09,0x09,0x09,0x02,0x02,
        0x02,0x02,0x02,0x09,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x09,0x09,0x09,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x09,0x02,0x02,
        0x02,0x02,0x02,0x09,0x09,0x09,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
};

uint8_t sprite_case_6[CASE_SIZE] = {
        9,	// tile_width
        9,	// tile_height
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
};

uint8_t sprite_case_7[CASE_SIZE] = {
        9,	// tile_width
        9,	// tile_height
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
};

uint8_t sprite_case_8[CASE_SIZE] = {
        9,	// tile_width
        9,	// tile_height
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
        0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,
};