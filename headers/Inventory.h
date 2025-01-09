#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
#include "../headers/InventoryExceptions.h"

template <typename T>
class Inventory
{
private:
    std::vector<std::shared_ptr<T>> items;

public:

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

    std::shared_ptr<T> getItem(int index) const
    {
        if (index >= 0 && index < items.size())
        {
            return items[index];
        }
        throw InventoryException();
    }

    void showInventory() const
    {
        for (const auto& item : items)
            std::cout << *item << " ";
    }
};

#endif // INVENTORY_H