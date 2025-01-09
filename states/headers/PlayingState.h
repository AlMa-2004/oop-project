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
 *
 * The PlayingState class manages the core game functionality where the player can plant and harvest crops.
 * It includes the visual representation of the field and crop growth, as well as interactions like planting, harvesting, and selling.
 */
class PlayingState : public State
{
private:
    Field field; /**< The field on which crops are grown. */
    Player player; /**< The player managing the field and crops. */
    int currentLot; /**< The index of the lot currently selected by the player. */
    sf::Clock gameClock; /**< A clock to track elapsed time for crop growth. */

    // Graphics and textures for crops
    sf::Texture tomatoTexture; /**< Texture for tomato crops. */
    sf::Texture wheatTexture; /**< Texture for wheat crops. */
    sf::Texture cornTexture; /**< Texture for corn crops. */
    std::vector<sf::RectangleShape> lots; /**< Visual representation of the field's lots. */

    /**
     * @brief Handles planting of a crop based on the selected seed index.
     * @param seedIndex The index of the selected seed in the player's inventory.
     */
    void handlePlanting(int seedIndex);

    /**
     * @brief Handles the harvesting of the crop in the currently selected lot.
     */
    void handleHarvesting();

    /**
     * @brief Loads textures for the crops.
     * @throws std::runtime_error if any of the crop textures cannot be loaded.
     */
    void loadTextures();

    /**
     * @brief Initializes the visual representation of the field and its lots.
     */
    void initializeFieldVisuals();

public:
    /**
     * @brief Constructor for PlayingState.
     * Initializes the player's inventory with seeds and sets up the field and textures.
     */
    PlayingState();

    /**
     * @brief Destructor for PlayingState.
     * Cleans up resources, if necessary.
     */
    ~PlayingState() override = default;

    /**
     * @brief Handles user input (keyboard events) for gameplay actions.
     * @param event A pointer to the SFML event to handle (e.g., key press).
     */
    void handleInput(sf::Event* event) override;

    /**
     * @brief Updates the game state, such as crop growth and lot status.
     * @param elapsedTime The elapsed time since the last update.
     */
    void update(float elapsedTime) override;

    /**
     * @brief Draws the field, crops, and UI elements to the window.
     * @param window A pointer to the SFML RenderWindow where the game will be rendered.
     */
    void draw(sf::RenderWindow* window) override;
};

#endif // PLAYING_STATE_H
