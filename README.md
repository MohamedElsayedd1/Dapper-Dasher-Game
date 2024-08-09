# Dapper Dasher Game

a simple 2D side-scrolling game built using the Raylib library. The player controls a character named Scarfy, who must navigate through a series of obstacles (nebulas) while running across a scrolling background. The objective is to avoid collisions with nebulas and reach the finish line to win the game.

<p align="center">
    <img src="https://github.com/MohamedElsayedd1/Dapper-Dasher-Game/blob/main/Dapper-Dasher-Gameplay.gif" width="600" />
</p>

## Features

- **2D Side-Scrolling Gameplay**: Navigate through a dynamically scrolling environment with layered backgrounds for a parallax effect.
- **Character Animation**: Scarfy is animated using a sprite sheet, providing smooth character movements.
- **Obstacle Avoidance**: Nebulas act as obstacles that the player must avoid to prevent a game over.
- **Simple Controls**: The game is controlled with the spacebar for jumping.
- **Win Condition**: Reach the finish line without colliding with any nebulas to win the game.

## Getting Started

### Prerequisites

- **Raylib**: Ensure you have Raylib installed on your system. Raylib is a simple and easy-to-use library to enjoy videogames programming.

### Building the Game

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/dapper-dasher.git
   cd dapper-dasher
   ```

2. Compile the source code:
   ```bash
   g++ -o DapperDasher main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
   ```

3. Run the game:
   ```bash
   ./DapperDasher
   ```

## How to Play

- **Jump**: Press the `spacebar` to make Scarfy jump over the obstacles (nebulas).
- **Win**: Reach the finish line without colliding with any nebulas.
- **Lose**: Collide with a nebula, and the game will display "Game Over!".

## Project Structure

- **main.cpp**: The main source file containing the game logic, including character and background animations, nebula obstacle handling, and collision detection.
- **textures/**: This folder contains the sprite sheets and background textures used in the game.

## Acknowledgements

- **Raylib**: The game is built using Raylib, a simple and easy-to-use library to enjoy videogames programming.
- **Kenney.nl**: Some of the assets used in this game may be sourced from Kenney.nl, known for providing free game assets.

