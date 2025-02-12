#include "Gates.h"
#include <iostream>

LogicGate::LogicGate(const std::string& label, float x, float y, int numInputs)
    : position(x + 40, y + 20), inputs(numInputs, false) {
    rect.setSize(sf::Vector2f(80, 40));
    rect.setFillColor(sf::Color::Red);
    rect.setPosition(x, y);

    if (!font.loadFromFile("assets/fonts/arial.ttf")) {
        std::cerr << "Failed to load font!" << std::endl;
    }

    text.setFont(font);
    text.setString(label);
    text.setCharacterSize(14);
    text.setFillColor(sf::Color::White);
    text.setPosition(x + 20, y + 10);
}

void LogicGate::setInput(bool state) {
    inputs[0] = state;
}

sf::Vector2f LogicGate::getPosition() const {
    return position;
}

void LogicGate::draw(sf::RenderWindow& window) {
    window.draw(rect);
    window.draw(text);
}

ANDGate::ANDGate(float x, float y) : LogicGate("AND", x, y, 2) {}
bool ANDGate::computeOutput() { return inputs[0] && inputs[1]; }

ORGate::ORGate(float x, float y) : LogicGate("OR", x, y, 2) {}
bool ORGate::computeOutput() { return inputs[0] || inputs[1]; }

NOTGate::NOTGate(float x, float y) : LogicGate("NOT", x, y, 1) {}
bool NOTGate::computeOutput() { return !inputs[0]; }
