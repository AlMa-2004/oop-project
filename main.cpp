#include <iostream>
#include <ostream>
#include <chrono>
#include <SFML/Graphics.hpp>
#include "headers/Player.h"
using namespace std;

int main() {

    //create a render window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Agrarian Affair");
    window.setFramerateLimit(60);

    //load font
    sf::Font myFont;
    if (!myFont.loadFromFile("../fonts/ARCADECLASSIC.ttf")) {
        std::cout << "Couldn't load the font!!\n";
        return -1;
    }

    //create text object
    sf::Text text("Welcome to the Game!", myFont, 30);
    text.setFillColor(sf::Color::White);
    text.setPosition(10, 10);

    //gameloop
    while (window.isOpen()) {

        //to be replaced
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //Similar to double buffering
        // Clear the screen
        window.clear();
        // Draw the text
        window.draw(text);
        // Display the frame
        window.display();
    }

    return 0;

}