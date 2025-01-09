#ifndef FIELDEXCEPTIONS_H
#define FIELDEXCEPTIONS_H
#include <exception>

/**
 * @class HarvestException
 * @brief Base class for exceptions related to harvesting in the field.
 *
 * This exception serves as a base for all harvesting-related exceptions
 * in the field management system.
 */
class HarvestException : public std::exception
{
public:
    [[nodiscard]] const char* what() const noexcept override
    {
        return "Harvest exception occurred";
    }
};


/**
 * @class EmptyLotException
 * @brief Exception thrown when attempting to harvest from an empty lot.
 *
 * This exception is derived from HarvestException and indicates that the
 * specified lot does not contain any crop to harvest.
 */
class EmptyLotException : public HarvestException
{
public:
    [[nodiscard]] const char* what() const noexcept override
    {
        return "Attempted to harvest from an empty lot";
    }
};

/**
 * @class CropNotFoundException
 * @brief Exception thrown when no crop matching specified criteria is found.
 *
 * This exception is derived from HarvestException and indicates that the
 * desired crop type or condition does not exist in the field.
 */
class CropNotFoundException : public HarvestException
{
public:
    [[nodiscard]] const char* what() const noexcept override
    {
        return "Harvest crop-criteria doesn't exist in the field";
    }
};

#endif //FIELDEXCEPTIONS_H
