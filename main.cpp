#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>

#include "player.hpp"

int randInRange(int, int);

int main() {
    srand(time(0));
    std::cout << "Press Any Key...";
    getch();

    // For some reason, putting this at the top of main causes line 12 to not appear at runtime. The program still behaves normally otherwise
    std::ios_base::sync_with_stdio(false);

    Player player;
    player.init();

    int targetMs = 1000 / 30; // Unused
    std::clock_t c_start;
    std::clock_t c_end;

    while (player.initialized && player.inBounds()) {
        c_start = std::clock();
        player.listen();
        player.updatePos();
        player.drawGrid();
        c_end = std::clock();

        // https://stackoverflow.com/questions/20167685/how-to-measure-cpu-time
        long double time_elapsed = 1000 * (c_end - c_start) / CLOCKS_PER_SEC;
        std::cout << "Draw Time: " << time_elapsed << "ms" << std::endl;
    
        std::this_thread::sleep_for(std::chrono::milliseconds(125 - static_cast<int>(time_elapsed))); // ~8 FPS
    }

    return 0;
}

int randInRange(int min, int max) {
    return (rand() % max - min + 1) + min;
}