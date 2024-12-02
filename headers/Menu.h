#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <iostream>
//WIP

/**
 * @class Menu
 * @brief Represents the main menu interface for the game.
 *
 * The Menu class handles the display and interaction with the game's main menu options,
 * such as starting the game, viewing the tutorial, or exiting the application.
 */
class Menu
{
    /**
     * @brief The font used for rendering text in the menu.
     *
     * A static `sf::Font` object shared across all instances of the Menu class
     * to maintain consistent text styling.
     */
    static sf::Font myFont;

    /**
     * @brief Enum representing the available menu options.
     *
     * The menu options include:
     * - START: Starts the game.
     * - TUTORIAL: Displays the game tutorial.
     * - EXIT: Exits the application.
     */
    enum OPTION
    {
        START, ///< Represents the "Start Game" option.
        TUTORIAL, ///< Represents the "Tutorial" option.
        EXIT ///< Represents the "Exit" option.
    };

public:
    /**
     * @brief Displays the main menu and handles user input.
     * @return An integer representing the user's selected menu option.
     *
     * The function waits for user interaction and returns the corresponding option:
     * - 0 for START
     * - 1 for TUTORIAL
     * - 2 for EXIT
     */
    static int showMenu();
};

#endif // MENU_H
