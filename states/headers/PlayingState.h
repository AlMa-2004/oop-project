#ifndef PLAYING_STATE_H
#define PLAYING_STATE_H

#include "State.h"
#include "../../headers/Field.h"
#include "../../headers/Player.h"
#include <vector>
#include <SFML/Graphics.hpp>

/**
 * @class PlayingState
 * @brief Handles the main gameplay logic and rendering for the field and crops.
 */
class PlayingState : public State
{
private:
    Field field;
    Player player;
    int currentLot;
    sf::Clock gameClock;

    // Graphics and textures
    sf::Texture tomatoTexture;
    sf::Texture wheatTexture;
    sf::Texture cornTexture;
    std::vector<sf::RectangleShape> lots;

    void handlePlanting(int seedIndex);
    void handleHarvesting();

    void loadTextures();
    void initializeFieldVisuals();

public:
    PlayingState();
    ~PlayingState() override = default;

    void handleInput(sf::Event* event) override;
    void update(float elapsedTime) override;
    void draw(sf::RenderWindow* window) override;
};

#endif // PLAYING_STATE_H
