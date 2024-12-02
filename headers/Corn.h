#ifndef CORN_H
#define CORN_H
#include "Crop.h"
#include "Item.h"

/**
 * @class Corn
 * @brief Represents a specific type of crop: Corn.
 *
 * The Corn class inherits from the Crop base class and provides implementations for
 * cloning and harvesting. Corn has specific attributes and behaviors associated with
 * its growth and harvesting process.
 */
class Corn : public Crop {
public:
    /**
     * @brief Default constructor for Corn.
     *
     * Initializes a Corn object with default values.
     */
    Corn();

    /**
    * @brief Parameterized constructor for Corn.
    * @param growthTime The time required for the corn crop to fully grow (in seconds).
    * @param plantedTimestamp The timestamp indicating when the corn was planted.
    *
    * This constructor initializes the Corn object with specific growth time and
    * planting timestamp, setting its growth and readiness status.
    */
    Corn(int growthTime, long long plantedTimestamp);

    /**
     * @brief Creates a clone of the current Corn object.
     * @return A unique pointer to the cloned Corn object.
     *
     * This function is part of the Prototype Design Pattern, allowing polymorphic
     * creation of Corn objects. Useful when duplicating Corn crops dynamically.
     */
    [[nodiscard]] std::unique_ptr<Crop> clone() const override;

     /**
     * @brief Harvests the Corn crop.
     * @return A shared pointer to an Item object representing the harvested Corn.
     *
     * Harvesting a Corn crop generates an Item with a name, quantity, and selling price
     * based on the Corn crop's attributes. The crop is marked as harvested after this operation.
     */
    [[nodiscard]] std::shared_ptr<Item> harvest() override;
};

#endif //CORN_H