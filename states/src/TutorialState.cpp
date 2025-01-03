#include "../headers/TutorialState.h"
#include "../../headers/GameStateManager.h"
#include "../headers/MenuState.h"

TutorialState::TutorialState()
{
    if (!font.loadFromFile("../fonts/ARCADECLASSIC.ttf"))
    {
        throw std::runtime_error("Couldn't to load font!");
    }

    // Set up the tutorial text
    tutorialText.setFont(font);
    tutorialText.setString(
        "Tutorial\n\n"
        "Use the left and right arrow keys and \n to navigate between the field lots\n\n"
        "Once a lot is highlighted you can to interact with it\n\n"
        "If the lot is empty pressing F1 or F2 or F3 will \n plant the corresponding seed from your inventory\n\n"
        "If the lot has a grown crop pressing Enter will harvest the crop\n\n"
        "Pressing H will enable you to harvest only crops of\n a given type\n\n"
        "Pressing one of the numbers 1 through 6 will open a \n prompt for selling the item requiring the quantity\n\n"
        "Press 'Esc' to return to the menu");
    tutorialText.setCharacterSize(30);
    tutorialText.setFillColor(sf::Color::White);
    tutorialText.setPosition(10.f, 10.f);
}

void TutorialState::handleInput(sf::Event* event)
{
    if (event->type == sf::Event::KeyPressed)
    {
        if (event->key.code == sf::Keyboard::Escape)
        {
            GameStateManager::getInstance().popState();
        }
    }
}

void TutorialState::update([[maybe_unused]] float elapsedTime)
{
}

void TutorialState::draw(sf::RenderWindow* window)
{
    window->clear();
    window->draw(tutorialText);
    window->display();
}
