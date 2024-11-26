#include "../../headers/Seed.h"

//WIP

Seed::Seed(const std::string& n,const int c,const int price, std::unique_ptr<Crop>& crop)
    :
    Item(n, c, price),
    crop(std::move(crop))
{
}

int Seed::plant(Field& f, int c)
{
    int plantedSeeds=0;

    for(int i=1;i<=f.getLength();i++)
    {
        if(c==0)
            break;

        if(f.getLotStatus(i)==0)
        {
            f.plantCrop(i,crop->clone());
            plantedSeeds++;
            c--;
        }
    }
    if(plantedSeeds==0)
        return -1;

    this->setQuantity(this->getQuantity()-plantedSeeds);
    return 0;
}