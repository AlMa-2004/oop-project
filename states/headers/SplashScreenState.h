#ifndef SPLASHSCREENSTATE_H
#define SPLASHSCREENSTATE_H

#include <SFML/Graphics.hpp>
#include "State.h"

/**
 * @class SplashScreenState
 * @brief Manages the splash screen that displays the game logo.
 *
 * The SplashScreenState class handles the display of the splash screen, showing the game's logo for a brief duration or until user input is detected.
 * The splash screen then transitions to the main menu.
 */
class SplashScreenState : public State
{
private:
    sf::Texture logoTexture; /**< Texture holding the game logo image. */
    sf::Sprite logoSprite; /**< Sprite used to render the game logo. */
    sf::Clock clock; /**< Clock to track the elapsed time for the splash screen duration. */
    const float duration = 3.0f; /**< Duration for which the splash screen will be displayed (in seconds). */

public:
    /**
     * @brief Constructor for SplashScreenState.
     * Initializes the logo texture and sets up the logo sprite for rendering.
     */
    SplashScreenState();

    /**
     * @brief Handles user input during the splash screen (key press or mouse click).
     * @param event The event triggered by user input (e.g., key press, mouse click).
     */
    void handleInput(sf::Event* event) override;

    /**
     * @brief Updates the splash screen state. If the duration has passed, it transitions to the menu state.
     * @param elapsedTime The time elapsed since the last update (unused in this method).
     */
    void update([[maybe_unused]] float elapsedTime) override;

    /**
     * @brief Draws the splash screen (logo) onto the render window.
     * @param window The SFML render window where the splash screen is drawn.
     */
    void draw(sf::RenderWindow* window) override;
};

#endif //SPLASHSCREENSTATE_H
