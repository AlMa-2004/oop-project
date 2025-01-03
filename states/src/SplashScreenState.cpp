#include "../headers/SplashScreenState.h"
#include "../headers/MenuState.h"
#include "../../headers/GameStateManager.h"

SplashScreenState::SplashScreenState()
{
    if (!logoTexture.loadFromFile("../assets/logo.png"))
    {
        throw std::runtime_error("Failed to load logo texture!");
    }

    logoSprite.setTexture(logoTexture);
    logoSprite.setPosition(200.f, 150.f);
}

void SplashScreenState::handleInput(sf::Event* event)
{
    if (event->type == sf::Event::KeyPressed || event->type == sf::Event::MouseButtonPressed)
    {
        GameStateManager::getInstance().pushState(std::make_unique<MenuState>());
    }
}

void SplashScreenState::update([[maybe_unused]] float elapsedTime)
{
    if (clock.getElapsedTime().asSeconds() >= duration)
    {
        GameStateManager::getInstance().pushState(std::make_unique<MenuState>());
    }
}

void SplashScreenState::draw(sf::RenderWindow* window)
{
    window->clear();
    window->draw(logoSprite);
    window->display();
}
