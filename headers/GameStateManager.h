#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H

#include <stack>
#include <memory>
#include "../states/headers/State.h"

//singleton
class GameStateManager
{
private:
    std::stack<std::unique_ptr<State>> states;
    GameStateManager() = default;

public:
    static GameStateManager& getInstance();
    void pushState(std::unique_ptr<State> state);
    void popState();
    void handleInput(sf::Event* event);
    void update(float elapsedTime);
    void draw(sf::RenderWindow* window);
};

#endif //GAMESTATEMANAGER_H
