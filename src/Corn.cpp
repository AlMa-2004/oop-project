#include "../../headers/Corn.h"

Corn::Corn()
    : Crop("Corn", 5, 0, false, false)
{
}

Corn::Corn(int growthTime, long long plantedTimestamp)
    : Crop("Corn", growthTime, plantedTimestamp, false, false)
{
}

[[nodiscard]] std::unique_ptr<Crop> Corn::clone() const override
{
    return std::make_unique<Corn>(*this);
}

[[nodiscard]] std::unique_ptr<Item> Corn::harvest() override
{
    std::cout << "Harvesting Corn\n";
    return std::make_unique<Item>("Corn Basket", 10, 5);
}

