#ifndef FIELD_H
#define FIELD_H
#include <vector>
#include <memory>
#include "Crop.h"

class Field
{
    int length;
    std::vector<std::unique_ptr<Crop>> lots;

public:
    //For the simplicity of the game, the field in not a matrix,
    //just a simple line with a few lots
    explicit Field(int l);

    //function to check if a lot is available or not
    [[nodiscard]] int getLotStatus(int x) const;

    [[nodiscard]] int getLength() const;

    //Function that checks if lot is empty and puts
    //a crop there (the conversion from seed to crop)
    //is handled within the seed class
    void plantCrop(int x, std::unique_ptr<Crop> c);

    //calls the grow() function withing the crop class
    void updateGrowth(long long seconds);

    //harvests crop (! actually returns an item that gets
    //transferred later on into the player inventory !) from a certain lot
    //and resets/null the certain lot pointer
    //!This function works polymorphically!
    //Both Item and Crop classes are based classes, but they are never handled
    std::unique_ptr<Item> harvestCrop(int x);
};
#endif //FIELD_H
