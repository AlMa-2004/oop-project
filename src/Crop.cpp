#include "../headers/Crop.h"

Crop::Crop(): timeStampPlanted(0),
              cropName("Crop"),
              cropGrowthTime(1),
              isGrown(false)
{
}

Crop::Crop(std::string name, const int growth_time = 1, const long long time_stamp_planted = 0,
           const bool growth_status = false)
    : timeStampPlanted(time_stamp_planted),
      cropName(std::move(name)),
      cropGrowthTime(growth_time),
      isGrown(growth_status)
{
}

Crop& Crop::operator=(const Crop& other)
{
    cropName = other.cropName;
    cropGrowthTime = other.cropGrowthTime;
    isGrown = other.isGrown;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Crop& obj)
{
    os << "cropName: " << obj.cropName
        << " timeStampPlanted: " << obj.timeStampPlanted
        << " cropGrowthTime: " << obj.cropGrowthTime
        << " growthStatus: " << obj.isGrown
        << "\n";
    return os;
}

void Crop::grow(const long long seconds)
{
    if (isGrown == false && (seconds - timeStampPlanted) >= cropGrowthTime)
    {
        isGrown = true;
        std::cout << "The crop " << cropName << " has grown!\n";
    }
    //else std::cout << "The crop " << cropName << " is still growing!\n";
}

[[nodiscard]] std::string Crop::getName() const { return cropName; }
[[nodiscard]] bool Crop::getGrowthStatus() const { return isGrown; }

void Crop::setTimeStampPlanted(const long long seconds)
{
    this->timeStampPlanted = seconds;
}
