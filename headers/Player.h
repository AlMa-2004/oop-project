#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "Item.h"

class Player
{
    std::string playerName;
    int playerMoney;
    std::vector<std::unique_ptr<Item>> playerInventory;

public:
    //CONSTRUCTORS & DESTRUCTORS
    Player();
    explicit Player(std::string name, int money);
    //Player(const Player& p);

    //OPERATOR OVERLOADING
    //Player& operator=(const Player& p);
    friend std::ostream& operator<<(std::ostream& os, const Player& player);

    //INVENTORY MANAGEMENT
    void addItem(std::unique_ptr<Item> i);
    std::vector<std::unique_ptr<Item>>::iterator searchItem(const std::string& s);
    void removeItem(const std::string& s, int q);
    void sellItem(const std::string& s, int q);
    void showInventory() const;
};


#endif //PLAYER_H
