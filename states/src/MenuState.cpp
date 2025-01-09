#include "../headers/MenuState.h"
#include "../headers/TutorialState.h"
#include "../headers/PlayingState.h"
#include "../../headers/GameStateManager.h"
#include <iostream>

sf::Font MenuState::font; //static members always have to be initialised outside the class

void MenuState::loadFont()
{
    if (!font.loadFromFile("../fonts/ARCADECLASSIC.ttf"))
    {
        throw std::runtime_error("Could not load font!");
    }
}

MenuState::MenuState()
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

void MenuState::handleInput(sf::Event* event)
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
            switch (currentSelection)
            {
            case 0:
                std::cout << "Start" << std::endl;
                GameStateManager::getInstance().pushState(std::make_unique<PlayingState>());
                break;
            case 1:
                std::cout << "Tutorial" << std::endl;
                GameStateManager::getInstance().pushState(std::make_unique<TutorialState>());
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

void MenuState::update( [[maybe_unused]] float elapsedTime)
{
    for (int i = 0; i < 3; ++i)
    {
        if (i == currentSelection)
        {
            menuOptions[i].setFillColor(sf::Color::Green);
        }
        else
        {
            menuOptions[i].setFillColor(sf::Color::White);
        }
    }
}

void MenuState::draw(sf::RenderWindow* window)
{
    window->clear();
    for (const auto& option : menuOptions)
    {
        window->draw(option);
    }
    window->display();
}
