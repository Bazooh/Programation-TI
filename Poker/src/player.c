
#include "player.h"

void initPlayerName(t_player *player) {
    uint8_t i;

    for (i = 0; i <= MAX_CHAR_IN_NAME; i++) {
        player->name[i] = '\0';
    }
}

void initPlayerHand(t_player *player) {
    uint8_t i;
    t_card null_card;

    initCard(&null_card, 0, 0);

    for (i = 0; i < NUMBER_OF_CARD_IN_HAND; i++) {
        player->hand[i] = null_card;
    }
}

void initPlayerPassword(t_player *player) {
    player->password = 0;
}

void initPlayer(t_player *player, uint32_t start_money) {
    initPlayerName(player);
    initPlayerPassword(player);
    player->bankroll = start_money;
    initPlayerHand(player);
    player->ready = 0;
    player->fold = 0;
}