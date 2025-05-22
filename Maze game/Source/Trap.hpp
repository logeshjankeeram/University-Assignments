#pragma once

#include <SFML/Graphics.hpp>
#include "Actor.hpp"

class Trap : public Actor
{
private:
    sf::CircleShape shape;
    bool isActive;
    float spawnDelay;

public:
    Trap(const sf::Vector2f &pos, float delay = 0.5f);
    void update(float deltaTime) override;
    void render(sf::RenderWindow &window) override;
    sf::FloatRect getGlobalBounds() const override { return shape.getGlobalBounds(); }
    bool isSpawned() const { return isActive; }
    void activate() { isActive = true; }
};