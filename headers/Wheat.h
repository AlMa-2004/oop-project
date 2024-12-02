#ifndef WHEAT_H
#define WHEAT_H

#include "Crop.h"
#include "Item.h"

/**
 * @class Wheat
 * @brief Represents a specific type of crop, the Wheat, derived from the Crop base class.
 *
 * The Wheat class provides implementation for cloning and harvesting, tailored to the behavior
 * of a wheat crop.
 */
class Wheat : public Crop
{
public:
    /**
     * @brief Default constructor for the Wheat class.
     *
     * Initializes a Wheat object with default attributes such as name, growth time, and timestamp.
     */
    Wheat();

    /**
     * @brief Parameterized constructor for the Wheat class.
     * @param growthTime The time (in seconds) required for the wheat to fully grow.
     * @param plantedTimestamp The timestamp (in seconds since the game started) when the wheat was planted.
     *
     * This constructor allows customization of the wheat's growth time and planting timestamp.
     */
    Wheat(int growthTime, long long plantedTimestamp);

    /**
     * @brief Creates a unique copy of the current Wheat object.
     * @return A unique pointer to a new Wheat object that is a clone of this instance.
     *
     * This method supports the Prototype design pattern, allowing the creation of dynamic copies of Wheat objects.
     */
    [[nodiscard]] std::unique_ptr<Crop> clone() const override;

    /**
     * @brief Harvests the Wheat crop and produces a corresponding Item object.
     * @return A shared pointer to an Item object representing the harvested wheat.
     *
     * This method is called when the wheat is ready for harvest. It creates an Item
     * with the name "Wheat" and a predefined selling price.
     */
    [[nodiscard]] std::shared_ptr<Item> harvest() override;
};

#endif // WHEAT_H
