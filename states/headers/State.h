#ifndef STATE_H
#define STATE_H
#include <SFML/Graphics.hpp>

/**
 * @class State
 * @brief Abstract base class representing a game state.
 *
 * The State class defines the interface for handling input, updating, and rendering in different
 * states of a game or application. Derived classes must implement the abstract methods.
 */
class State
{
public:
    /**
     * @brief Virtual destructor for the State class.
     *
     * Ensures proper cleanup of derived classes when destroyed.
     */
    virtual ~State() = default;

    /**
     * @brief Handles user input for the current state.
     * @param event A pointer to an SFML event that contains information about the input.
     *
     * This method is called to process input events (such as keyboard or mouse events) and
     * respond accordingly within the current state.
     */
    virtual void handleInput(sf::Event *event) = 0;

    /**
     * @brief Updates the logic of the current state.
     * @param elapsedTime The time elapsed since the last update, in seconds.
     *
     * This method is called each frame to update the state logic (e.g., game progress,
     * animations, etc.) based on the elapsed time.
     */
    virtual void update(float elapsedTime) = 0;

    /**
     * @brief Draws the contents of the current state to the window.
     * @param window A pointer to the SFML RenderWindow where the state should be drawn.
     *
     * This method is called to render the state’s visual elements (such as UI, game objects, etc.)
     * to the screen.
     */
    virtual void draw(sf::RenderWindow *window) = 0;
};

#endif //STATE_H
