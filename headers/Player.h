#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include "Inventory.h"
#include "Seed.h"
#include "Harvest.h"
/**
 * @class Player
 * @brief Represents the player in the game, handling inventory, money, and actions related to items.
 *
 * The Player class manages the player's name, money, and inventory. It provides methods
 * for managing items, such as adding, removing, selling, and searching for items in the inventory.
 */
class Player
{
    /**
     * @brief The name of the player.
     */
    std::string playerName;

    /**
     * @brief The amount of money the player currently has.
     */
    int playerMoney;

    //specialised inventories
    Inventory<Seed> seedInventory;
    Inventory<Harvest> harvestInventory;

public:
    // CONSTRUCTORS & DESTRUCTORS

    /**
     * @brief Default constructor that initializes the player with default values.
     * The player's name is set to "Player" and money to 0.
     */
    Player();

    /**
     * @brief Parameterized constructor to initialize the player with a specified name and money.
     * @param name The player's name.
     * @param money The amount of money the player has.
     */
    explicit Player(std::string  name, int money);

    // OPERATOR OVERLOADING

    /**
     * @brief Output stream operator for the Player class.
     * @param os The output stream to write to.
     * @param player The Player object to output.
     * @return The output stream with the player's details.
     *
     * Displays the player's name, money, and inventory.
     */
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
    // inventory related methods
    void addSeed(const std::shared_ptr<Seed>& seed);
    void addHarvest(const std::shared_ptr<Harvest>& harvest);
    void removeSeed(const std::string& seedName, int quantity);
    void removeHarvest(const std::string& harvestName, int quantity);
    void sellSeed(const std::string& seedName, int quantity);
    void sellHarvest(const std::string& harvestName, int quantity);
    void showSeedInventory() const;
    void showHarvestInventory() const;
};
#endif // PLAYER_H
