#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <array>
#include <vector>
#include <iostream>
#include "Crop.h"
#include "Item.h"
#include "Animal.h"

class Player
{
    std::string playerName;
    int playerMoney;
    //std::vector<Item> Inventory;
    //std::array<Crop, 5> Field;
    //vector<Animal> Barn;

public:
    //CONSTRUCTORS & DESTRUCTORS
    Player();
    explicit Player(std::string name, int money, const std::vector<Item>& items,
                    const std::array<Crop, 5>& field);
    Player(const Player& p);

    ~Player();

    //OPERATOR OVERLOADING
    Player& operator=(const Player& p);
    friend std::ostream& operator<<(std::ostream& os, const Player& player);

    //INVENTORY MANAGEMENT
    void addItem(const Item& i);

};


#endif //PLAYER_H
