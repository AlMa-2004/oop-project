#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>

/**
 * @class Game
 * @brief Hosts the internal clock, rendered window, and main game loop.
 */
class Game
{
private:
    /**
     * @brief The main game rendering window.
     */
    static sf::RenderWindow gameWindow;

    /**
     * @brief The game clock used to track elapsed time.
     */
    static sf::Clock gameClock;

public:
    /**
     * @brief The width of the game window in pixels.
     */
    static constexpr int WIDTH = 800;

    /**
     * @brief The height of the game window in pixels.
     */
    static constexpr int HEIGHT = 600;

    /**
     * @brief Initializes the game, sets up the window, and starts the game loop.
     */
    static void start();

    /**
     * @brief The main game loop, handling events, updates, and rendering.
     */
    static void gameLoop();
};

#endif //GAME_H
