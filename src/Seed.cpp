#include "../headers/Seed.h"

Seed::Seed(const std::string& n, const int c, const int price,const std::unique_ptr<Crop>& crop)
    :
    Item(n, c, price),
    crop(crop->clone())
{
}

std::unique_ptr<Crop> Seed::getCrop() const {
    return crop->clone();
}

int Seed::plant(Field& f, int lotIndex, long long seconds) {
    auto cropClone = this->getCrop();

    f.plantCrop(lotIndex, std::move(cropClone), seconds);

    this->setQuantity(this->getQuantity() - 1);

    return 0;
}
