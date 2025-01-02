#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <memory>
#include <thread>
#include "headers/Player.h"
#include "headers/Field.h"
#include "headers/Seed.h"
#include "headers/Tomato.h"
#include "headers/Wheat.h"
#include "headers/Corn.h"
#include "headers/Menu.h"
#include "headers/FieldExceptions.h"
#include "headers/InventoryExceptions.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Menu");
    window.setFramerateLimit(60);

    Menu menu;
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            menu.handleInput(&event);
        }
        menu.update(clock.restart().asSeconds());
        menu.draw(&window);
    }
}

/// OLD GAME LOOP, JUST FOR EXEMPLIFICATION PURPOSES

/*

int displayMenu(const std::string& text)
{
    std::cout << text;
    int choice;
    std::cin >> choice;
    return choice;
}

bool sellItem(Player& player)
{
    std::string itemName;
    int quantity;

    std::cout << "Enter the item name to sell: ";
    std::cin >> itemName;

    std::cout << "Enter the quantity to sell: ";
    std::cin >> quantity;

    try
    {
        player.sellItem(itemName, quantity);
        std::cout << "Sold " << quantity << " of " << itemName << " successfully!\n";
        return true;
    }
    catch (InventoryException& e)
    {
        std::cout << e.what() << "\n";
        return false;
    }
}


int main()
{
    std::string name;
    Field field(10);
    const Tomato tomatoCrop;
    const Wheat wheatCrop;
    const Corn cornCrop;
    Seed tomatoSeed("Tomato Seed", 10, 5, tomatoCrop.clone());
    Seed wheatSeed("Wheat Seed", 10, 5, wheatCrop.clone());
    Seed cornSeed("Corn Seed", 10, 5, cornCrop.clone());

    std::cout << "Welcome to Agrarian Affair!\n";
    std::cout << "Please enter your name:\n";
    std::cin >> name;

    Player player(name, 100);

    std::cout << "You, " << name <<
        ", never thought you were the outdoorsy type. But one day, you decided to throw all of your "
        "urban life and discover what life is truly about: a little bit of a dirt and some plants.\n\n";

    for (int i = 0; i < 5; ++i)
    {
        std::cout << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << std::endl;

    std::cout <<
        "As a welcome gift for joining our farm, you have received 10 seeds of Wheat, Corn, and Tomato crops each!\n";

    player.addItem(std::make_shared<Seed>("Tomato Seed", 10, 21, tomatoCrop.clone()));
    player.addItem(std::make_shared<Seed>("Wheat Seed", 10, 5, wheatCrop.clone()));
    player.addItem(std::make_shared<Seed>("Corn Seed", 10, 10, cornCrop.clone()));

    std::cout << "You now have in your inventory the following items: \n";
    player.showInventory();

    sf::Clock clock;
    bool showMenu = true;
    int option = 0;

    std::string mainMenu =
        "\nMain Menu:\n1.Navigate the field\n2.Navigate the inventory\n";
    std::string fieldMenu =
        "\nField Menu:\n1.Plant Seeds\n2.Harvest Crops\n";
    std::string inventoryMenu =
        "\nInventory Menu:\n1.See Inventory\n2.Sell Item\n";
    std::string plantMenu =
        "\nWhat crop do you want to plant:\n1. Tomato\n2. Wheat\n3. Corn\n";
    std::string harvestMenu = "\nHarvest Menu:\n1. Harvest a specific lot\n2. Harvest crops by type\n";

    while (true)
    {
        sf::Time elapsed = clock.getElapsedTime();
        long long currentTime = elapsed.asSeconds();

        bool exit = false;

        if (showMenu)
        {
            option = displayMenu(mainMenu);
            showMenu = false;
        }

        if (option == 1)
        {
            int fieldOption = displayMenu(fieldMenu);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
            {
                exit = true;
            }

            if (fieldOption == 1)
            {
                int plantChoice = displayMenu(plantMenu);
                int seedCount;
                std::cout << "Enter the number of seeds to plant: ";
                std::cin >> seedCount;

                switch (plantChoice)
                {
                case 1:
                    tomatoSeed.plant(field, seedCount);
                    break;
                case 2:
                    wheatSeed.plant(field, seedCount);
                    break;
                case 3:
                    cornSeed.plant(field, seedCount);
                    break;
                default:
                    std::cout << "Invalid crop choice.\n";
                    break;
                }
            }
            else if (fieldOption == 2)
            {
                int harvestChoice = displayMenu(harvestMenu);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
                {
                    exit = true;
                }

                if (harvestChoice == 1)
                {
                    int lot;
                    std::cout << "Enter the lot number to harvest [0-9]: ";
                    std::cin >> lot;

                    try
                    {
                        auto harvested = field.harvestCrop(lot);
                        player.addItem(harvested);
                    }
                    catch (EmptyLotException& e)
                    {
                        std::cout << e.what() << std::endl;
                    }
                }
                else if (harvestChoice == 2)
                {
                    char cropType;
                    std::cout << "Enter the crop type to harvest (T/W/C for Tomato/Wheat/Corn): ";
                    std::cin >> cropType;

                    try
                    {
                        if (cropType == 'T' || cropType == 't')
                            player.addItem(field.harvestCropLike<Tomato>());
                        else if (cropType == 'W' || cropType == 'w')
                            player.addItem(field.harvestCropLike<Wheat>());
                        else if (cropType == 'C' || cropType == 'c')
                            player.addItem(field.harvestCropLike<Corn>());
                        else
                            std::cout << "Invalid crop type.\n";
                    }
                    catch (HarvestException& e)
                    {
                        std::cout << e.what() << std::endl;
                    }
                }
            }
        }
        else if (option == 2)
        {
            int inventoryOption = displayMenu(inventoryMenu);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
            {
                exit = true;
            }

            if (inventoryOption == 1)
            {
                player.showInventory();
            }
            else if (inventoryOption == 2)
            {
                if (sellItem(player))
                {
                    exit = true;
                }
                else
                {
                    std::cout << "Failed to sell item. Returning to the main menu.\n";
                    exit = true;
                }
            }
        }

        if (exit)
        {
            showMenu = true;
            continue;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1))
        {
            std::cout << "Bye bye!\n";
            break;
        }

        field.updateGrowth(currentTime);
    }


    return 0;
}

 */
