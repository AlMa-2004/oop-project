#ifndef HARVEST_H
#define HARVEST_H

#include "Item.h"

/**
 * @class Harvest
 * @brief Represents an item that is the result of harvesting, which may or may not be edible raw.
 *
 * The Harvest class is derived from the Item class and includes an additional attribute
 * to track whether the harvested item is edible when raw.
 */
class Harvest : public Item
{
private:
    /**
     * @brief A boolean indicating whether the harvested item is edible raw.
     */
    bool isEdibleRaw;

public:
    /**
     * @brief Default constructor for creating a Harvest object with the raw-edible flag set to false.
     * @param e A boolean value indicating if the item is edible raw (default is false).
     */
    explicit Harvest(const bool& e = false);

    /**
     * @brief Constructor for creating a Harvest object with a specified name, quantity, price, and raw-edible flag.
     * @param n The name of the harvest item.
     * @param c The quantity of the harvest item (default is 0).
     * @param price The price per unit of the harvest item (default is 10).
     * @param e A boolean value indicating if the item is edible raw (default is false).
     */
    Harvest(std::string n, int c = 0, int price = 10, const bool& e = false);

    /**
     * @brief Sets whether the harvested item is edible when raw.
     * @param e A boolean value indicating if the item is edible raw.
     */
    void setEdibleRaw(const bool& e);

    /**
     * @brief Retrieves whether the harvested item is edible when raw.
     * @return A boolean value indicating if the item is edible raw.
     */
    [[nodiscard]] bool getEdibleRaw() const;
};

#endif //HARVEST_H
