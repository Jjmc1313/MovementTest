// player.cpp
#include <iostream>
#include <conio.h>

enum Vector {
    UP, DOWN, LEFT, RIGHT
};

class Player {
    public:
        int x;
        int y;
        char marker;
        Vector inputVector;
        bool initialized;

        void init();
        void listen();
        void updatePos();

        bool inBounds(int, int);
};

void Player::init() {
    x = 0;
    y = 0;
    marker = '#';
    inputVector = LEFT;
    initialized = true;
}

void Player::listen() {    
    int a = getch();
    int b = getch();

    // std::cout << "A: " << a << " B: " << b << std::endl;

    switch (b) {
    case 72:
        inputVector = UP;
        break;

    case 80:
        inputVector = DOWN;
        break;

    case 75:
        inputVector = LEFT;
        break;

    case 77:
        inputVector = RIGHT;
        break;

    case 113:
        exit;

    default:
        break;
    }
}

void Player::updatePos() {
    switch (inputVector) {
    case UP:
        y++;
        break;
    
    case DOWN:
        y--;
        break;

    case LEFT:
        x--;
        break;

    case RIGHT:
        x++;
        break;
    }

    std::cout << "X: " << x << " Y: " << y << "\r";
}

bool Player::inBounds(int width, int height) {
    return true;
}