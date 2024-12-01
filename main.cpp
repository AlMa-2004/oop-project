#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <memory>
#include "../../headers/Player.h"
#include "../../headers/Field.h"
#include "../../headers/Seed.h"
#include "../../headers/Tomato.h"
#include "../../headers/Wheat.h"
#include "headers/FieldExceptions.h"

int main()
{
    Player player("Alex", 100);
    Field field(10);
    Tomato tomatoCrop;
    Seed tomatoSeed("Tomato Seed", 10, 5, tomatoCrop.clone());

    sf::Clock clock;

    bool spaceKeyReleased = true;
    bool pKeyReleased = true;

    while (true)
    {
        sf::Time elapsed = clock.getElapsedTime();
        long long currentTime = elapsed.asSeconds();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        {
            if (pKeyReleased)
            {
                std::cout << "Planting tomato seed...\n";
                tomatoSeed.plant(field, 5);
                pKeyReleased = false;
            }
        }
        else
        {
            pKeyReleased = true;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            if (spaceKeyReleased)
            {
                try
                {
                    auto const harvested = field.harvestCropLike<Tomato>();
                    player.addItem(harvested);
                }
                catch (CropNotFoundException& e)
                {
                    std::cout << "Caught specific exception: " << e.what() << std::endl;
                }
                catch (EmptyLotException& e)
                {
                    std::cout << "Caught empty lot exception: " << e.what() << std::endl;
                }
                catch (HarvestException& e)
                {
                    std::cout << "Caught harvest exception: " << e.what() << std::endl;
                }
                catch (std::exception& e)
                {
                    std::cout << "Caught general exception: " << e.what() << std::endl;
                }
                spaceKeyReleased = false;
            }
        }
        else
        {
            spaceKeyReleased = true;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            break;
        }

        field.updateGrowth(currentTime);
    }

    return 0;
}
