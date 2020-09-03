cmake_minimum_required(VERSION 3.15)
project(Poker C)

set(CMAKE_C_STANDARD 11)

include_directories(inc)


add_executable(Poker
        inc/bet.h
        inc/betRound.h
        inc/card.h
        inc/core.h
        inc/deck.h
        inc/display.h
        inc/gameInfo.h
        inc/initGame.h
        inc/main.h
        inc/player.h
        inc/playerAction.h
        inc/players.h
        inc/round.h
        inc/checkHand.h

        src/bet.c
        src/betRound.c
        src/card.c
        src/core.c
        src/deck.c
        src/display.c
        src/initGame.c
        src/main.c
        src/player.c
        src/playerAction.c
        src/players.c
        src/round.c
        src/checkHand.c)