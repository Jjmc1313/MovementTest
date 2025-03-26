// player.hpp
#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <iostream>
#include <conio.h>

enum Vector {
    UP, DOWN, LEFT, RIGHT
};

class Player {
    public:
        int x;
        int y;
        int gridWidth;
        int gridHeight;
        char marker;
        Vector inputVector;
        bool initialized;

        void init();

        void listen();
        void updatePos();
        void drawGrid();

        bool inBounds();
};

#endif