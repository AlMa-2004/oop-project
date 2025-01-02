#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "State.h"


class Menu : public State
{
    static sf::Font font;
    sf::Text menuOptions[3];
    int currentSelection = 0;

public:
    static void loadFont();
    Menu();
    void handleInput(sf::Event* event) override;
    void update(float elapsedTime) override;
    void draw(sf::RenderWindow* window) override;
};

#endif // MENU_H
