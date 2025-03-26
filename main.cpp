#include <iostream>
#include <thread>
#include <chrono>

#include "player.hpp"

int randInRange(int, int);

int main() {
    srand(time(0));

    Player player;
    player.init();

    std::cout << "Enter Grid Size (x): ";
    int gridSizeX;
    std::cin >> gridSizeX;
    player.gridWidth = gridSizeX / 2;

    std::cout << "Enter Grid Size (y): ";
    int gridSizeY;
    std::cin >> gridSizeY;
    player.gridHeight = gridSizeY / 2;

    while (player.initialized && player.inBounds()) {
        player.listen();
        player.updatePos();
        std::this_thread::sleep_for(std::chrono::milliseconds(125));
    }

    return 0;
}

int randInRange(int min, int max) {
    return (rand() % max - min + 1) + min;
}