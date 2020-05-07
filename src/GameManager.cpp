/*
** PokerBot
** File description:
** Created by thomas.lopvet,
*/
#include "GameManager.hpp"

PokerBot::GameManager::GameManager() = default;

int response(const std::string& str)
{
    if (str == "quit")
        return (1);

    return (0);
}

int PokerBot::GameManager::Shell()
{
    std::string str;
    int exit = 0;
    while (exit == 0 && std::cin) {
        std::cout << "> ";
        std::cin >> str;
        exit = response(str);
    }
    return 0;
}
