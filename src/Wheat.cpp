#include "../headers/Wheat.h"
#include "../headers/Harvest.h"

Wheat::Wheat()
    : Crop("Wheat", 10, 0, false)
{
}

Wheat::Wheat(int growthTime, long long plantedTimestamp)
    : Crop("Wheat", growthTime, plantedTimestamp, false)
{
}

[[nodiscard]] std::unique_ptr<Crop> Wheat::clone() const
{
    return std::make_unique<Wheat>(*this);
}

[[nodiscard]] std::shared_ptr<Item> Wheat::harvest()
{
    std::cout << "Harvesting wheat\n";
    return std::make_shared<Harvest>("Wheat Bundle", 10, 5, false);
}
