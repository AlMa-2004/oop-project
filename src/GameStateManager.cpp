#include "../headers/GameStateManager.h"

GameStateManager& GameStateManager::getInstance()
{
    static GameStateManager instance;
    return instance;
}

void GameStateManager::pushState(std::unique_ptr<State> state)
{
    states.push(std::move(state));
}

void GameStateManager::popState()
{
    if (!states.empty())
    {
        states.pop();
    }
}

void GameStateManager::handleInput(sf::Event* event)
{
    if (!states.empty())
    {
        states.top()->handleInput(event);
    }
}

void GameStateManager::update(float elapsedTime)
{
    if (!states.empty())
    {
        states.top()->update(elapsedTime);
    }
}

void GameStateManager::draw(sf::RenderWindow* window)
{
    if (!states.empty())
    {
        states.top()->draw(window);
    }
}
