#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <memory>
#include <thread>
#include "Player.h"
#include "Field.h"
#include "Seed.h"
#include "Tomato.h"
#include "Wheat.h"
#include "Corn.h"
#include "../states/headers/MenuState.h"
#include "../states/headers/State.h"
#include "FieldExceptions.h"
#include "InventoryExceptions.h"

//class that hosts the internal clock, rendered window and main game loop
class Game
{
private:
    static sf::RenderWindow gameWindow;
    static sf::Clock gameClock;

public:
    const static int WIDTH = 800;
    const static int HEIGHT = 600;

    static void start();
    static void gameLoop();
};

#endif //GAME_H
