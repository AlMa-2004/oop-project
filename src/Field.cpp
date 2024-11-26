#include "../headers/Field.h"

Field::Field(const int l): length(l)
{
}

void Field::plantCrop(const int x, std::unique_ptr<Crop> c)
{
    if (lots[x] == nullptr)
    {
        lots[x] = std::move(c);
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
std::unique_ptr<Item> Field::harvestCrop(const int x)
{
    if (lots[x] != nullptr && lots[x]->getGrowthStatus())
    {
        auto harvested = lots[x]->harvest();
        lots[x].reset();
        return harvested;
    }
    return nullptr;
}