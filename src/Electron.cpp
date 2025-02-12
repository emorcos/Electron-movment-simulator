#ifndef ELECTRON_H
#define ELECTRON_H

#include <SFML/Graphics.hpp>
#include <queue>

class Electron {
private:
    sf::Vector2f position;
    sf::Vector2f target;
    sf::CircleShape shape;
    std::queue<sf::Vector2f> trail;

public:
    Electron(sf::Vector2f startPos, sf::Vector2f endPos);
    bool move();
    void draw(sf::RenderWindow& window);
};

#endif
