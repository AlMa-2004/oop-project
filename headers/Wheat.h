#ifndef WHEAT_H
#define WHEAT_H

#include "Crop.h"
#include "Item.h"

class Wheat : public Crop
{
public:
    Wheat();

    Wheat(int growthTime, long long plantedTimestamp);

    [[nodiscard]] std::unique_ptr<Crop> clone() const override;

    [[nodiscard]] std::unique_ptr<Item> harvest() override;
};

#endif // WHEAT_H
