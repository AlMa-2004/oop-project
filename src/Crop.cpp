#include "../headers/Crop.h"

Crop::Crop(): timeStampPlanted(0),
              cropName("Crop"),
              cropGrowthTime(1),
              isPlanted(false),
              isGrown(false)
{
}

Crop::Crop(std::string name, const int growth_time = 0, long long time_stamp_planted = 0,
           const bool growth_status = false, const bool planted_status = false)
    : timeStampPlanted(time_stamp_planted),
      cropName(std::move(name)),
      cropGrowthTime(growth_time),
      isPlanted(planted_status),
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
    if (isGrown == false && isPlanted == true && (seconds - timeStampPlanted) >= cropGrowthTime)
    {
        isGrown = true;
        std::cout << "The crop " << cropName << " has grown!\n";
    }
    //else std::cout << "The crop " << cropName << " is still growing!\n";
}

[[nodiscard]] std::string Crop::getName() const { return cropName; }
[[nodiscard]] bool Crop::getGrowthStatus() const { return isGrown; }
