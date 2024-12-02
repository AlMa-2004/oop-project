#ifndef TOMATO_H
#define TOMATO_H
#include "Item.h"
#include "Crop.h"

/**
 * @class Tomato
 * @brief Represents a specific type of crop, the Tomato, derived from the Crop base class.
 *
 * The Tomato class inherits from the Crop base class and implements the virtual methods
 * for cloning and harvesting specific to tomato crops.
 */
class Tomato : public Crop
{
public:
    /**
     * @brief Default constructor for the Tomato class.
     *
     * Initializes a Tomato object with default attributes.
     */
    Tomato();

    /**
     * @brief Parameterized constructor for the Tomato class.
     * @param growthTime The time (in seconds) required for the tomato to fully grow.
     * @param plantedTimestamp The timestamp (in seconds since the game started) when the tomato was planted.
     *
     * This constructor allows customization of the tomato's growth time and planting timestamp.
     */
    Tomato(int growthTime, long long plantedTimestamp);

    /**
     * @brief Creates a unique copy of the current Tomato object.
     * @return A unique pointer to a new Tomato object that is a clone of this instance.
     *
     * This method supports the Prototype design pattern, enabling dynamic copying of Tomato objects.
     */
    [[nodiscard]] std::unique_ptr<Crop> clone() const override;

    /**
     * @brief Harvests the Tomato crop and produces a corresponding Item object.
     * @return A shared pointer to an Item object representing the harvested tomato.
     *
     * This method is called when the tomato is ready for harvest. It creates an Item
     * with the name "Tomato" and a predefined selling price.
     */
    [[nodiscard]] std::shared_ptr<Item> harvest() override;
};

#endif // TOMATO_H
