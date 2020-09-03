
#ifndef POKER_CARD_H
#define POKER_CARD_H

# include <stdint.h>

# define NUMBER_OF_COLOR 4
# define NUMBER_OF_VALUE 13

typedef struct s_card {
    uint8_t value;
    uint8_t color;
}              t_card;

void initCard(t_card *card, uint8_t color, uint8_t value);
void initCompressCard(t_compress_card *compress_card, t_card card, uint8_t same_color, uint8_t same_value);

#endif //POKER_CARD_H
