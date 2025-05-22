#pragma once

#include <SFML/Graphics.hpp>
#include "Actor.hpp"

class Player : public Actor
{
private:
    sf::CircleShape shape;
    float speed;
    bool isDead;
    sf::Texture texture;
    sf::Sprite sprite;
    int currentFrame = 0;
    float animationTimer = 0.0f;
    const int frameCount = 3;
    const float frameDuration = 0.15f; // seconds per frame

public:
    Player();
    void update(float deltaTime) override;
    void render(sf::RenderWindow &window) override;
    sf::FloatRect getGlobalBounds() const override;
    void reset(const sf::Vector2f &startPos);
    bool isAlive() const { return !isDead; }
    void kill() { isDead = true; }
    void setPosition(const sf::Vector2f &pos)
    {
        position = pos;
        sprite.setPosition(pos);
    }
    float getCollisionRadius() const;
};