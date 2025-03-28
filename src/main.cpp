#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include <conio.h>

#include "player.hpp"
#include "keyboardListener.hpp"

void draw(Player, int, int, int, int);

int main() {
    srand(time(0));

    // Change the terminal code page to UTF-8 to display block characters correctly
    system("chcp 65001"); // Default 437 (US)
    system("cls");

    std::cout << "   ___   ____     __  ___                                     __     ______          __ \n"
              << "  |__ \\ / __ \\   /  |/  /___ _   _____  ____ ___  ___  ____  / /_   /_  __/__  _____/ /_\n"
              << "  __/ // / / /  / /|_/ / __ \\ | / / _ \\/ __ `__ \\/ _ \\/ __ \\/ __/    / / / _ \\/ ___/ __/\n"
              << " / __// /_/ /  / /  / / /_/ / |/ /  __/ / / / / /  __/ / / / /_     / / /  __(__  ) /_  \n"
              << "/____/_____/  /_/  /_/\\____/|___/\\___/_/ /_/ /_/\\___/_/ /_/\\__/    /_/  \\___/____/\\__/  " << std::endl;
    std::cout << "Press Any Key To Start...";
    getch();
    
    std::ios_base::sync_with_stdio(false);

    int gridWidth, 
        gridHeight;
    gridWidth = 10;
    gridHeight = 10;
    // *2 these values

    int fruitX,
        fruitY;
    fruitX = 4;
    fruitY = 0;

    Player player;
    KBListener kbListener;

    player.init();

    std::clock_t c_start;
    std::clock_t c_end;

    do {
        if (kbListener.paused) {
            std::cout << "Paused! Press Any Key to Unpause..." << std::endl;
            getch();
            kbListener.paused = !kbListener.paused;
        }

        c_start = std::clock();
        system("cls");

        kbListener.listen(player);
        player.updatePos();
        player.isInBounds(gridWidth, gridHeight);
        player.gotFruit(fruitX, fruitY, gridWidth, gridHeight);

        draw(player, gridWidth, gridHeight, fruitX, fruitY);

        std::cout << "Score: $" << player.score << std::endl;
        // std::cout << fruitX << " " << fruitY << std::endl;
        // std::cout << "X: " << player.x << " Y: " << player.y << std::endl;
        c_end = std::clock();

        long double time_elapsed = 1000 * (c_end - c_start) / CLOCKS_PER_SEC;
        std::cout << "Time: " << time_elapsed << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(125 - static_cast<int>(time_elapsed)));
    } while (player.initialized && player.inBounds);

    return 0;
}

void draw(Player target, int width, int height, int fruitX, int fruitY) {
    // draws +---+ line at top 
    for (int w = -1; w <= width * 2; w++) {
        std::cout << "▄▄";
    }
    std::cout << std::endl;

    // Draws grid
    for (int yPos = -height; yPos <= height; yPos++) {
        std::cout << "█";
        for (int xPos = -width; xPos <= width; xPos++) {
            if (xPos == target.x && yPos == target.y) {
                std::cout << "▓▓";
            } else if (xPos == fruitX && yPos == fruitY) {
                std::cout << "$1";
            } else {
                std::cout << "  ";
            }
        }
        std::cout << "█" << std::endl;
    }

    // draws +---+ line at bottom
    for (int w = -1; w <= width * 2; w++) {
        std::cout << "▀▀";
    }
    std::cout << std::endl;
}