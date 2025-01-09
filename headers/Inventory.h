#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include "../headers/InventoryExceptions.h"

/**
 * @class Inventory
 * @brief Template class that manages a collection of items with shared properties.
 *
 * The Inventory class provides methods to add, search, remove, and sell items.
 * It uses a vector of shared pointers to manage memory efficiently.
 *
 * @tparam T The type of items stored in the inventory.
 */
template <typename T>
class Inventory
{
private:
    /**
     * @brief The collection of items in the inventory.
     */
    std::vector<std::shared_ptr<T>> items;

public:
    /**
     * @brief Adds an item to the inventory.
     *
     * If an item with the same name exists, its quantity is updated.
     * Otherwise, the new item is added to the inventory.
     *
     * @param item A shared pointer to the item to be added.
     */
    void addItem(const std::shared_ptr<T>& item)
    {
        for (auto& i : items)
        {
            if (i->getName() == item->getName())
            {
                i->setQuantity(i->getQuantity() + item->getQuantity());
                return;
            }
        }
        items.push_back(item);
        std::cout << "Added item: " << item->getName() << " successfully!\n";
    }

    /**
     * @brief Searches for an item by name.
     *
     * @param itemName The name of the item to search for.
     * @return An iterator pointing to the found item.
     * @throws InventoryException if the item is not found.
     */
    typename std::vector<std::shared_ptr<T>>::iterator searchItem(const std::string& itemName)
    {
        auto it = std::find_if(items.begin(), items.end(),
            [&itemName](const std::shared_ptr<T>& item) {
                return item->getName() == itemName;
            });

        if (it == items.end())
        {
            throw InventoryException();
        }
        return it;
    }

    /**
     * @brief Removes a specified quantity of an item from the inventory.
     *
     * If the quantity to be removed matches the item's current quantity, the item is removed completely.
     *
     * @param itemName The name of the item to remove.
     * @param quantity The quantity to remove.
     */
    void removeItem(const std::string& itemName, int quantity)
    {
        auto found = searchItem(itemName);
        if (found != items.end())
        {
            if (quantity == (*found)->getQuantity())
                items.erase(found);
            else
                (*found)->setQuantity((*found)->getQuantity() - quantity);
        }
    }

    /**
     * @brief Sells a specified quantity of an item and updates the player's money.
     *
     * The selling price is calculated by the item's method.
     *
     * @param itemName The name of the item to sell.
     * @param quantity The quantity to sell.
     * @param playerMoney Reference to the player's money to be updated.
     * @throws InventoryException if the item is not found.
     */
    void sellItem(const std::string& itemName, int quantity, int& playerMoney)
    {
        auto found = searchItem(itemName);
        if (found != items.end())
        {
            playerMoney += (*found)->calculateSellingPrice(quantity);
            removeItem(itemName, quantity);
        }
        else
        {
            throw InventoryException();
        }
    }

    /**
     * @brief Retrieves an item by its index in the inventory.
     *
     * @param index The index of the item to retrieve.
     * @return A shared pointer to the item.
     * @throws InventoryException if the index is out of bounds.
     */
    std::shared_ptr<T> getItem(int index) const
    {
        if (index >= 0 && static_cast<size_t>(index) < items.size())
        {
            return items[index];
        }
        throw InventoryException();
    }


    /*
    void showInventory() const
    {
        for (const auto& item : items)
            std::cout << *item << " ";
    }
    */
};

#endif // INVENTORY_H
