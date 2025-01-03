#ifndef MENUSTATE_H
#define MENUSTATE_H
#include <SFML/Graphics.hpp>
#include "State.h"

class MenuState : public State
{
    static sf::Font font;
    sf::Text menuOptions[3];
    int currentSelection = 0;

public:
    static void loadFont();
    MenuState();
    void handleInput(sf::Event* event) override;
    void update([[maybe_unused]] float elapsedTime) override;
    void draw(sf::RenderWindow* window) override;
};

#endif // MENUSTATE_H
