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
    void isInBounds(int, int);
};

void Player::init() {
    x = 0;
    y = 0;
    dirVector = RIGHT;
    initialized = true;
    inBounds = true;
}

void Player::updatePos() {
    switch (dirVector) {
        case UP:
            y--;
            break;
        
        case DOWN:
            y++;
            break;
    
        case LEFT:
            x--;
            break;
    
        case RIGHT:
            x++;
            break;
        }
}

void Player::isInBounds(int gridWidth, int gridHeight) {
    bool xInRange = (x <= gridWidth) && (x >= gridWidth * -1);
    bool yInRange = (y <= gridHeight) && (y >= gridHeight * -1);

    if (xInRange && yInRange) {
        inBounds = true;
    } else {
        inBounds = false;
    }
}