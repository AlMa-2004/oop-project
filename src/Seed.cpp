#include "../../headers/Seed.h"

//WIP

Seed::Seed(const std::string& n, int c, int price, std::unique_ptr<Crop>& crop)
    :
    Item(n, c, price),
    crop(std::move(crop))
{
}

void Seed::plant(Field& f)
{
}
