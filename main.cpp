#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <memory>
#include "../../headers/Player.h"
#include "../../headers/Field.h"
#include "../../headers/Seed.h"
#include "../../headers/Tomato.h"
#include "../../headers/Wheat.h"

int main() {

    Player player("Alex",100);
    Field field(10);
    Tomato tomatoCrop;
    Seed tomatoSeed("Tomato Seed", 10, 5, tomatoCrop.clone());

    sf::Clock clock;

    while (true) {
        sf::Time elapsed = clock.getElapsedTime();
        long long currentTime = elapsed.asSeconds();


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
            std::cout << "Planting tomato seed...\n";
            tomatoSeed.plant(field, 5);

        }

        field.updateGrowth(currentTime);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
        {
             break;
        }
    //std::cout<<elapsed.asSeconds() << "\n";
    }
    player.addItem(field.harvestCropLike<Wheat>());
    return 0;
}