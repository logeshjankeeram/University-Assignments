#include "Player.hpp"
#include <cmath>
#include <iostream>

Player::Player() : speed(200.0f), isDead(false)
{
    // i hope this path works on other computers
    if (!texture.loadFromFile("/Users/logeshjankeeram/Desktop/Pacman-Main/build/player.png"))
    {
        std::cerr << "Failed to load player.png" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 30, 30));
    sprite.setOrigin(15.0f, 15.0f);
    position = {0, 0};
    sprite.setPosition(position);
}

void Player::update(float deltaTime)
{
    if (isDead)
        return;

    // this debug stuff helped me figure out which keys were actually working
    for (int k = sf::Keyboard::A; k <= sf::Keyboard::Z; ++k)
    {
        if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(k)))
        {
            std::cout << "Key pressed: " << static_cast<char>('A' + (k - sf::Keyboard::A)) << std::endl;
        }
    }

    sf::Vector2f movement(0.0f, 0.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        movement.y -= 1.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        movement.y += 1.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        movement.x -= 1.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        movement.x += 1.0f;

    // this normalization thing makes diagonal movement not faster
    // i learned this the hard way when my character was zooming
    if (movement.x != 0.0f && movement.y != 0.0f)
    {
        float length = std::sqrt(movement.x * movement.x + movement.y * movement.y);
        movement /= length;
    }

    position += movement * speed * deltaTime;
    sprite.setPosition(position);

    // animation is just changing which part of the sprite sheet we show
    // it's like a flip book but for computers
    if (movement.x != 0.0f || movement.y != 0.0f)
    {
        animationTimer += deltaTime;
        if (animationTimer >= frameDuration)
        {
            animationTimer = 0.0f;
            currentFrame = (currentFrame + 1) % frameCount;
            sprite.setTextureRect(sf::IntRect(currentFrame * 30, 0, 30, 30));
        }
    }
    else
    {
        currentFrame = 0;
        sprite.setTextureRect(sf::IntRect(0, 0, 30, 30));
    }
}

void Player::render(sf::RenderWindow &window)
{
    window.draw(sprite);
}

void Player::reset(const sf::Vector2f &startPos)
{
    position = startPos;
    sprite.setPosition(position);
    isDead = false;
    currentFrame = 0;
    animationTimer = 0.0f;
    sprite.setTextureRect(sf::IntRect(0, 0, 30, 30));
}

float Player::getCollisionRadius() const
{
    return 10.0f;
}

sf::FloatRect Player::getGlobalBounds() const
{
    float r = getCollisionRadius();
    sf::Vector2f center = sprite.getPosition();
    return sf::FloatRect(center.x - r, center.y - r, 2 * r, 2 * r);
}