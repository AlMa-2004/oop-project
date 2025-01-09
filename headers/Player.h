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

    // Specialized inventories for seeds and harvests
    Inventory<Seed> seedInventory; /**< Inventory for storing seeds. */
    Inventory<Harvest> harvestInventory; /**< Inventory for storing harvested crops. */

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
    explicit Player(std::string name, int money);

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

    // Inventory related methods
    /**
     * @brief Adds a seed to the player's seed inventory.
     * @param seed The seed object to be added.
     */
    void addSeed(const std::shared_ptr<Seed>& seed);

    /**
     * @brief Adds a harvested crop to the player's harvest inventory.
     * @param harvest The harvested crop to be added.
     */
    void addHarvest(const std::shared_ptr<Harvest>& harvest);

    /**
     * @brief Sells a specified quantity of a harvested crop.
     * @param harvestName The name of the harvested crop to be sold.
     * @param quantity The quantity of the harvested crop to be sold.
     */
    void sellHarvest(const std::string& harvestName, int quantity);

    /**
     * @brief Gets a seed from the inventory by its index.
     * @param index The index of the seed in the inventory.
     * @return A shared pointer to the seed.
     */
    [[nodiscard]] std::shared_ptr<Seed> getSeedByIndex(int index) const;
};

#endif // PLAYER_H
