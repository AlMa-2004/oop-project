#ifndef FIELD_H
#define FIELD_H
#include <vector>
#include <memory>
#include <algorithm>
#include "Crop.h"
#include "FieldExceptions.h"

/**
 * @class Field
 * @brief Represents a field containing lots where crops can be planted, grown, and harvested.
 *
 * The Field class manages a linear arrangement of lots where each lot can hold a crop.
 * It provides methods for planting, updating growth, harvesting crops, and querying lot status.
 */
class Field
{
    /**
     * @brief A vector of unique pointers to Crop objects, representing the lots in the field.
     */
    std::vector<std::unique_ptr<Crop>> lots;

public:
    /**
    * @brief Constructs a Field with a specified number of lots.
    * @param l The number of lots in the field.
    *
    * Initializes the field with `l` empty lots.
    * (Field is meant to represent a "line", not a matrix)
    */
    explicit Field(int l);

    /**
     * @brief Checks the status of a specific lot.
     * @param x The index of the lot to check.
     * @return 0 if the lot is empty, otherwise 1.
     */
    [[nodiscard]] int getLotStatus(int x) const;

    /**
    * @brief Retrieves the number of lots in the field.
    * @return The length of the field (number of lots).
    */
    [[nodiscard]] int getLength() const;

    /**
      * @brief Plants a crop in a specified lot.
      * @param x The index of the lot where the crop will be planted.
      * @param c A unique pointer to the Crop object to be planted.
      * @param seconds Takes a timestamp of the elapsed time.
      *
      * Checks if the specified lot is empty and places the crop in it. The conversion from seed
      * to crop is handled by the Seed class.
      */
    void plantCrop(int x, std::unique_ptr<Crop> c, long long seconds);

    /**
      * @brief Updates the growth status of all crops in the field.
      * @param seconds The current timestamp, used to update growth status.
      *
      * Calls the `grow()` function of each Crop object to update its growth status.
      */
    void updateGrowth(long long seconds);

    /**
    * @brief Harvests a crop from a specific lot.
    * @param x The index of the lot to harvest from.
    * @return A shared pointer to an Item object representing the harvested crop.
    *
    * Resets the lot to null after harvesting. The function operates polymorphically, returning
    * an appropriate Item object based on the harvested crop.
    */
    std::shared_ptr<Item> harvestCrop(int x);
    /**
     * @brief Harvests the first crop of a specific type from the field.
     * @tparam T The type of crop to harvest.
     * @return A shared pointer to an Item object representing the harvested crop.
     *
     * Uses dynamic casting to identify crops of type `T`
     * @throws EmptyLotException if all lots are empty.
     * @throws CropNotFoundException if no crops of the desired type are found.
     */
    [[nodiscard]] std::unique_ptr<Crop> getCrop(int lotIndex);

    template <typename T>
    std::shared_ptr<Item> harvestCropLike()
    {
        int ok = 0; //this function can throw 2 different exceptions, this differentiates them
        for (auto& lot : lots)
        {
            if (lot != nullptr)
                if (lot->getGrowthStatus())
                {
                    ok = 1;
                    if (auto* specificCrop = dynamic_cast<T*>(lot.get()))
                    {
                        auto harvested = specificCrop->harvest();
                        lot.reset();
                        return harvested;
                    }
                }
        }
        if (ok == 0)
            throw EmptyLotException();
        else
            throw CropNotFoundException();
    }
};
#endif //FIELD_H
