#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "Gates.h"
#include <vector>
#include <memory>

class Circuit {
private:
    std::vector<std::shared_ptr<Gate>> gates;

public:
    void initialize();
    void draw(sf::RenderWindow& window);
    sf::Vector2f getGatePosition(size_t index) const;
    bool getGateOutput(size_t index) const;
    size_t getGateCount() const;
};

#endif
