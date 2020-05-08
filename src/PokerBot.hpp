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
        explicit PokerBot(unsigned int);
        ~PokerBot() = default;
        std::vector<std::pair<Card::Nbr, Card::Suit>> GetHand();
        std::pair<Response, unsigned int> PlayTurn();
        void AddFunds(unsigned int);
        void AddToHand(std::pair<Card::Nbr, Card::Suit>);
        void SetTable(std::vector<std::pair<Card::Nbr, Card::Suit>>);
        void AddToTable(std::pair<Card::Nbr, Card::Suit>);
        unsigned int GiveFunds(unsigned int);
        unsigned int GetFunds() const;
        void NewGame();
        void NewRound();
        void SetLastPlayInRound(std::pair<Response, unsigned int>, unsigned int);
        //void AddInfos(//) pour dire au bot ce que les joueurs font

        private:
        void MinimumBetCalc();
        std::pair<Response, unsigned int> Simulation();
        int CheckLastPlay() const;
        unsigned int _funds;
        std::vector<std::pair<Card::Nbr, Card::Suit>> _table;
        std::vector<std::pair<Card::Nbr, Card::Suit>> _hand;
        unsigned int _bet;
        unsigned int _totalLastBetInRound;
        std::pair<Response, unsigned int> _lastResponseInRound;
        unsigned int _minimumBet;
        bool _folded;

    };
}
#endif //POKERBOT_POKERBOT_HPP
