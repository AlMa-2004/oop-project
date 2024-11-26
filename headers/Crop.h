#ifndef CROP_H
#define CROP_H
#include <string>
#include <iostream>
#include <memory>
#include "../../headers/Item.h"
//base class for the Wheat, Corn, and Tomato classes, provides virtual functions;
//implemented with a Prototype (Clone) Design Pattern to create a proper "linkage"
//between the class Seed and this class' subclasses (see Seed class)
class Crop
{
    protected:
    //This attribute cannot possibly be 0, since t=0 is allocated for initialisation of assets/
    //Everytime a crop object is created (aka planted in the field), this attribute must take the current timestamp
    //of the elapsed in-game time.
    long long timeStampPlanted;

    std::string cropName;

    //how much elapsed time it needs in order to grow
    int cropGrowthTime;

    //attribute which ensures the proper growth of the planted crop;
    //due to the fact that the game loop might iterate through the creation
    //of an object with each frame (while the window is open), we prevent this
    //by making the attribute true (it never really changes its value from true,
    //it's a mere artifice)
    bool isPlanted;

    bool isGrown;

public:
    Crop();
    explicit Crop(std::string name, int growth_time, long long time_stamp_planted,
                  bool planted_status, bool growth_status);
    virtual ~Crop() = default;

    Crop(const Crop &other) = default;
    Crop& operator=(const Crop& other);
    friend std::ostream& operator<<(std::ostream& os, const Crop& obj);

    [[nodiscard]] std::string getName() const;

    //usage: whenever a crop is harvested, this function will return an item
    //with the same name and a certain selling price
    virtual std::unique_ptr<Item> harvest() = 0;

    //returns a smart pointer to crop(base class for wheat, corn, tomatoes) to
    //ensure polymorphic behaviour
    //usage: an instantiation of class Seed will "plant itself" in the field, meaning
    //it will create a clone of the crop it's linked to accordingly and "manually"
    //store it in a lot in the field
    [[nodiscard]] virtual std::unique_ptr<Crop> clone() const = 0;

    //takes the current timestamp, calculates if the necessary times
    //has passed in order to grow the plant and takes action accordingly
    void grow(long long seconds);

    [[nodiscard]] bool getGrowthStatus() const;
};
#endif //CROP_H
