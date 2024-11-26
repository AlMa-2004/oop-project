#ifndef SEED_H
#define SEED_H
#include <memory>

#include "Crop.h"
#include "Item.h"
#include "Field.h"

class Seed : public Item
{
private:
    std::unique_ptr<Crop> crop;

public:
    Seed(const std::string& n, int c, int price, std::unique_ptr<Crop>& crop);
    void plant(Field& f);
};
#endif //SEED_H
