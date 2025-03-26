#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>

#include "player.hpp"

int randInRange(int, int);

int main() {
    srand(time(0));

    Player player;
    player.init();

    /*
    std::cout << "Enter Grid Size (x): ";
    int gridSizeX;
    std::cin >> gridSizeX;
    player.gridWidth = gridSizeX / 2;

    std::cout << "Enter Grid Size (y): ";
    int gridSizeY;
    std::cin >> gridSizeY;
    player.gridHeight = gridSizeY / 2;
    */

    int targetMs = 1000 / 30;

    while (player.initialized /*&& player.inBounds()*/) {  
        std::clock_t c_start = std::clock();
        player.listen();
        player.updatePos();
        std::clock_t c_end = std::clock();

        // https://stackoverflow.com/questions/20167685/how-to-measure-cpu-time
        long double time_elapsed = 1000 * (c_end - c_start) / CLOCKS_PER_SEC;
        std::cout << time_elapsed << std::endl;
    
        // std::this_thread::sleep_for(std::chrono::milliseconds(125));
    }

    return 0;
}

int randInRange(int min, int max) {
    return (rand() % max - min + 1) + min;
}