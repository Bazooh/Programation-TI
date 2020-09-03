
#include "../inc/card.h"

void initCard(t_card *card, uint8_t color, uint8_t value) {
    card->color = color;
    card->value = value;
}

void initCompressCard(t_compress_card *compress_card, t_card card, uint8_t same_color, uint8_t same_value) {
    compress_card->value = card.value;
    compress_card->color = card.color;
    compress_card->same_value = same_value;
    compress_card->same_color = same_color;
}