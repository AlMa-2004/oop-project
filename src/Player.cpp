#include <utility>

#include "../headers/Player.h"

Player::Player()
    : playerName("Player"), playerMoney(0)
{
    //::cout << "Default player constructor\n";
}

// Parameterized constructor: initializes player with given name and money
Player::Player(std::string  name, const int money)
    : playerName(std::move(name)), playerMoney(money)
{

}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
    os << "PlayerName: " << player.playerName
        << " Money: " << player.playerMoney
        << " Inventory: ";
    // showInventory();

    return os;
}

void Player::addSeed(const std::shared_ptr<Seed>& seed)
{
    seedInventory.addItem(seed);
}

void Player::addHarvest(const std::shared_ptr<Harvest>& harvest)
{
    harvestInventory.addItem(harvest);
}


void Player::removeSeed(const std::string& seedName, int quantity)
{
    seedInventory.removeItem(seedName, quantity);
}

void Player::removeHarvest(const std::string& harvestName, int quantity)
{
    harvestInventory.removeItem(harvestName, quantity);
}


void Player::sellSeed(const std::string& seedName, int quantity)
{
    seedInventory.sellItem(seedName, quantity, playerMoney);
}

void Player::sellHarvest(const std::string& harvestName, int quantity)
{
    harvestInventory.sellItem(harvestName, quantity, playerMoney);
}


void Player::showSeedInventory() const
{
    std::cout << "Seed Inventory:\n";
    seedInventory.showInventory();
}

void Player::showHarvestInventory() const
{
    std::cout << "Harvest Inventory:\n";
    harvestInventory.showInventory();
}
