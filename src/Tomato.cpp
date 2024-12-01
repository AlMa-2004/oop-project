#include "../headers/Tomato.h"

Tomato::Tomato()
    : Crop("Tomato", 2, 0, false)
{
}

Tomato::Tomato(int growthTime, long long plantedTimestamp)
    : Crop("Tomato", growthTime, plantedTimestamp, false)
{
}

[[nodiscard]] std::unique_ptr<Crop> Tomato::clone() const
{
    return std::make_unique<Tomato>(*this);
}

[[nodiscard]] std::shared_ptr<Item> Tomato::harvest()
{
    std::cout << "Harvesting tomatoes!\n";
    return std::make_shared<Item>("Tomato Crate", 20, 10);
}
