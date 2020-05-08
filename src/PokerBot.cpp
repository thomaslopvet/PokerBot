/*
** PokerBot
** File description:
** Created by thomas.lopvet,
*/
#include "PokerBot.hpp"

PokerBot::PokerBot::PokerBot(unsigned int startingFunds) : _funds(startingFunds), _bet(0), _totalLastBetInRound(0), _lastResponseInRound(Response::ERROR, 0), _minimumBet(0), _folded(false)
{
}

std::vector<std::pair<PokerBot::Card::Nbr, PokerBot::Card::Suit>> PokerBot::PokerBot::GetHand()
{
    return _hand;
}

std::pair<PokerBot::Response, unsigned int> PokerBot::PokerBot::PlayTurn()
{
    std::pair<Response, unsigned int> res (Response::ERROR, 0);
    int err = CheckLastPlay();

    if (err)
        res.second = err;
    else if (_funds == 0)
        res.first = NOFUND;
    else if (_folded)
        res.first = FOLD;
    else {
        MinimumBetCalc();
        res = Simulation();
    }
    return res;
}

std::pair<PokerBot::Response, unsigned int> PokerBot::PokerBot::Simulation()
{
    //minimum raise = _lastResponseInRound.second
    return {CALL, GiveFunds(_minimumBet)};
}

void PokerBot::PokerBot::MinimumBetCalc()
{
    if (_lastResponseInRound.first == ERROR) {
        _minimumBet = _totalLastBetInRound;
        _lastResponseInRound.second = _totalLastBetInRound;
    }
    else
        _minimumBet = _totalLastBetInRound + _lastResponseInRound.second - _bet;
}

void PokerBot::PokerBot::AddFunds(unsigned int funds)
{
    _funds += funds;
}

void PokerBot::PokerBot::AddToHand(std::pair<Card::Nbr, Card::Suit> card)
{
    _hand.emplace_back(card);
}

void PokerBot::PokerBot::SetTable(std::vector<std::pair<Card::Nbr, Card::Suit>> table)
{
    _table = std::move(table);
}

void PokerBot::PokerBot::AddToTable(std::pair<Card::Nbr, Card::Suit> card)
{
    _table.emplace_back(card);
}

unsigned int PokerBot::PokerBot::GiveFunds(unsigned int cost)
{
    unsigned int given = 0;

    if (_funds < cost) {
        given = _funds;
        _funds = 0;
    }
    else {
        _funds -= cost;
        given = cost;
    }
    _bet += given;
    return given;
}

unsigned int PokerBot::PokerBot::GetFunds() const
{
    return _funds;
}

void PokerBot::PokerBot::NewGame()
{
    _table.clear();
    _hand.clear();
    _bet = 0;
    _totalLastBetInRound = 0;
    _lastResponseInRound = {ERROR, 0};
    _minimumBet = 0;
    _folded = false;
}

void PokerBot::PokerBot::NewRound()
{
    _totalLastBetInRound = 0;
    _lastResponseInRound = {ERROR, 0};
    _minimumBet = 0;
}

void PokerBot::PokerBot::SetLastPlayInRound(std::pair<Response, unsigned int> response, unsigned int totalBet)
{
    _lastResponseInRound = response;
    _totalLastBetInRound = totalBet;
}

int PokerBot::PokerBot::CheckLastPlay() const
{
    int nbr = _lastResponseInRound.second;

    switch (_lastResponseInRound.first) {
    case ERROR:
        if (nbr != 0)
            return 1;
        break;
    case FOLD:
        if (nbr == 0 && _totalLastBetInRound == 0)
            return 2;
        break;
    case NOFUND:
        return 3;
    case CHECK:
        if (nbr > 0 || _totalLastBetInRound == 0)
            return 2;
        break;
    case RAISE:
        if (nbr <= 1)
            return 2;
        break;
    case CALL:
        if (nbr == 0)
            return 2;
    }
    return 0;
}
