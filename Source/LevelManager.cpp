#include "LevelManager.hpp"
#include <iostream>
#include <fstream>
#include "Utils.hpp"

namespace
{
    constexpr float WINDOW_WIDTH = 800.f;
    constexpr float WINDOW_HEIGHT = 600.f;
}

LevelManager::LevelManager() : currentLevel(0)
{
    // i hope these level files exist or we're screwed
    std::string baseDir = getExecutableDir();
    levelFiles = {
        baseDir + "/Resources/Level/level1.txt",
        baseDir + "/Resources/Level/level2.txt",
        baseDir + "/Resources/Level/level3.txt"};
    loadMazeFromFile(levelFiles[0]);
}

void LevelManager::loadMazeFromFile(const std::string &filename)
{
    walls.clear();
    trapPositions.clear();
    std::ifstream file(filename);
    if (!file.is_open())
    {
        // if the file is not in the executable dir, try the current dir
        // this is probably not the best way to do it but it works
        std::ifstream fallbackFile(filename.substr(filename.find_last_of("/") + 1));
        if (!fallbackFile.is_open())
        {
            std::cerr << "Failed to open maze file: " << filename << std::endl;
            return;
        }
        file = std::move(fallbackFile);
    }
    std::vector<std::string> layout;
    std::string line;
    while (std::getline(file, line))
    {
        layout.push_back(line);
    }
    file.close();
    if (layout.empty())
        return;

    // center the maze in the window because it looks better
    float offsetX = (WINDOW_WIDTH - layout[0].size() * CELL_SIZE) / 2.0f;
    float offsetY = (WINDOW_HEIGHT - layout.size() * CELL_SIZE) / 2.0f;

    // this is where the magic happens - converting text to actual game objects
    for (int y = 0; y < layout.size(); ++y)
    {
        for (int x = 0; x < layout[y].size(); ++x)
        {
            if (layout[y][x] == 'w')
            {
                sf::RectangleShape wall({CELL_SIZE, CELL_SIZE});
                wall.setPosition(x * CELL_SIZE + offsetX, y * CELL_SIZE + offsetY);
                wall.setFillColor(sf::Color::Blue);
                walls.push_back(wall);
            }
            else if (layout[y][x] == 'S')
            {
                startPos = {x * CELL_SIZE + CELL_SIZE / 2.0f + offsetX, y * CELL_SIZE + CELL_SIZE / 2.0f + offsetY};
            }
            else if (layout[y][x] == 'E')
            {
                endPos = {x * CELL_SIZE + CELL_SIZE / 2.0f + offsetX, y * CELL_SIZE + CELL_SIZE / 2.0f + offsetY};
                endTile.setSize({CELL_SIZE, CELL_SIZE});
                endTile.setPosition(endPos.x - CELL_SIZE / 2.0f, endPos.y - CELL_SIZE / 2.0f);
                endTile.setFillColor(sf::Color::Yellow);
            }
            else if (layout[y][x] == '.' || layout[y][x] == 'T')
            {
                // both '.' and 'T' are traps, i was too lazy to make them different
                trapPositions.push_back({x * CELL_SIZE + CELL_SIZE / 2.0f + offsetX, y * CELL_SIZE + CELL_SIZE / 2.0f + offsetY});
            }
        }
    }
    std::cout << "Player start position: (" << startPos.x << ", " << startPos.y << ")\n";
    for (const auto &wall : walls)
    {
        auto pos = wall.getPosition();
        std::cout << "Wall at: (" << pos.x << ", " << pos.y << ")\n";
    }
}

void LevelManager::reset()
{
    currentLevel = 0;
    loadMazeFromFile(levelFiles[0]);
}

void LevelManager::loadNextLevel()
{
    currentLevel = (currentLevel + 1) % levelFiles.size();
    loadMazeFromFile(levelFiles[currentLevel]);
}

void LevelManager::draw(sf::RenderWindow &window)
{
    for (const auto &wall : walls)
        window.draw(wall);
    window.draw(endTile);
}

bool LevelManager::isWall(float x, float y) const
{
    for (const auto &wall : walls)
    {
        if (wall.getGlobalBounds().contains(x, y))
            return true;
    }
    return false;
}

bool LevelManager::isEnd(float x, float y) const
{
    return endTile.getGlobalBounds().contains(x, y);
}

float LevelManager::getLevelTime() const
{
    float levelTime = (currentLevel == 0) ? 20.0f : (currentLevel == 1) ? 30.0f
                                                                        : 40.0f;
    std::cout << "Level " << currentLevel + 1 << " timer: " << levelTime << " seconds" << std::endl;
    return levelTime;
}