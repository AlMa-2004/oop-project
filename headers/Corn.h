#ifndef CORN_H
#define CORN_H
#include "Crop.h"
#include "Item.h"
class Corn : public Crop {
public:
    Corn();

    Corn(int growthTime, long long plantedTimestamp);

    [[nodiscard]] std::unique_ptr<Crop> clone() const override;

    [[nodiscard]] std::unique_ptr<Item> harvest() override;
};

#endif //CORN_H
