#ifndef SPLASHSCREENSTATE_H
#define SPLASHSCREENSTATE_H

#include <SFML/Graphics.hpp>
#include "State.h"

class SplashScreenState : public State
{
private:
    sf::Texture logoTexture;
    sf::Sprite logoSprite;
    sf::Clock clock;
    const float duration = 3.0f;

public:
    SplashScreenState();
    void handleInput(sf::Event* event) override;
    void update([[maybe_unused]] float elapsedTime) override;
    void draw(sf::RenderWindow* window) override;
};

#endif //SPLASHSCREENSTATE_H
