#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>

class Item
{
    std::string itemName;
    int itemQuantity;
    int itemSellingPrice;

public:
    explicit Item(std::string n, int c, int price);

    [[nodiscard]] std::string getName() const;

    [[nodiscard]] int getQuantity() const;

    void setQuantity(int c);

    //Function calculates the selling price of an item and
    //a certain quantity
    [[nodiscard]] int calculateSellingPrice(int c) const;

    friend std::ostream& operator<<(std::ostream& os, const Item& obj);
};
#endif //ITEM_H
