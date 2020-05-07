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
        static int SelectSuit(char chr);
        static int SelectNbr(char chr);
        static std::pair<Card::Nbr, Card::Suit> CreateCard();
        int Manager(const std::string&);
        void Display();
        std::vector<std::pair<Card::Nbr, Card::Suit>> _table;
        PokerBot _bot;
    };
}
#endif //POKERBOT_GAMEMANAGER_HPP
