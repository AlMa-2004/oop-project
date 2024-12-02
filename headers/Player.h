#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include "Item.h"

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

    /**
     * @brief The inventory of the player, which stores items in shared pointers.
     */
    std::vector<std::shared_ptr<Item>> playerInventory;

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

    // INVENTORY MANAGEMENT

    /**
     * @brief Adds an item to the player's inventory.
     * @param i A shared pointer to the Item to be added.
     *
     * If the item already exists in the inventory, its quantity is increased by the
     * quantity of the added item. Otherwise, the item is added to the inventory.
     */
    void addItem(const std::shared_ptr<Item>& i);

    /**
     * @brief Searches for an item in the player's inventory.
     * @param itemName The name of the item to search for.
     * @return An iterator to the item if found.
     * @throws InventoryException If the item is not found in the inventory.
     */
    std::vector<std::shared_ptr<Item>>::iterator searchItem(const std::string& itemName);

    /**
     * @brief Removes an item from the player's inventory.
     * @param s The name of the item to be removed.
     * @param q The quantity of the item to remove.
     * @throws InventoryException If the item is not found in the inventory.
     *
     * If the quantity of the item is exactly the amount in the inventory, the item is
     * completely removed. Otherwise, the item's quantity is decreased.
     */
    void removeItem(const std::string& s, int q);

    /**
     * @brief Sells an item from the player's inventory.
     * @param s The name of the item to sell.
     * @param q The quantity of the item to sell.
     *
     * The item is removed from the inventory, and the player's money is increased by
     * the total selling price of the sold items.
     */
    void sellItem(const std::string& s, int q);

    /**
     * @brief Displays the player's inventory.
     *
     * This function prints all items currently in the player's inventory to the console.
     */
    void showInventory() const;
};

#endif // PLAYER_H
