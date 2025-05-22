#pragma once
#include <SFML/Graphics.hpp>

class Actor
{
protected:
    sf::Vector2f position;

public:
    virtual void update(float deltaTime) = 0;
    virtual void render(sf::RenderWindow &window) = 0;
    virtual sf::FloatRect getGlobalBounds() const = 0;
    sf::Vector2f getPosition() const { return position; }
    virtual ~Actor() = default;
};