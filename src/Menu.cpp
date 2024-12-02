#include "../headers/Menu.h"

//WIP - might be the case to implement a game state manager
sf::Font Menu::myFont; //static members always have to be initialised outside the class

int Menu::showMenu()
{
    if (!myFont.loadFromFile("../fonts/ARCADECLASSIC.ttf")) {
        std::cout << "Couldn't load the font!!\n";
        return -1;
    }

    sf::Text startText("Start", myFont, 50);
    startText.setFillColor(sf::Color::White);
    startText.setPosition(300, 150);

    sf::Text tutorialText("Tutorial", myFont, 50);
    tutorialText.setFillColor(sf::Color::White);
    tutorialText.setPosition(300, 250);

    sf::Text exitText("Exit", myFont, 50);
    exitText.setFillColor(sf::Color::White);
    exitText.setPosition(300, 350);

    sf::Text menuOptions[] = {startText, tutorialText, exitText};

    int currentSelection = 0;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Agrarian Affair");
    window.setFramerateLimit(60);

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Up:

                            if (currentSelection > 0) {
                                currentSelection--;
                            }
                            break;

                        case sf::Keyboard::Down:

                            if (currentSelection < 2) {  // We have 3 options
                                currentSelection++;
                            }
                            break;

                        case sf::Keyboard::Enter:

                            switch (currentSelection)
                            {
                                case START:
                                    std::cout << "Start Game\n";
                                    // Start the game logic here
                                    break;

                                case TUTORIAL:
                                    std::cout << "Tutorial\n";
                                    break;

                                case EXIT:
                                    std::cout << "Exit\n";
                                    window.close();
                                    break;

                                default:
                                    break;
                            }
                            break;

                        default:
                            break;
                    }
                    break;

                default:
                    break;
            }
        }

        for (int i = 0; i < 3; ++i) {
            if (i == currentSelection) {
                menuOptions[i].setFillColor(sf::Color::Green);
            } else {
                menuOptions[i].setFillColor(sf::Color::White);
            }
        }

        // Double buffering
        window.clear();
        // Draw all menu options
        for (int i = 0; i < 3; ++i) {
            window.draw(menuOptions[i]);
        }
        window.display();
    }
    return 0;
}
