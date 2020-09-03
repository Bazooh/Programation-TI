
#include "players.h"

t_player *initPlayers(t_game game) {
    t_player *players;
    uint8_t i;
    uint8_t number_of_player = game.param.number_of_player;
    uint32_t money = game.param.money;

    if (!(players = malloc(sizeof(t_player) * number_of_player))) { return NULL; }

    for (i = 0; i < number_of_player; i++) {
        initPlayer(&players[i], money);
        players[i].name[0] = i + 'A';
        players[i].number = i;
    }
    return players;
}