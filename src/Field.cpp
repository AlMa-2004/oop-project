#include "../headers/Field.h"

Field::Field(const int l): lots(l)
{
}

int Field::getLotStatus(const int x) const
{
    if (lots[x] == nullptr)
        return 0;
    return 1;
}
int Field:: getLength() const {
    return lots.size();
}

void Field::plantCrop(const int x, std::unique_ptr<Crop> c)
{
    if (lots[x] == nullptr)
    {
        lots[x] = std::move(c);
        //i can either use the local copy of the crop pointer with std::move
        //or
        //read it from the argument list as a const reference and clone that
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

//inspired from AI-generated content
std::shared_ptr<Item> Field::harvestCrop(const int x)
{
    if (lots[x] != nullptr && lots[x]->getGrowthStatus())
    {
        auto harvested = lots[x]->harvest();
        lots[x].reset();
        return harvested;
    }
    return nullptr;
}
