#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <iostream>
class Menu
{
    static sf::Font myFont;
    enum OPTION
    {
        START,
        TUTORIAL,
        EXIT
    };

    public:
    static int showMenu();
};

#endif //MENU_H