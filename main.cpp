#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>

#include "player.hpp"

int randInRange(int, int);

int main() {
    srand(time(0));
    std::cout << "   ___   ____     __  ___                                     __     ______          __ \n"
              << "  |__ \\ / __ \\   /  |/  /___ _   _____  ____ ___  ___  ____  / /_   /_  __/__  _____/ /_\n"
              << "  __/ // / / /  / /|_/ / __ \\ | / / _ \\/ __ `__ \\/ _ \\/ __ \\/ __/    / / / _ \\/ ___/ __/\n"
              << " / __// /_/ /  / /  / / /_/ / |/ /  __/ / / / / /  __/ / / / /_     / / /  __(__  ) /_  \n"
              << "/____/_____/  /_/  /_/\\____/|___/\\___/_/ /_/ /_/\\___/_/ /_/\\__/    /_/  \\___/____/\\__/  " << std::endl;
    std::cout << "Press Any Key To Start...";
    getch();

    // For some reason, putting this at the top of main causes header to not appear at runtime. The program still behaves normally otherwise
    std::ios_base::sync_with_stdio(false);
    // Cannot mix C and C++ style IO, streams are no longer thread-safe. Potential race states
    // Positive side effect: cout now has a seperate buffer from stdout, spends less CPU time 

    Player player;
    player.init();

    int targetMs = 1000 / 30; // Unused
    std::clock_t c_start;
    std::clock_t c_end;

    // Game loop
    do {
        c_start = std::clock();
        if (player.paused) {
            std::cout << "Paused!" << std::endl;
            getch();
            player.paused = !player.paused;
        }

        player.listen();
        player.updatePos();
        player.drawGrid();
        c_end = std::clock();

        // https://stackoverflow.com/questions/20167685/how-to-measure-cpu-time
        long double time_elapsed = 1000 * (c_end - c_start) / CLOCKS_PER_SEC;
        std::cout << "Draw Time: " << time_elapsed << "ms" << std::endl;
    
        std::this_thread::sleep_for(std::chrono::milliseconds(125 - static_cast<int>(time_elapsed))); // ~8 FPS
    } while (player.initialized && player.inBounds());

    return 0;
}

// Unused
int randInRange(int min, int max) {
    return (rand() % max - min + 1) + min;
}