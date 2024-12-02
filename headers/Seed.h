#ifndef SEED_H
#define SEED_H
#include <memory>
#include "Crop.h"
#include "Item.h"
#include "Field.h"

/**
 * @class Seed
 * @brief Represents a seed item that can be planted in a field to grow crops.
 *
 * The Seed class is derived from the Item class and includes a reference to a Crop object.
 * It allows planting of the crop in available field lots, reducing its quantity accordingly.
 */
class Seed : public Item
{
private:
    /**
     * @brief A unique pointer to a Crop object associated with this seed.
     */
    std::unique_ptr<Crop> crop;

public:
    /**
     * @brief Constructor for creating a Seed object.
     * @param n The name of the seed.
     * @param c The quantity of the seed.
     * @param price The price per unit of the seed.
     * @param crop A unique pointer to the Crop object associated with this seed.
     */
    Seed(const std::string& n, int c, int price, const std::unique_ptr<Crop>& crop);

    /**
     * @brief Plants the seed in available lots within the field.
     * @param f Reference to the Field object where the seeds will be planted.
     * @param c The quantity of seeds to be planted.
     * @return Returns 0 if at least one seed was planted, or -1 if no lots were available.
     */
    int plant(Field& f, int c);
};

#endif // SEED_H
