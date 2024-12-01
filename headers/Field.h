#ifndef FIELD_H
#define FIELD_H
#include <vector>
#include <memory>
#include "Crop.h"

class Field
{
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
    //This function works polymorphically!
    //Both Item and Crop classes are based classes, but they are never handled
    std::shared_ptr<Item> harvestCrop(int x);

    //this function uses
    //down casting to "sort" through the planted crops in the field
    //and harvests the desired crops
    //as dynamic_cast isn't implemented for unique_ptr's, and we can't
    //know the type until runtime (if's on typeid's are not recommended)
    //usage of a template is the best option
    template <typename T>
    std::shared_ptr<Item> harvestCropLike()
    {
        for (auto& lot : lots)
        {
            if (lot->getGrowthStatus() && lot)
            {
                if (auto* specificCrop = dynamic_cast<T*>(lot.get()))
                {
                    auto harvested = specificCrop->harvest();
                    lot.reset();
                    return harvested;
                }
            }
        }
        return nullptr;
    }
};
#endif //FIELD_H
