
#include "playerAction.h"

uint32_t numberOfPossibleBet(t_player player, t_game game) {
    uint32_t bet;
    uint32_t number_of_possible_bet;

    number_of_possible_bet = 0;

    if (game.round.bet) {
        bet = game.round.bet * 2;
    } else {
        bet = game.param.small_blind;
    }

    while (bet < player.bankroll) {
        bet += bet;
        number_of_possible_bet++;
    }
    number_of_possible_bet++;

    return number_of_possible_bet;
}

uint32_t *possibleBet(t_player player, t_game game) {
    uint32_t *possible_bet;
    uint32_t i;
    uint32_t number_of_possible_bet;
    uint32_t bet;

    number_of_possible_bet = numberOfPossibleBet(player, game);

    if (!(possible_bet = malloc(sizeof(uint32_t) * (number_of_possible_bet + 1)))) { return NULL; }

    possible_bet[0] = number_of_possible_bet;

    if (game.round.bet) {
        bet = game.round.bet * 2;
    } else {
        bet = game.param.small_blind;
    }

    for (i = 1; i < number_of_possible_bet; i++) {
        possible_bet[i] = bet;
        bet += bet;
    }
    possible_bet[i] = player.bankroll;

    return possible_bet;
}

int32_t checkAction(t_player player, t_game game) {
    int32_t response;
    uint32_t response2;
    uint32_t *possible_bet;

    printf("-1 : fold | 0 : call | 1 : raise\n");
    scanf("%d", &response);
    if (response < 0) {
        return FOLD;
    }
    if (response == CALL) {
        return CALL;
    }

    possible_bet = possibleBet(player, game);

    printf("Hom much you want to raise ?\n");
    printPossibleBet(possible_bet);
    scanf("%d", &response2);

    free(possible_bet);
    return response2;
}

void playerAction(t_player *players, t_game *game, uint8_t number) {
    int32_t action;

    action = checkAction(players[number], *game);
    if (action == FOLD) {
        players[number].fold = 1;
    } else if (action == CALL) {
        betPlayer(&players[number], game, game->round.bet);
    } else {
        betPlayer(&players[number], game, action);
        setReady(players, game->param.number_of_player);
        game->round.last_raise_id = players[number].number;
        game->round.bet = action;
    }
    players[number].ready = 1;
}