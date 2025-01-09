#include <utility>

#include "../headers/Harvest.h"

Harvest::Harvest(const bool& e): Item(), isEdibleRaw(e)
{
}

Harvest::Harvest(std::string n, const int c, const int price, const bool& e)
    : Item(std::move(n), c, price), isEdibleRaw(e)
{
}

void Harvest::setIsEdibleRaw(const bool& e)
{
    this->isEdibleRaw = e;
}

