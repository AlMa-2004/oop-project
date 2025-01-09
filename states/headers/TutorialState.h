#ifndef TUTORIALSTATE_H
#define TUTORIALSTATE_H

#include <SFML/Graphics.hpp>
#include "State.h"

/**
 * @class TutorialState
 * @brief Manages the tutorial screen that explains the game mechanics.
 *
 * The TutorialState class displays a tutorial explaining the controls and mechanics of the game. It shows the instructions to the player and allows them to return to the main menu by pressing the 'Esc' key.
 */
class TutorialState : public State
{
private:
    sf::Text tutorialText; /**< Text object that holds the tutorial instructions. */
    sf::Font font; /**< Font used to render the tutorial text. */

public:
    /**
     * @brief Constructor for TutorialState.
     * Initializes the tutorial text with instructions on how to play the game.
     */
    TutorialState();

    /**
     * @brief Handles user input during the tutorial (key press events).
     * @param event The event triggered by user input (e.g., key press).
     */
    void handleInput(sf::Event* event) override;

    /**
     * @brief Updates the tutorial screen (no actions required for this class).
     * @param elapsedTime The time elapsed since the last update (unused).
     */
    void update([[maybe_unused]] float elapsedTime) override;

    /**
     * @brief Draws the tutorial screen onto the render window.
     * @param window The SFML render window where the tutorial text is drawn.
     */
    void draw(sf::RenderWindow* window) override;
};

#endif // TUTORIALSTATE_H
