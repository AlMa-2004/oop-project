#ifndef FIELDEXCEPTIONS_H
#define FIELDEXCEPTIONS_H
#include <exception>

class HarvestException : public std::exception
{
public:
    [[nodiscard]] const char* what() const throw()
    {
        return "Harvest exception occurred";
    }
};

class EmptyLotException : public HarvestException
{
public:
    [[nodiscard]] const char* what() const throw()
    {
        return "Attempted to harvest from an empty lot";
    }
};

class CropNotFoundException : public HarvestException
{
public:
    [[nodiscard]] const char* what() const throw()
    {
        return "Harvest crop-criteria doesn't exist in the field";
    }
};

#endif //FIELDEXCEPTIONS_H
