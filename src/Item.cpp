#include "../headers/Item.h"

Item::Item(): itemName("UnknownItem"),
              itemQuantity(0),
              itemSellingPrice(10)
{
};

Item::Item(std::string n, const int c = 0, const int price = 10)
    : itemName(std::move(n)),
      itemQuantity(c),
      itemSellingPrice(price)
{
    //std::cout << "Item constructor\n";
}

[[nodiscard]] std::string Item::getName() const { return itemName; }

[[nodiscard]] int Item::getQuantity() const { return itemQuantity; }

void Item::setQuantity(const int c) { itemQuantity = c; }

int Item::calculateSellingPrice(const int c) const
{
    return itemSellingPrice * c;
}

std::ostream& operator<<(std::ostream& os, const Item& obj)
{
    return os << "Item " << obj.itemName << " ( " << obj.itemQuantity << "pcs )\n";
}
