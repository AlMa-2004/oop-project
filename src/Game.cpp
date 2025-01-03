#include "../headers/Game.h"
#include "../headers/GameStateManager.h"
#include "../states/headers/SplashScreenState.h"

sf::RenderWindow Game::gameWindow;
sf::Clock Game::gameClock;

void Game::start()
{
    try
    {
        gameWindow.create(sf::VideoMode(WIDTH, HEIGHT), "Agrarian Affair");
        gameWindow.setFramerateLimit(60);
        GameStateManager::getInstance().pushState(std::make_unique<SplashScreenState>());
        gameLoop();
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
    }
}


void Game::gameLoop()
{
    while (gameWindow.isOpen())
    {
        sf::Event event;
        float elapsedTime = gameClock.restart().asSeconds();

        while (gameWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                gameWindow.close();

            GameStateManager::getInstance().handleInput(&event);
        }

        GameStateManager::getInstance().update(elapsedTime);
        GameStateManager::getInstance().draw(&gameWindow);
    }
}
