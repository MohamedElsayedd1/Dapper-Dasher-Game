Dapper Dasher Game
This repository contains the source code for Dapper Dasher, a simple 2D side-scrolling game built using the Raylib library. The player controls a character named Scarfy, who must navigate through a series of obstacles (nebulas) while running across a scrolling background. The objective is to avoid collisions with nebulas and reach the finish line to win the game.

Features
2D Side-Scrolling Gameplay: Navigate through a dynamically scrolling environment with layered backgrounds for a parallax effect.
Character Animation: Scarfy is animated using a sprite sheet, providing smooth character movements.
Obstacle Avoidance: Nebulas act as obstacles that the player must avoid to prevent a game over.
Simple Controls: The game is controlled with the spacebar for jumping.
Win Condition: Reach the finish line without colliding with any nebulas to win the game.
Getting Started
Prerequisites
Raylib: Ensure you have Raylib installed on your system. Raylib is a simple and easy-to-use library to enjoy videogames programming.
Building the Game
Clone the repository:

bash
Copy code
git clone https://github.com/yourusername/dapper-dasher.git
cd dapper-dasher
Compile the source code:

bash
Copy code
g++ -o DapperDasher main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
Run the game:

bash
Copy code
./DapperDasher
How to Play
Jump: Press the spacebar to make Scarfy jump over the obstacles (nebulas).
Win: Reach the finish line without colliding with any nebulas.
Lose: Collide with a nebula, and the game will display "Game Over!".
Project Structure
dasher.cpp: The main source file containing the game logic, including character and background animations, nebula obstacle handling, and collision detection.
textures/: This folder contains the sprite sheets and background textures used in the game.

Acknowledgements
Raylib: The game is built using Raylib, a simple and easy-to-use library to enjoy videogames programming.
Kenney.nl: Some of the assets used in this game may be sourced from Kenney.nl, known for providing free game assets.# Dapper-Dasher-Game
