#include "../headers/Menu.h"

sf::Font Menu::font; //static members always have to be initialised outside the class

void Menu::loadFont()
{
    if (!font.loadFromFile("../fonts/ARCADECLASSIC.ttf"))
    {
        throw std::runtime_error("Could not load font!");
    }
}

Menu::Menu()
{
    try
    {
        loadFont();
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
    }

    menuOptions[0].setString("Start");
    menuOptions[1].setString("Tutorial");
    menuOptions[2].setString("Exit");

    for (int i = 0; i < 3; ++i)
    {
        menuOptions[i].setFont(font);
        menuOptions[i].setPosition(300.f, 150.f + static_cast<float>(i * 100));
        menuOptions[i].setCharacterSize(50);
        menuOptions[i].setFillColor(sf::Color::White);
    }
}

void Menu::handleInput(sf::Event* event)
{
    if (event->type == sf::Event::KeyPressed)
    {
        if (event->key.code == sf::Keyboard::Up)
        {
            currentSelection = (currentSelection > 0) ? currentSelection - 1 : 0;
        }
        else if (event->key.code == sf::Keyboard::Down)
        {
            currentSelection = (currentSelection < 2) ? currentSelection + 1 : 2;
        }
        else if (event->key.code == sf::Keyboard::Enter)
        {
            switch (currentSelection) //temporary, function to be taken over by the game state manager
            {
            case 0:
                std::cout << "Start" << std::endl;
                break;
            case 1:
                std::cout << "Tutorial" << std::endl;
                break;
            case 2:
                std::cout << "Exit" << std::endl;
                exit(0);
            default:
                break;
            }
        }
    }
}

void Menu::update(float elapsedTime)
{
    for (int i = 0; i < 3; ++i)
    {
        if (i == currentSelection)
        {
            menuOptions[i].setFillColor(sf::Color::Green); // Highlight the selected option
        }
        else
        {
            menuOptions[i].setFillColor(sf::Color::White); // Reset color for others
        }
    }
}

void Menu::draw(sf::RenderWindow* window)
{
    window->clear();
    for (const auto& option : menuOptions)
    {
        window->draw(option);
    }
    window->display();
}
