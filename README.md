# Electron Movement Simulator

## Overview

This project is a simple electron movement simulator built using C++ and the SFML graphics library. It aims to visually represent the movement of electrons within a basic circuit environment.  While currently simplified, the project provides a foundation for exploring and simulating fundamental concepts in electromagnetism.

## Features

*   **Visual Simulation:** Displays moving electrons within a simulated space.
*   **C++ and SFML:** Leverages the performance of C++ and the ease-of-use of SFML for graphics rendering.
*   **Basic Physics:**  Implements a basic model of electron movement based on applied voltage (currently simplified).

## Dependencies

*   **SFML (Simple and Fast Multimedia Library):**  Version 2.5 or later is recommended.

## Building and Running

1.  **Install SFML:** Download and install the SFML library for your operating system from the official SFML website ([https://www.sfml-dev.org/](https://www.sfml-dev.org/)).
2.  **Clone the Repository:**  Clone this repository to your local machine.
    ```bash
    git clone https://github.com/emorcos/Electron-movment-simulator.git
    cd Electron-movment-simulator
    ```
3.  **Compile the Code:** Use a C++ compiler (e.g., g++, clang++, Visual Studio) to compile the `main.cpp` file.  You will need to link against the SFML libraries.

    **Example using g++:**

    ```bash
    g++ main.cpp -o simulator -lsfml-graphics -lsfml-window -lsfml-system
    ```

    *   **Note:**  You may need to adjust the compiler flags and library paths depending on your SFML installation location and operating system.  On Windows, you might need to specify the directory where `sfml-graphics.dll`, `sfml-window.dll`, and `sfml-system.dll` are located, either by adding it to your PATH environment variable or by specifying the library directory using the `-L` flag.

4.  **Run the Simulator:** Execute the compiled binary.
    ```bash
    ./simulator  # (On Linux/macOS)
    simulator.exe # (On Windows)
    ```

## Usage

*   Once the simulator is running, you should see a window displaying electrons moving within the simulated space.
*   Currently, the simulator provides a basic visualization without any interactive controls.  Future versions may include features for controlling voltage, resistance, and other simulation parameters.
