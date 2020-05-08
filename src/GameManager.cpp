/*
** PokerBot
** File description:
** Created by thomas.lopvet,
*/
#include "GameManager.hpp"

PokerBot::GameManager::GameManager() : _bot(500), _pot(0)
{}

int PokerBot::GameManager::Shell()
{
    std::string str;
    int exit = 0;
    while (exit == 0 && std::cin) {
        std::cout << "> ";
        std::cin >> str;
        exit = Manager(str);
    }
    return 0;
}

int PokerBot::GameManager::Manager(const std::string& str)
{
    std::vector<std::string> args;
    std::pair<Card::Nbr, Card::Suit> card;
    int exit = 0;

    if (str == "quit")
        return (1);
    else if (str == "give") {
        card = CreateCard();
        _bot.AddToHand(card);
        std::cout << "card given to bot." << std::endl;
    }
    else if (str == "table") {
        card = CreateCard();
        _table.emplace_back(card);
        _bot.AddToTable(card);
        std::cout << "card added on the table." << std::endl;
    }
    else if (str == "display")
        Display();
    else if (str == "nextGame") {
        _table.clear();
        _bot.NewGame();
    }
    else if (str == "play") {
      /*  if (_table.size() < 3 || _bot.GetHand().size() != 5)
            std::cout << "hand of bot / table not settled properly." << std::endl;
        else*/
            PlayRound();
    }
    else if (str == "simulate")
        SetPrecedentPlayer();
    return 0;
}

void PokerBot::GameManager::SetPrecedentPlayer()
{
    int exit = 0;
    std::string str;
    std::pair<Response, unsigned int> playerMove;
    unsigned int playerOldBet;

    while (exit == 0 && std::cin) {
        std::cout << "Choose from the actions :\n1 = CALL\n2 = RAISE\n3 = FOLD(not permitted)\n4 = CHECK\n5 = NOFUND(not permitted)\n6 = ERROR(not permitted)\n";
        std::cin >> str;
        if (!str.empty() && (str[0] >= '1' && str[0] <= '6')) {
            playerMove.first = static_cast<Response>(str[0] - '0');
            exit = 1;
        }
    }
    exit = 0;
    while (exit == 0 && std::cin) {
        std::cout << "Enter the amount of dollars which has been bet : " << std::endl;
        std::cin >> str;
        if (!str.empty() && std::stoi(str) >= 0) {
            playerMove.second = std::stoi(str);
            exit = 1;
        }
    }
    exit = 0;
    while (exit == 0 && std::cin) {
        std::cout << "Enter the funds of the prec player before the bet : " << std::endl;
        std::cin >> str;
        if (!str.empty() && std::stoi(str) >= 0) {
            playerOldBet = std::stoi(str);
            exit = 1;
        }
    }
    _bot.SetLastPlayInRound(playerMove, playerOldBet);
}

void PokerBot::GameManager::PlayRound()
{
    std::pair<Response, unsigned int> response = _bot.PlayTurn();

    switch(response.first) {
    case Response::CALL:
        _pot += response.second;
        std::cout << "Bot called and put " << response.second << "$ onto the pot.";
        break;
    case Response::FOLD:
        std::cout << "Bot folded.";
        break;
    case Response::RAISE:
        std::cout << "Bot raised and put " << response.second << "$ onto the pot.";
        break;
    case Response::CHECK:
        std::cout << "Bot checked.";
        break;
    case Response::NOFUND:
        std::cout << "Bot doesn't have money.";
        break;
    case Response::ERROR:
        std::cout << "ERROR : Bot couldn't play. Code : '" << response.second << "'.";
        break;
    default:
        std::cout << "Error : unrecognized response. Response code : '" << response.first << "', second value : '" << response.second << "'.";
    }
    std::cout << std::endl;
}

void PokerBot::GameManager::Display()
{
    std::vector<std::string> numbers {"AS", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king"};
    std::vector<std::string> suits {"spade", "diamond", "heart", "club"};

    std::cout << std::endl << "On the table :" << std::endl;
    for (auto & card : _table)
        std::cout << numbers[card.first - 1] << " of " << suits[card.second - 1] << "   ";
    std::cout << std::endl << "In the bot hand :" << std::endl;
    for (auto & card : _bot.GetHand()) {
        std::cout << numbers[card.first - 1] << " of " << suits[card.second - 1] << "   ";
    }
    std::cout << std::endl;
}

std::pair<PokerBot::Card::Nbr, PokerBot::Card::Suit> PokerBot::GameManager::CreateCard()
{
    int exit = 0;
    std::string str;
    std::pair<Card::Nbr, Card::Suit> card;


    while (exit == 0 && std::cin) {
        std::cout << "number of card : ";
        std::cin >> str;
        if (!str.empty() && SelectNbr(str[0]) != -1) {
            card.first = static_cast<Card::Nbr>(SelectNbr(str[0]));
            exit = 1;
        }
    }
    exit = 0;
    while (exit == 0 && std::cin) {
        std::cout << "suit of card : ";
        std::cin >> str;
        if (!str.empty() && SelectSuit(str[0]) != -1) {
            card.second = static_cast<Card::Suit>(SelectSuit(str[0]));
            exit = 1;
        }
    }
    return card;
}

int PokerBot::GameManager::SelectNbr(char chr)
{
    switch (chr) {
    case 'A':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    case '1':
        return 10;
    case 'J':
        return 11;
    case 'Q':
        return 12;
    case 'K':
        return 13;
    default:
        return -1;
    }
}

int PokerBot::GameManager::SelectSuit(char chr)
{
    switch (chr) {
    case 'S':
        return 1;
    case 'D':
        return 2;
    case 'H':
        return 3;
    case 'C':
        return 4;
    default:
        return -1;
    }
}
