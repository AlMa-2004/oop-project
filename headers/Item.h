#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>

/**
 * @class Item
 * @brief Represents an item in the game, such as harvested crops or inventory goods.
 *
 * The Item class manages details such as the item's name, quantity, and selling price.
 * It provides methods for accessing and modifying these attributes, as well as calculating
 * the total selling price for a given quantity.
 */
class Item
{
    /**
     * @brief The name of the item.
     */
    std::string itemName;

    /**
     * @brief The quantity of the item available.
     */
    int itemQuantity;

    /**
     * @brief The selling price of a single unit of the item.
     */
    int itemSellingPrice;

public:
    /**
     * @brief Default constructor for the Item class.
     */
    Item();

    /**
     * @brief Constructs an Item with specified attributes.
     *
     * @param n The name of the item.
     * @param c The initial quantity of the item. Defaults to 0.
     * @param price The selling price per unit of the item. Defaults to 10.
     */
    explicit Item(std::string n, int c = 0, int price = 10);

    /**
     * @brief Retrieves the name of the item.
     *
     * @return The item's name as a string.
     */
    [[nodiscard]] std::string getName() const;

    /**
     * @brief Retrieves the quantity of the item.
     *
     * @return The current quantity of the item.
     */
    [[nodiscard]] int getQuantity() const;

    /**
     * @brief Sets the quantity of the item.
     *
     * @param c The new quantity of the item.
     */
    void setQuantity(int c);

    /**
     * @brief Calculates the total selling price for a given quantity of the item.
     *
     * @param c The quantity of the item to calculate the price for.
     * @return The total selling price for the specified quantity.
     *
     * This function multiplies the specified quantity by the item's unit selling price.
     */
    [[nodiscard]] int calculateSellingPrice(int c) const;

    /**
     * @brief Output stream operator for the Item class.
     *
     * @param os The output stream.
     * @param obj The Item object to output.
     * @return The modified output stream.
     *
     * Displays the item's details, including name, quantity, and selling price.
     */
    friend std::ostream& operator<<(std::ostream& os, const Item& obj);

    /**
     * @brief Virtual destructor for the Item class.
     */
    virtual ~Item() = default;
};

#endif //ITEM_H
