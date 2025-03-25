// player.hpp
#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <iostream>
#include <conio.h>

enum Vector {
    UP, DOWN, LEFT, RIGHT
};

class Player {
    private:
        int x;
        int y;
        char marker;
        Vector inputVector;

    public:
        bool initialized;

        void init();
        void listen();
        void updatePos();

        bool inBounds(int, int);
};

#endif