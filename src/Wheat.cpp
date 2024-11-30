#include <../../headers/Wheat.h>


Wheat::Wheat()
    : Crop("Wheat", 10, 0, false, false)
{
}

Wheat::Wheat(int growthTime, long long plantedTimestamp)
    : Crop("Wheat", growthTime, plantedTimestamp, false, false)
{
}

[[nodiscard]] std::unique_ptr<Crop> Wheat::clone() const
{
    return std::make_unique<Wheat>(*this);
}

[[nodiscard]] std::unique_ptr<Item> Wheat::harvest()
{
    std::cout << "Harvesting wheat\n";
    return std::make_unique<Item>("Wheat Bundle", 10, 5);
}
