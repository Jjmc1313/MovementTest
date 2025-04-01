#include <iostream>

int randInRange(int, int);

enum Vector {
    UP, DOWN, LEFT, RIGHT
};

class Player {
    public:
    int x;
    int y;
    int length;
    int score;
    Vector dirVector;
    bool initialized;
    bool inBounds;

    void init();
    void updatePos();
    void isInBounds(int, int);
    void gotFruit(int&, int&, int, int);
};

void Player::init() {
    x = -5;
    y = 0;
    score = 0; // + 3 = length
    dirVector = RIGHT;
    initialized = true;
    inBounds = true;

    return;
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

    return;
}

void Player::isInBounds(int gridWidth, int gridHeight) {
    bool xInRange = (x <= gridWidth) && (x >= gridWidth * -1);
    bool yInRange = (y <= gridHeight) && (y >= gridHeight * -1);

    if (xInRange && yInRange) {
        inBounds = true;
    } else {
        inBounds = false;
    }

    return;
}

void Player::gotFruit(int& fruitX, int& fruitY, int gridWidth, int gridHeight) {
    if (x == fruitX && y == fruitY) {
        score++;
        fruitX = randInRange(-gridWidth + 1, gridWidth - 1);
        fruitY = randInRange(-gridHeight + 1, gridHeight - 1);
    }
    
    return;
}

int randInRange(int min, int max) {
    return rand() % (max + 1 - min) + min;
}