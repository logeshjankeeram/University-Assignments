#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <memory>
#include "Player.hpp"
#include "Trap.hpp"
#include "LevelManager.hpp"

class Game
{
public:
    enum class GameState
    {
        MENU,
        PLAYING,
        PAUSED,
        GAME_OVER
    };

private:
    GameState state = GameState::MENU;
    int menuSelection = 0;
    sf::RenderWindow &window;
    std::unique_ptr<Player> player;
    std::vector<std::unique_ptr<Trap>> traps;
    LevelManager levelManager;

    sf::Clock gameClock;
    sf::Clock trapSpawnClock;
    float trapSpawnInterval;
    int currentLevel;
    bool isGameOver;

    sf::Font font;
    float deltaTime;

    std::vector<float> bestTimes;

    sf::Text debugText;
    static void logDebug(const std::string &message);

    sf::Clock frameClock;

    bool timerStarted = false;

    sf::Text timeText;
    sf::Text bestText;
    sf::Text levelText;

    sf::SoundBuffer menuBuffer;
    sf::SoundBuffer levelCompleteBuffer;
    sf::SoundBuffer gameOverBuffer;
    sf::Sound menuSound;
    sf::Sound levelCompleteSound;
    sf::Sound gameOverSound;

    bool prevWPressed = false;
    bool prevSPressed = false;
    bool prevUpPressed = false;
    bool prevDownPressed = false;
    bool prevEnterPressed = false;

    void handleInput();
    void updateTraps();
    void checkCollisions();
    void updateTimer();
    void drawUI();
    void resetGame();
    void loadHighScores();
    void saveHighScores();

public:
    Game(sf::RenderWindow &window);
    void update();
    void draw();
};