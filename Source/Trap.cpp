#include "Trap.hpp"

Trap::Trap(const sf::Vector2f &pos, float delay)
    : isActive(false), spawnDelay(delay)
{
    position = pos;
    shape.setRadius(8.0f);
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin(8.0f, 8.0f);
    shape.setPosition(position);
}

void Trap::update(float deltaTime)
{
    if (!isActive)
    {
        spawnDelay -= deltaTime;
        if (spawnDelay <= 0.0f)
        {
            activate();
        }
    }
}

void Trap::render(sf::RenderWindow &window)
{
    if (isActive)
    {
        window.draw(shape);
    }
}