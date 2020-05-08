/*
** PokerBot
** File description:
** Created by thomas.lopvet,
*/
#ifndef POKERBOT_ENUM_HPP
#define POKERBOT_ENUM_HPP

#include <iostream>
#include <fstream>
#include <iomanip>
#include <ostream>
#include <memory>
#include <vector>
#include <utility>

namespace PokerBot {
    namespace Card {
        enum Nbr {
            ACE = 1,
            TWO = 2,
            THREE = 3,
            FOUR = 4,
            FIVE = 5,
            SIX = 6,
            SEVEN = 7,
            EIGHT = 8,
            NINE = 9,
            TEN = 10,
            JACK = 11,
            QUEEN = 12,
            KING = 13
        };

        enum Suit {
            SPADE = 1,
            DIAMOND = 2,
            HEART = 3,
            CLUB = 4
        };
    }

    enum Response {
        CALL = 1,
        RAISE = 2,
        FOLD = 3,
        CHECK = 4,
        NOFUND = 5,
        ERROR = 6,
    };
}
#endif //POKERBOT_ENUM_HPP
