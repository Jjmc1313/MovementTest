#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <iostream>

enum Vector {
    UP, DOWN, LEFT, RIGHT
};

class Player {
    public:
    int x;
    int y;
    Vector dirVector;
    bool initialized;
    bool inBounds;

    void init();
    void updatePos();
    bool isInBounds(int, int);
};

#endif