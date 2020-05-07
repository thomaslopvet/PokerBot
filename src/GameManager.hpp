/*
** PokerBot
** File description:
** Created by thomas.lopvet,
*/
#ifndef POKERBOT_GAMEMANAGER_HPP
#define POKERBOT_GAMEMANAGER_HPP

#include "PokerBot.hpp"

namespace PokerBot {
    class GameManager {
        public:
        GameManager();
        ~GameManager() = default;
        int Shell();

        private:
        std::vector<std::pair<Card::Nbr, Card::Suit>> _table;
        std::vector<PokerBot> _bots;
    };
}
#endif //POKERBOT_GAMEMANAGER_HPP
