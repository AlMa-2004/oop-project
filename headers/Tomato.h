#ifndef TOMATO_H
#define TOMATO_H
#include "Item.h"
#include "Crop.h"

class Tomato : public Crop
{
public:
    Tomato();
    Tomato(int growthTime, long long plantedTimestamp);
    [[nodiscard]] std::unique_ptr<Crop> clone() const override;
    [[nodiscard]] std::unique_ptr<Item> harvest() override;
};

#endif //TOMATO_H
