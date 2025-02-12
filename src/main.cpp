#include <SFML/Graphics.hpp>
#include "Circuit.h"
#include "Electron.h"
#include <iostream>
#include <thread>
#include <chrono>

constexpr float ELECTRON_SPEED = 2.0f;

int main() {
    sf::RenderWindow window(sf::VideoMode(600, 400), "Electron Flow Simulation");

    // Create the circuit
    Circuit circuit;
    circuit.initialize();

    // Electron logic
    std::vector<Electron> electrons;
    bool electronMoving = false;
    size_t currentGate = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        // Draw the circuit
        circuit.draw(window);

        // Start electron flow on key press
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !electronMoving) {
            electronMoving = true;
            currentGate = 0;
            electrons.emplace_back(Electron({50, 120}, circuit.getGatePosition(0)));
        }

        // Move electrons through logic gates
        if (electronMoving) {
            if (!electrons.empty() && electrons.back().move()) {
                if (currentGate < circuit.getGateCount() - 1) {
                    currentGate++;
                    if (circuit.getGateOutput(currentGate)) {
                        electrons.emplace_back(Electron(
                            circuit.getGatePosition(currentGate - 1),
                            circuit.getGatePosition(currentGate)));
                    } else {
                        electronMoving = false;
                    }
                } else {
                    electronMoving = false;
                }
            }
        }

        for (auto& electron : electrons) {
            electron.draw(window);
        }

        window.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    return 0;
}
