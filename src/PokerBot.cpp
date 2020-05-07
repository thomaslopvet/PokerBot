/*
** PokerBot
** File description:
** Created by thomas.lopvet,
*/
#include "PokerBot.hpp"

PokerBot::PokerBot::PokerBot(int startingFunds) : _funds(startingFunds)
{
}

std::vector<std::pair<PokerBot::Card::Nbr, PokerBot::Card::Suit>> PokerBot::PokerBot::GetHand()
{
    return _hand;
}

std::pair<PokerBot::Response, int> PokerBot::PokerBot::PlayTurn()
{
    std::pair<Response, int> res (Response::RAISE, 20);
    return res;
}

void PokerBot::PokerBot::AddFunds(int funds)
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

void PokerBot::PokerBot::GiveFunds(int cost)
{
    _funds -= cost;
}

int PokerBot::PokerBot::GetFunds() const
{
    return _funds;
}
