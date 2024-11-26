#include "../headers/Tomato.h"

Tomato::Tomato()
    : Crop("Tomato", 120, 0, false, true)
{
}

Tomato::Tomato(int growthTime, long long plantedTimestamp)
    : Crop("Tomato", growthTime, plantedTimestamp, false, false)
{
}

[[nodiscard]] std::unique_ptr<Crop> Tomato::clone() const override
{
    return std::make_unique<Tomato>(*this);
}

[[nodiscard]] std::unique_ptr<Item> Tomato::harvest() override
{
    std::cout << "Harvesting tomatoes!\n";
    return std::make_unique<Item>("Tomato Crate", 20, 10);
}
