#ifndef INVENTORYEXCEPTIONS_H
#define INVENTORYEXCEPTIONS_H
#include <exception>

/**
 * @class InventoryException
 * @brief Exception thrown for errors related to inventory management.
 *
 * This exception is used to indicate that a specified item could not
 * be found in the inventory or other inventory-related errors.
 */
class InventoryException : public std::exception
{
    public:
    [[nodiscard]]const char* what() const noexcept override
    {
        return "Item not found in inventory!";
    }
};
#endif //INVENTORYEXCEPTIONS_H
