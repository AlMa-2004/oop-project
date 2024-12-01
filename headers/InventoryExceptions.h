#ifndef INVENTORYEXCEPTIONS_H
#define INVENTORYEXCEPTIONS_H
#include <exception>


class InventoryException : public std::exception
{
    public:
    [[nodiscard]]const char* what() const throw() override
    {
        return "Item not found in inventory!";
    }
};
#endif //INVENTORYEXCEPTIONS_H
