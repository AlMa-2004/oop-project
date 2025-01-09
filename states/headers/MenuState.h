#ifndef MENUSTATE_H
#define MENUSTATE_H
#include <SFML/Graphics.hpp>
#include "State.h"

/**
 * @class MenuState
 * @brief Represents the menu state in the game where the player can select different options.
 *
 * The MenuState class is a derived class of State and represents the main menu of the game.
 * It allows the player to choose between options like starting the game, viewing the tutorial, or exiting.
 * The current selection is highlighted, and input is handled to navigate and select options.
 */
class MenuState : public State
{
    /**
     * @brief A static font used for rendering text in the menu.
     */
    static sf::Font font;

    /**
     * @brief Array of text objects representing menu options.
     */
    sf::Text menuOptions[3];

    /**
     * @brief Index of the currently selected menu option.
     */
    int currentSelection = 0;

public:
    /**
     * @brief Loads the font used for menu text.
     * @throws std::runtime_error if the font file cannot be loaded.
     */
    static void loadFont();

    /**
     * @brief Constructor for MenuState.
     * Initializes menu options and loads the font.
     */
    MenuState();

    /**
     * @brief Handles user input (keyboard events) for menu navigation.
     * @param event A pointer to the SFML event to handle (e.g., key press).
     */
    void handleInput(sf::Event* event) override;

    /**
     * @brief Updates the menu (e.g., highlights the selected option).
     * @param elapsedTime The elapsed time since the last update (unused).
     */
    void update([[maybe_unused]] float elapsedTime) override;

    /**
     * @brief Draws the menu to the window.
     * @param window A pointer to the SFML RenderWindow where the menu will be drawn.
     */
    void draw(sf::RenderWindow* window) override;
};

#endif // MENUSTATE_H
