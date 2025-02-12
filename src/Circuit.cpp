#include "Circuit.h"

void Circuit::initialize() {
    gates.push_back(std::make_shared<ANDGate>(100, 100));
    gates.push_back(std::make_shared<ORGate>(250, 100));
    gates.push_back(std::make_shared<NOTGate>(400, 100));

    gates[0]->setInput(true);
    gates[0]->setInput(true);
    gates[1]->setInput(true);
    gates[1]->setInput(false);
    gates[2]->setInput(true);
}

void Circuit::draw(sf::RenderWindow& window) {
    for (auto& gate : gates) {
        gate->draw(window);
    }
}

sf::Vector2f Circuit::getGatePosition(size_t index) const {
    return (index < gates.size()) ? gates[index]->getPosition() : sf::Vector2f(0, 0);
}

bool Circuit::getGateOutput(size_t index) const {
    return (index < gates.size()) ? gates[index]->computeOutput() : false;
}

size_t Circuit::getGateCount() const {
    return gates.size();
}
