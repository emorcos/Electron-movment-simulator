#ifndef GATES_H
#define GATES_H

#include <SFML/Graphics.hpp>
#include <vector>

class Gate {
public:
    virtual bool computeOutput() = 0;
    virtual sf::Vector2f getPosition() const = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void setInput(bool state) = 0;
};

class LogicGate : public Gate {
protected:
    std::vector<bool> inputs;
    sf::RectangleShape rect;
    sf::Text text;
    sf::Font font;
    sf::Vector2f position;

public:
    LogicGate(const std::string& label, float x, float y, int numInputs);
    void setInput(bool state) override;
    sf::Vector2f getPosition() const override;
    void draw(sf::RenderWindow& window) override;
};

class ANDGate : public LogicGate {
public:
    ANDGate(float x, float y);
    bool computeOutput() override;
};

class ORGate : public LogicGate {
public:
    ORGate(float x, float y);
    bool computeOutput() override;
};

class NOTGate : public LogicGate {
public:
    NOTGate(float x, float y);
    bool computeOutput() override;
};

#endif
