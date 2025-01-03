#ifndef CROP_H
#define CROP_H
#include <string>
#include <iostream>
#include <memory>
#include "../../headers/Item.h"

/**
 * @class Crop
 * @brief Represents a generic crop in the farming simulation.
 *
 * The Crop class is the base class for specific crop types like Wheat, Corn, and Tomato.
 * It includes common attributes and virtual functions for crop behavior, enabling polymorphism.
 * Implements the Prototype (Clone) Design Pattern to facilitate linkage with the Seed class.
 */
class Crop
{
protected:
    /**
      * @brief Time when the crop was planted, stored as a timestamp.
      *
      * This is the in-game time at which the crop was planted. The value is non-zero by design,
      * as t=0 is reserved for asset initialization.
      */
    long long timeStampPlanted;

    /**
      * @brief Name of the crop.
      *
      * The crop name is used for display purposes.
      */
    std::string cropName;

    /**
    * @brief Time required for the crop to grow, in seconds.
    *
    * This is the in-game duration needed for the crop to transition from planted to grown.
    */
    int cropGrowthTime;

    /**
    * @brief Status indicating whether the crop has grown.
    *
    * This boolean attribute is true if the crop has finished growing, otherwise false.
    */
    bool isGrown;

public:
    /**
     * @brief Default constructor for the Crop class.
     */
    Crop();

    /**
    * @brief Parameterized constructor for the Crop class.
    * @param name The name of the crop.
    * @param growth_time The time required for the crop to grow, in seconds.
    * @param time_stamp_planted The timestamp when the crop was planted.
    * @param growth_status The initial growth status of the crop.
    *
    * Constructs a Crop object with the given attributes.
    */
    explicit Crop(std::string name, int growth_time, long long time_stamp_planted, bool growth_status);

    /**
    * @brief Virtual destructor for the Crop class.
    */
    virtual ~Crop() = default;

    /**
     * @brief Copy constructor for the Crop class.
     * @param other The Crop object to copy from.
     */
    Crop(const Crop& other) = default;

    /**
    * @brief Assignment operator for the Crop class.
    * @param other The Crop object to assign from.
    * @return A reference to the assigned Crop object.
    */
    Crop& operator=(const Crop& other);

    /**
    * @brief Output stream operator for the Crop class.
    * @param os The output stream.
    * @param obj The Crop object to stream.
    * @return The modified output stream.
    */
    friend std::ostream& operator<<(std::ostream& os, const Crop& obj);

    /**
    * @brief Retrieves the name of the crop.
    * @return The crop's name as a string.
    */
    [[nodiscard]] std::string getName() const;

    /**
    * @brief Harvests the crop and returns an item.
    * @return A shared pointer to an Item representing the harvested crop.
    *
    * This is a pure virtual function that must be implemented by subclasses.
    */
    virtual std::shared_ptr<Item> harvest() = 0;

    /**
     * @brief Creates a clone of the crop.
     * @return A unique pointer to a Crop object.
     *
     * This is a pure virtual function, enabling subclasses to provide specific clone functionality.
     */
    [[nodiscard]] virtual std::unique_ptr<Crop> clone() const = 0;

    /**
     * @brief Updates the growth status of the crop based on elapsed time.
     * @param seconds The current timestamp, used to determine if the crop has grown.
     *
     * This function checks if the necessary time has passed for the crop to grow and updates
     * its growth status accordingly.
     */
    void grow(long long seconds);

     /**
     * @brief Retrieves the growth status of the crop.
     * @return True if the crop is grown, otherwise false.
     */
    [[nodiscard]] bool getGrowthStatus() const;
     void setTimeStampPlanted(long long seconds);
};
#endif //CROP_H
