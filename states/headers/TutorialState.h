#ifndef TUTORIALSTATE_H
#define TUTORIALSTATE_H

#include <SFML/Graphics.hpp>
#include "State.h"

class TutorialState : public State
{
private:
    sf::Text tutorialText;
    sf::Font font;

public:
    TutorialState();
    void handleInput(sf::Event* event) override;
    void update([[maybe_unused]] float elapsedTime) override;
    void draw(sf::RenderWindow* window) override;
};

#endif // TUTORIALSTATE_H
