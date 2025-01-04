#include <utility>

#include "../headers/Harvest.h"

Harvest::Harvest(const bool& e = false): Item(), isEdibleRaw(e)
{
}

Harvest::Harvest(std::string n, const int c = 0, const int price = 10, const bool& e = false)
    : Item(std::move(n), c, price), isEdibleRaw(e)
{
}

void Harvest::setEdibleRaw(const bool& e)
{
    isEdibleRaw = e;
}

bool Harvest::getEdibleRaw() const
{
    return isEdibleRaw;
}
