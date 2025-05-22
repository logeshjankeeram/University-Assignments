#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class LevelManager
{
public:
    static const int CELL_SIZE = 32;
    LevelManager();
    void reset();
    void loadNextLevel();
    void draw(sf::RenderWindow &window);
    bool isWall(float x, float y) const;
    bool isEnd(float x, float y) const;
    sf::Vector2f getStartPosition() const { return startPos; }
    const std::vector<sf::Vector2f> &getTrapPositions() const { return trapPositions; }
    const std::vector<sf::RectangleShape> &getWalls() const { return walls; }
    int getCurrentLevel() const { return currentLevel; }
    float getLevelTime() const;

private:
    std::vector<std::string> levelFiles;
    std::vector<sf::RectangleShape> walls;
    std::vector<sf::Vector2f> trapPositions;
    sf::RectangleShape endTile;
    sf::Vector2f startPos, endPos;
    int currentLevel;
    void loadMazeFromFile(const std::string &filename);
};