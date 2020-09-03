
#include "../inc/bet.h"


void withdrawMoney(t_player *player, t_game *game, uint32_t money) {
    uint8_t round_id;

    round_id = game->round.round_id;

    player->bankroll -= money - player->bet[round_id];
    game->pot += money - player->bet[round_id];
    player->bet[round_id] = money;
}

void setFold(t_player *players, uint8_t number_of_player) {
    uint8_t i;

    for (i = 0; i < number_of_player; i++) {
        if (players[i].bankroll) {
            players[i].fold = 0;
        } else {
            players[i].fold = 1;
        }
    }
}

void setReady(t_player *players, uint8_t number_of_player) {
    uint8_t i;

    for (i = 0; i < number_of_player; i++) {
        if (players[i].fold || !players[i].bankroll) {
            players[i].ready = 1;
        } else {
            players[i].ready = 0;
        }
    }
}

void betPlayer(t_player *player, t_game *game, uint32_t bet) {
    bet -= player->bet[game->round.round_id];

    if (player->bankroll >= bet) {
        withdrawMoney(player, game, bet);
    } else {
        withdrawMoney(player, game, player->bankroll);
    }
}

uint8_t checkReady(t_player *players, uint8_t number_of_player) {
    uint8_t i;
    uint8_t check_ready;

    check_ready = 0;

    for (i = 0; i < number_of_player; i++) {
        if (players[i].ready) { check_ready++; }
    }

    if (check_ready == number_of_player) { return 1;}
    return 0;
}

void initPlayersBet(t_player *players, t_game game) {
    uint8_t i;

    for (i = 0; i < game.param.number_of_player; i++) {
        players[i].bet[game.round.round_id] = 0;
    }
}