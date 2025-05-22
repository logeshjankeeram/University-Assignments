#include "Game.hpp"
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <cmath>
#include <filesystem>
#include "Utils.hpp"
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Audio.hpp>

Game::Game(sf::RenderWindow &window)
    : window(window), currentLevel(1), isGameOver(false), trapSpawnInterval(3.0f)
{
    // i hope this font loading works on other computers too
    std::string fontPath = getExecutableDir() + "/arial.ttf";
    if (!font.loadFromFile(fontPath))
    {
        if (!font.loadFromFile("arial.ttf"))
        {
            std::cerr << "Failed to load font\n";
        }
    }

    timeText.setFont(font);
    timeText.setCharacterSize(20);
    timeText.setFillColor(sf::Color::White);
    bestText.setFont(font);
    bestText.setCharacterSize(20);
    bestText.setFillColor(sf::Color::White);
    levelText.setFont(font);
    levelText.setCharacterSize(20);
    levelText.setFillColor(sf::Color::White);

    player = std::make_unique<Player>();
    bestTimes.resize(3, 0.0f);
    loadHighScores();

    debugText.setFont(font);
    debugText.setCharacterSize(16);
    debugText.setFillColor(sf::Color::Green);
    debugText.setPosition(10, 70);

    // sound files are in the Resources/Sounds directory
    std::string soundPath = getExecutableDir() + "/Resources/Sounds/";
    if (!menuBuffer.loadFromFile(soundPath + "menu.ogg"))
        menuBuffer.loadFromFile("Resources/Sounds/menu.ogg");
    if (!levelCompleteBuffer.loadFromFile(soundPath + "level_complete.wav"))
        levelCompleteBuffer.loadFromFile("Resources/Sounds/level_complete.wav");
    if (!gameOverBuffer.loadFromFile(soundPath + "game_over.wav"))
        gameOverBuffer.loadFromFile("Resources/Sounds/game_over.wav");
    menuSound.setBuffer(menuBuffer);
    menuSound.setLoop(true);
    levelCompleteSound.setBuffer(levelCompleteBuffer);
    gameOverSound.setBuffer(gameOverBuffer);
    menuSound.play();
}

void Game::update()
{
    if (state == GameState::MENU)
    {
        if (menuSound.getStatus() != sf::Sound::Playing)
            menuSound.play();
        bool wPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
        bool sPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
        bool upPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
        bool downPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
        bool enterPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Enter);
        if ((wPressed && !prevWPressed) || (upPressed && !prevUpPressed))
        {
            menuSelection = (menuSelection + 1) % 2;
        }
        if ((sPressed && !prevSPressed) || (downPressed && !prevDownPressed))
        {
            menuSelection = (menuSelection + 1) % 2;
        }
        if (enterPressed && !prevEnterPressed)
        {
            if (menuSelection == 0)
            {
                state = GameState::PLAYING;
                resetGame();
            }
            else if (menuSelection == 1)
            {
                window.close();
            }
        }
        prevWPressed = wPressed;
        prevSPressed = sPressed;
        prevUpPressed = upPressed;
        prevDownPressed = downPressed;
        prevEnterPressed = enterPressed;
        return;
    }
    if (state == GameState::PAUSED)
    {
        if (menuSound.getStatus() != sf::Sound::Playing)
            menuSound.play();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            state = GameState::PLAYING;
            frameClock.restart();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            state = GameState::MENU;
        }
        return;
    }
    if (state == GameState::GAME_OVER)
    {
        if (menuSound.getStatus() == sf::Sound::Playing)
            menuSound.stop();
        if (gameOverSound.getStatus() != sf::Sound::Playing)
            gameOverSound.play();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            state = GameState::MENU;
        }
        return;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        state = GameState::PAUSED;
        return;
    }

    if (!timerStarted)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            timerStarted = true;
            gameClock.restart();
            frameClock.restart();
        }
        else
        {
            updateTimer();
            return;
        }
    }

    float deltaTime = frameClock.restart().asSeconds();

    player->update(deltaTime);
    updateTraps();
    checkCollisions();
    updateTimer();

    // this time limit thing is so stressful, i keep dying
    if (gameClock.getElapsedTime().asSeconds() > levelManager.getLevelTime())
    {
        state = GameState::GAME_OVER;
        Game::logDebug("Time's up! Game Over.");
        std::cout << "Time's up! Game Over." << std::endl;
    }

    std::cout << "Current time: " << gameClock.getElapsedTime().asSeconds() << " seconds" << std::endl;
    std::cout << "Level time: " << levelManager.getLevelTime() << " seconds" << std::endl;
    std::cout << "Trap positions: " << levelManager.getTrapPositions().size() << std::endl;

    if (levelManager.isEnd(player->getPosition().x, player->getPosition().y))
    {
        float currentTime = gameClock.getElapsedTime().asSeconds();
        if (bestTimes[levelManager.getCurrentLevel()] == 0 || currentTime < bestTimes[levelManager.getCurrentLevel()])
        {
            bestTimes[levelManager.getCurrentLevel()] = currentTime;
            saveHighScores();
        }
        if (menuSound.getStatus() == sf::Sound::Playing)
            menuSound.stop();
        levelCompleteSound.play();
        levelManager.loadNextLevel();
        player->reset(levelManager.getStartPosition());
        traps.clear();
        gameClock.restart();
        timerStarted = false;
    }
}

void Game::updateTraps()
{
    for (auto &trap : traps)
    {
        trap->update(1.0f / 60.0f);
    }

    // these traps are sneaky, they only appear when you get close
    for (const auto &trapPos : levelManager.getTrapPositions())
    {
        float distance = std::sqrt(std::pow(player->getPosition().x - trapPos.x, 2) + std::pow(player->getPosition().y - trapPos.y, 2));
        if (distance < 20.0f)
        {
            traps.push_back(std::make_unique<Trap>(trapPos, 0.0f));
            Game::logDebug("Trap spawned at: (" + std::to_string(trapPos.x) + ", " + std::to_string(trapPos.y) + ")");
        }
    }
}

void Game::checkCollisions()
{
    for (const auto &wall : levelManager.getWalls())
    {
        if (player->getGlobalBounds().intersects(wall.getGlobalBounds()))
        {
            window.clear(sf::Color::White);
            window.display();
            sf::sleep(sf::milliseconds(200));
            player->kill();
            state = GameState::GAME_OVER;
            return;
        }
    }

    for (const auto &trap : traps)
    {
        if (trap->isSpawned() && trap->getGlobalBounds().intersects(player->getGlobalBounds()))
        {
            window.clear(sf::Color::White);
            window.display();
            sf::sleep(sf::milliseconds(200));
            player->kill();
            state = GameState::GAME_OVER;
            return;
        }
    }
}

void Game::updateTimer()
{
    if (state != GameState::MENU && state != GameState::PAUSED && state != GameState::GAME_OVER)
    {
        float elapsed = timerStarted ? gameClock.getElapsedTime().asSeconds() : 0.0f;
        float remainingTime = levelManager.getLevelTime() - elapsed;
        if (remainingTime < 0.0f)
            remainingTime = 0.0f;
        std::stringstream ss;
        ss << "Time: " << std::fixed << std::setprecision(2) << remainingTime;
        timeText.setString(ss.str());
        bestText.setString("Best: " + std::to_string(static_cast<int>(bestTimes[levelManager.getCurrentLevel()] * 100) / 100.0f));
        levelText.setString("Level: " + std::to_string(levelManager.getCurrentLevel() + 1));
        int baseY = window.getSize().y - 90;
        timeText.setPosition(10, baseY);
        bestText.setPosition(10, baseY + 30);
        levelText.setPosition(10, baseY + 60);
    }
}

void Game::draw()
{
    if (state == GameState::MENU)
    {
        window.clear(sf::Color::Black);
        sf::Text title("Maze Runner", font, 40);
        title.setFillColor(sf::Color::White);
        title.setPosition(window.getSize().x / 2 - title.getLocalBounds().width / 2, 80);
        window.draw(title);
        sf::Text startText("Start Game", font, 28);
        startText.setFillColor(menuSelection == 0 ? sf::Color::Yellow : sf::Color::White);
        startText.setPosition(window.getSize().x / 2 - startText.getLocalBounds().width / 2, 200);
        window.draw(startText);
        sf::Text quitText("Quit", font, 28);
        quitText.setFillColor(menuSelection == 1 ? sf::Color::Yellow : sf::Color::White);
        quitText.setPosition(window.getSize().x / 2 - quitText.getLocalBounds().width / 2, 250);
        window.draw(quitText);
        return;
    }
    if (state == GameState::PAUSED)
    {
        levelManager.draw(window);
        for (const auto &trap : traps)
            trap->render(window);
        player->render(window);
        drawUI();
        sf::Text pausedText("Paused", font, 36);
        pausedText.setFillColor(sf::Color::Red);
        pausedText.setPosition(window.getSize().x / 2 - pausedText.getLocalBounds().width / 2, window.getSize().y / 2 - 60);
        window.draw(pausedText);
        sf::Text resumeText("Press Esc to Resume", font, 24);
        resumeText.setFillColor(sf::Color::White);
        resumeText.setPosition(window.getSize().x / 2 - resumeText.getLocalBounds().width / 2, window.getSize().y / 2);
        window.draw(resumeText);
        sf::Text menuText("Press Enter for Menu", font, 20);
        menuText.setFillColor(sf::Color::White);
        menuText.setPosition(window.getSize().x / 2 - menuText.getLocalBounds().width / 2, window.getSize().y / 2 + 40);
        window.draw(menuText);
        return;
    }
    if (state == GameState::GAME_OVER)
    {
        levelManager.draw(window);
        for (const auto &trap : traps)
            trap->render(window);
        player->render(window);
        drawUI();
        sf::Text gameOverText;
        gameOverText.setFont(font);
        gameOverText.setString("Game Over!");
        gameOverText.setCharacterSize(32);
        gameOverText.setFillColor(sf::Color::Red);
        float x = (window.getSize().x - gameOverText.getLocalBounds().width) / 2.f;
        float y = (window.getSize().y / 2.f) - 40;
        gameOverText.setPosition(x, y);
        window.draw(gameOverText);
        sf::Text restartText;
        restartText.setFont(font);
        restartText.setString("Press Enter to return to menu");
        restartText.setCharacterSize(24);
        restartText.setFillColor(sf::Color::Red);
        float rx = (window.getSize().x - restartText.getLocalBounds().width) / 2.f;
        float ry = (window.getSize().y / 2.f) + 10;
        restartText.setPosition(rx, ry);
        window.draw(restartText);
        return;
    }
    levelManager.draw(window);
    for (const auto &trap : traps)
        trap->render(window);
    player->render(window);
    drawUI();
}

void Game::drawUI()
{
    window.draw(timeText);
    window.draw(bestText);
    window.draw(levelText);
}

void Game::resetGame()
{
    isGameOver = false;
    state = GameState::PLAYING;
    timerStarted = false;
    gameClock.restart();
    frameClock.restart();
    traps.clear();
    levelManager.reset();
    player->reset(levelManager.getStartPosition());
}

void Game::loadHighScores()
{
    std::ifstream file("highscores.txt");
    if (file.is_open())
    {
        for (float &time : bestTimes)
        {
            if (!(file >> time))
                time = 0.0f;
        }
        file.close();
    }
    else
    {
        std::ofstream outFile("highscores.txt");
        if (outFile.is_open())
        {
            for (float time : bestTimes)
                outFile << "0 ";
            outFile.close();
        }
    }
}

void Game::saveHighScores()
{
    std::ofstream file("highscores.txt");
    if (file.is_open())
    {
        for (float time : bestTimes)
            file << time << " ";
        file.close();
    }
}

void Game::logDebug(const std::string &message)
{
    std::ofstream logFile("debug.log", std::ios::app);
    if (logFile.is_open())
    {
        logFile << message << std::endl;
        logFile.close();
    }
}