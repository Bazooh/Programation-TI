
#include "../inc/betRound.h"

void initBetFirstRound(t_player *players, t_game *game) {
    uint32_t small_blind;
    uint8_t small_blind_id;
    uint32_t big_blind;
    uint8_t big_blind_id;
    uint8_t first_player_id;

    setFold(players, game->param.number_of_player);

    small_blind = game->param.small_blind;
    small_blind_id = game->small_blind_id;
    big_blind = small_blind * 2;

    if (small_blind_id == game->param.number_of_player - 1) {
        small_blind_id = 0;
    } else {
        small_blind_id++;
    }

    if (small_blind_id == game->param.number_of_player - 1) {
        big_blind_id = 0;
    } else {
        big_blind_id = small_blind_id + 1;
    }

    if (big_blind_id == game->param.number_of_player - 1) {
        first_player_id = 0;
    } else {
        first_player_id = big_blind_id + 1;
    }

    initPlayersBet(players, *game);

    players[small_blind_id].bet[0] = small_blind;
    players[small_blind_id].bankroll -= small_blind;
    players[big_blind_id].bet[0] = big_blind;
    players[big_blind_id].bankroll -= big_blind;

    game->round.last_raise_id = first_player_id;
    game->round.bet = big_blind;
    game->pot = big_blind + small_blind;
    game->param.small_blind = small_blind;
    game->small_blind_id = small_blind_id;
}

void betFirstRound(t_player *players, t_game *game) {
    uint8_t checking_player_id;

    initBetFirstRound(players, game);
    setReady(players, game->param.number_of_player);

    checking_player_id = game->round.last_raise_id;

    while (!checkReady(players, game->param.number_of_player)) {
        if (!players[checking_player_id].fold && players[checking_player_id].bankroll) {
            printf("player : %s\n", players[checking_player_id].name);
            playerAction(players, game, checking_player_id);
            printGameInfo(players, *game);
        }

        checking_player_id++;

        if (checking_player_id >= game->param.number_of_player) {
            checking_player_id = 0;
        }
    }
}

uint8_t player_in_round(t_player *players, t_game *game) {
    uint8_t player_in_round;
    uint8_t i;

    player_in_round = 0;

    for (i = 0; i < game->param.number_of_player; i++) {
        if (!players[i].fold) {
            player_in_round++;
        }
    }
    return player_in_round;
}

void betRound(t_player *players, t_game *game) {
    uint8_t checking_player_id;

    checking_player_id = game->round.last_raise_id;
    setReady(players, game->param.number_of_player);
    initPlayersBet(players, *game);
    game->round.bet = 0;

    while (!checkReady(players, game->param.number_of_player) && player_in_round(players, game) >= 2) {
        if (!players[checking_player_id].fold && players[checking_player_id].bankroll) {
            printf("player : %s\n", players[checking_player_id].name);
            playerAction(players, game, checking_player_id);
            printGameInfo(players, *game);
        }

        checking_player_id++;

        if (checking_player_id >= game->param.number_of_player) {
            checking_player_id = 0;
        }
    }
}