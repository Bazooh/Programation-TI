
#include "checkHand.h"

uint8_t dispatchCheck(t_card *final_hand, t_hand_info hand_info) {
    uint8_t i;
    uint8_t value;

    for (i = 0; i < NUMBER_OF_CHECKING_FCT; i++) {
        value = checkHandFct[i](final_hand, hand_info);
        if (value) { return value; }
    }
    return 7;
}

void initHandInfo(t_card *final_hand, t_hand_info *hand_info) {
    uint8_t i;
    uint8_t j;

    for (i = 0; i < NUMBER_OF_COLOR; i++) {
        hand_info->color[i] = 0;
        for (j = 0; j < NUMBER_OF_CARD_IN_FINAL_HAND; j++) {
            if (final_hand[j].color == i) {
                hand_info->color[i]++;
            }
        }
    }
    for (i = 0; i < NUMBER_OF_VALUE; i++) {
        hand_info->value[i] = 0;
        for (j = 0; j < NUMBER_OF_CARD_IN_FINAL_HAND; j++) {
            if (final_hand[j].value == i) {
                hand_info->value[i]++;
            }
        }
    }
}

uint8_t checkHand(t_card *final_hand) {
    t_hand_info hand_info;

    initHandInfo(final_hand, &hand_info);

}

uint8_t checkStraightFlush() {

}

uint8_t checkSquare(t_card *final_hand, t_hand_info hand_info) {
    uint8_t i;

    for (i = NUMBER_OF_VALUE - 1; i >= 0; i--) {
        if (final_hand[i].value >= 4) { return 1;}
    }
    return 0;
}

uint8_t checkFull(t_card *final_hand, t_hand_info hand_info) {
    uint8_t i;
    uint8_t j;

    for (i = NUMBER_OF_VALUE - 1; i >= 0; i--) {
        if (final_hand[i].value >= 3) {
            for (j = NUMBER_OF_VALUE - 1; j >= 0; j--) {
                if (i != j && final_hand[j].value >= 2) { return 1; }
            }
        }
    }
    return 0;
}

uint8_t checkFlush(t_card *final_hand, t_hand_info hand_info) {
    uint8_t i;

    for (i = NUMBER_OF_COLOR - 1; i >= 0; i--) {
        if (final_hand[i].color >= 5) { return 1;}
    }
    return 0;
}

uint8_t checkStraight() {

}

uint8_t checkThreeOfAKind(t_card *final_hand, t_hand_info hand_info) {
    uint8_t i;

    for (i = NUMBER_OF_VALUE - 1; i >= 0; i--) {
        if (final_hand[i].value >= 3) { return 1;}
    }
    return 0;

}

uint8_t checkTwoPair(t_card *final_hand, t_hand_info hand_info) {
    uint8_t i;
    uint8_t j;

    for (i = NUMBER_OF_VALUE - 1; i >= 0; i--) {
        if (final_hand[i].value >= 2) {
            for (j = NUMBER_OF_VALUE - 1; j >= 0; j--) {
                if (i != j && final_hand[j].value >= 2) { return 1; }
            }
        }
    }
    return 0;

}

uint8_t checkPair(t_card *final_hand, t_hand_info hand_info) {
    uint8_t i;

    for (i = NUMBER_OF_VALUE - 1; i >= 0; i--) {
        if (final_hand[i].value >= 2) { return 1;}
    }
    return 0;

}