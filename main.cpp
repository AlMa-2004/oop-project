#include <iostream>
#include <ostream>
#include <chrono>
#include <SFML/Graphics.hpp>
#include "headers/Player.h"
using namespace std;

int main() {

    //testing the elapsed time
    Crop wheat("Wheat", 5,0,0,0); // Takes 5 seconds to grow
    bool isPlanted = false; // Flag to ensure the crop is planted only once

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
    sf::Clock clock;
    //gameloop
    while (window.isOpen()) {


        sf::Time elapsed1 = clock.getElapsedTime();
        //cout<<elapsed1.asSeconds()<<endl;

        long long elapsedTime = clock.getElapsedTime().asSeconds();

        // Plant the crop once
        if (!isPlanted) {
            wheat.setWateredStatus(true);
            wheat.setTimeStampPlanted(elapsedTime);
            isPlanted=true;
            std::cout<<"Crop planted at time:"<<elapsedTime<<" seconds.\n";
        }

        // Check crop growth
        wheat.Grow(elapsedTime);


        //to be replaced
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //elapsedTime = clock.getElapsedTime().asSeconds();

        //Crop wheat("wheat",5,elapsedTime,0,1);
        //wheat.Grow(elapsedTime);

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