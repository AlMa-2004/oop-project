#include "../headers/Field.h"
#include "../headers/FieldExceptions.h"

Field::Field(const int l): lots(l)
{
}

int Field::getLotStatus(const int x) const
{
    if (lots[x] == nullptr)
        return 0;
    return 1;
}

int Field::getLength() const
{
    return lots.size();
}

void Field::plantCrop(const int x, std::unique_ptr<Crop> c, long long seconds)
{
    c->setTimeStampPlanted(seconds);
    if (lots[x] == nullptr)
    {
        lots[x] = std::move(c);
        // the local copy of the crop pointer with std::move can be used
        //or
        //read from the argument list as a const reference and cloned
    }
}

void Field::updateGrowth(const long long seconds)
{
    for (auto& lot : lots)
    {
        if (lot != nullptr)
            lot->grow(seconds);
    }
}

std::shared_ptr<Item> Field::harvestCrop(const int x)
{
    if (lots[x] != nullptr && lots[x]->getGrowthStatus())
    {
        auto harvested = lots[x]->harvest();
        lots[x].reset();
        return harvested;
    }
    throw EmptyLotException();
}

std::unique_ptr<Crop> Field::getCrop(int lotIndex)
{
    if (lots[lotIndex] != nullptr)
    {
        return std::move(lots[lotIndex]);//due to the pointer's nature, it has to be moved since multiple ownership is restricted
    }
    return nullptr; // If no crop is planted, return nullptr
}
