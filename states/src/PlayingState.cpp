#include "../headers/PlayingState.h"
#include "../../headers/Tomato.h"
#include "../../headers/Wheat.h"
#include "../../headers/Corn.h"

#include <iostream>
#include <memory>

PlayingState::PlayingState()
    : field(5),
      player("Player", 100),
      currentLot(0)
{
    loadTextures();
    initializeFieldVisuals();
}

void PlayingState::loadTextures()
{
    if (!tomatoTexture.loadFromFile("../assets/tomato.png") ||
        !wheatTexture.loadFromFile("../assets/wheat.png") ||
        !cornTexture.loadFromFile("../assets/corn.png"))
    {
        throw std::runtime_error("Failed to load crop textures.");
    }
}

void PlayingState::initializeFieldVisuals()
{
    for (int i = 0; i < field.getLength(); ++i)
    {
        sf::RectangleShape lot(sf::Vector2f(100, 100));
        lot.setFillColor(sf::Color::Green);
        lot.setPosition(static_cast<float>(150 * i + 50), 200);
        lots.push_back(lot);
    }
}

void PlayingState::handlePlanting(const int seedIndex)
{
    if (auto seed = player.getSeedByIndex(seedIndex))
    {
        if (seed->plant(field, currentLot, static_cast<long long>(gameClock.getElapsedTime().asSeconds()) == 0))
        {
            std::cout << "Successfully planted " << seed->getName() << " in Lot " << currentLot << std::endl;
        }
        else
        {
            std::cout << "No available lots to plant " << seed->getName() << std::endl;
        }
    }
    else
    {
        std::cout << "No seed available in inventory." << std::endl;
    }
}

void PlayingState::handleHarvesting()
{
    try
    {
        auto harvestedItem = field.harvestCrop(currentLot);

        if (auto harvestedHarvest = std::dynamic_pointer_cast<Harvest>(harvestedItem))
        {
            player.addHarvest(harvestedHarvest);
            std::cout << "Harvested crop from Lot " << currentLot << std::endl;
        }
        else
        {
            std::cout << "Harvested item is not a valid Harvest.\n";
        }
    }
    catch (const EmptyLotException&)
    {
        std::cerr << "Lot is empty or crop is not grown." << std::endl;
    }
}

void PlayingState::handleInput(sf::Event* event)
{
    if (event->type == sf::Event::KeyPressed)
    {
        switch (event->key.code)
        {
        case sf::Keyboard::Right:
            currentLot = (currentLot + 1) % field.getLength();
            break;

        case sf::Keyboard::Left:
            currentLot = (currentLot - 1 + field.getLength()) % field.getLength();
            break;

        case sf::Keyboard::F1:
            handlePlanting(0); //tomato index in the seed inventory
            break;

        case sf::Keyboard::F2:
            handlePlanting(1); //tomato index in the seed inventory
            break;

        case sf::Keyboard::F3:
            handlePlanting(2); //tomato index in the seed inventory
            break;

        case sf::Keyboard::Enter:
            handleHarvesting();
            break;

        default:
            break;
        }
    }
}

void PlayingState::update(float elapsedTime)
{
    field.updateGrowth(static_cast<long long>(gameClock.getElapsedTime().asSeconds()));

    for (int i = 0; i < field.getLength(); ++i)
    {
        if (field.getLotStatus(i) == 0)
        {
            lots[i].setFillColor(sf::Color::Green);
        }
        else
        {
            if (field.getCrop(i)->getGrowthStatus())
            {
                lots[i].setFillColor(sf::Color::Yellow);
            }
            else
            {
                lots[i].setFillColor(sf::Color(139, 69, 19)); //brown indicates a seed was planted in the lot
            }
        }
    }
}


void PlayingState::draw(sf::RenderWindow* window)
{
    window->clear();
    for (int i = 0; i < lots.size(); ++i)
    {
        if (i == currentLot)
        {
            lots[i].setOutlineThickness(5);
            lots[i].setOutlineColor(sf::Color::Red);
        }
        else
        {
            lots[i].setOutlineThickness(0);
        }

        window->draw(lots[i]);

        if (field.getLotStatus(i) == 1)
        {
            sf::Sprite cropSprite;

            if ([[maybe_unused]] auto* crop = dynamic_cast<Tomato*>(field.getCrop(i).get()))
            {
                cropSprite.setTexture(tomatoTexture);
            }
            else if ([[maybe_unused]] auto* crop1 = dynamic_cast<Wheat*>(field.getCrop(i).get()))
            {
                cropSprite.setTexture(wheatTexture);
            }
            else if ([[maybe_unused]] auto* crop2 = dynamic_cast<Corn*>(field.getCrop(i).get()))
            {
                cropSprite.setTexture(cornTexture);
            }

            cropSprite.setPosition(lots[i].getPosition());
            window->draw(cropSprite);
        }
    }
    window->display();
}
