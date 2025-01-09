#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H

#include <stack>
#include <memory>
#include "../states/headers/State.h"

/**
 * @class GameStateManager
 * @brief Singleton class that manages the stack of game states.
 */
class GameStateManager
{
private:
    /**
     * @brief Stack containing the active game states.
     */
    std::stack<std::unique_ptr<State>> states;

    /**
     * @brief Private constructor to enforce the singleton pattern.
     */
    GameStateManager() = default;

public:
    /**
     * @brief Gets the singleton instance of the GameStateManager.
     * @return A reference to the singleton instance.
     */
    static GameStateManager& getInstance();

    /**
     * @brief Pushes a new state onto the stack.
     * @param state The new state to push onto the stack.
     */
    void pushState(std::unique_ptr<State> state);

    /**
     * @brief Pops the current state off the stack.
     */
    void popState();

    /**
     * @brief Passes input events to the current state for handling.
     * @param event Pointer to the SFML event.
     */
    void handleInput(sf::Event* event);

    /**
     * @brief Updates the current state.
     * @param elapsedTime The time elapsed since the last update, in seconds.
     */
    void update(float elapsedTime);

    /**
     * @brief Draws the current state to the given window.
     * @param window Pointer to the SFML render window.
     */
    void draw(sf::RenderWindow* window);
};

#endif //GAMESTATEMANAGER_H