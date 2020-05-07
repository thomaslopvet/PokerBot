/*
** PokerBot
** File description:
** Created by thomas.lopvet,
*/
#ifndef POKERBOT_POKERBOT_HPP
#define POKERBOT_POKERBOT_HPP

#include "enum.hpp"

namespace PokerBot {
    class PokerBot {
        public:
        explicit PokerBot(int);
        ~PokerBot() = default;
        std::vector<std::pair<Card::Nbr, Card::Suit>> GetHand();
        std::pair<Response, int> PlayTurn();
        void AddFunds(int);
        void AddToHand(std::pair<Card::Nbr, Card::Suit>);
        void SetTable(std::vector<std::pair<Card::Nbr, Card::Suit>>);
        void AddToTable(std::pair<Card::Nbr, Card::Suit>);
        void GiveFunds(int);
        int GetFunds() const;
        //void AddInfos(//) pour dire au bot ce que les joueurs font

        private:
        int _funds;
        std::vector<std::pair<Card::Nbr, Card::Suit>> _table;
        std::vector<std::pair<Card::Nbr, Card::Suit>> _hand;

    };
}
#endif //POKERBOT_POKERBOT_HPP
