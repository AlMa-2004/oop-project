//
// Created by alexa on 19.11.2024.
//

#include "../headers/Player.h"

Player::Player(): playerName("Player"), playerMoney(0)
{
    std::cout << "Default player constructor\n";
}

Player::Player(std::string name="Player", const int money=0) :
playerName(std::move(name)),
playerMoney(money)
{
    std::cout << "Parameterised player constructor\n";
}

Player::Player(const Player& p):
    playerName(p.playerName),
    playerMoney(p.playerMoney)
{
    std::cout << "Copy player constructor\n";
}

Player::~Player() = default;

//OPERATOR OVERLOADING
Player& Player::operator=(const Player& p)
{
    this->playerName = p.playerName;
    this->playerMoney = p.playerMoney;
    std::cout << "Player assignment\n";
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
    os << "PlayerName: " << player.playerName
        << " Money: " << player.playerMoney
        << " Inventory: ";
    return os;
}

//INVENTORY MANAGEMENT
/*
void Player::addItem(const Item& i)
{
    for (auto& item : Inventory)
    {
        if (item.getName() == i.getName())
        {
            item.setQuantity(item.getQuantity() + i.getQuantity());
            return;
        }
    }
    Inventory.push_back(i);
}
*/