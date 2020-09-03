
#ifndef POKER_CHECKHAND_H
#define POKER_CHECKHAND_H

# include <stdint.h>

# include "player.h"
# include "gameInfo.h"

# define NUMBER_OF_CARD_IN_FINAL_HAND (NUMBER_OF_CARD_IN_BOARD + NUMBER_OF_CARD_IN_HAND)
# define NUMBER_OF_CHECKING_FCT 6

uint8_t checkHand(t_card *final_hand);

uint8_t dispatchCheck(t_card *final_hand, t_hand_info hand_info);

uint8_t checkSquare(t_card *final_hand, t_hand_info hand_info);
uint8_t checkFull(t_card *final_hand, t_hand_info hand_info);
uint8_t checkFlush(t_card *final_hand, t_hand_info hand_info);
uint8_t checkThreeOfAKind(t_card *final_hand, t_hand_info hand_info);
uint8_t checkTwoPair(t_card *final_hand, t_hand_info hand_info);
uint8_t checkPair(t_card *final_hand, t_hand_info hand_info);

uint8_t (*checkHandFct[NUMBER_OF_CHECKING_FCT])(t_card *final_hand, t_hand_info hand_info) = {
        &checkSquare,
        &checkFull,
        &checkFlush,
        &checkThreeOfAKind,
        &checkTwoPair,
        &checkPair,
};

#endif //POKER_CHECKHAND_H