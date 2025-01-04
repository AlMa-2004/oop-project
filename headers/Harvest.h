#ifndef HARVEST_H
#define HARVEST_H

#include "Item.h"

class Harvest : public Item
{
private:
    bool isEdibleRaw;
    public:
    explicit Harvest(const bool& e);
    Harvest(std::string n, int c, int price, const bool& e);
    void setEdibleRaw(const bool& e);
    [[nodiscard]] bool getEdibleRaw() const;

};

#endif //HARVEST_H
