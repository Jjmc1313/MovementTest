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

void Player::init() {
    x = 0;
    y = 0;
    gridWidth = 10;
    gridHeight = 10;
    marker = '#';
    inputVector = LEFT;
    initialized = true;
}

void Player::listen() {    
    char ch;
    
    while (_kbhit()) {
        ch = _getch();
    } 

    switch (ch) {
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
        initialized = false;

    default:
        break;
    }
}

void Player::updatePos() {
    switch (inputVector) {
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

    system("cls");
    drawGrid();
}

void Player::drawGrid() {
    for (int yPos = gridHeight * -1; yPos < gridHeight; yPos++) {
        for (int xPos = gridWidth * -1; xPos < gridWidth; xPos++) {
            if (xPos == x && yPos == y) {
                std::cout << marker << marker;
            } else {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }

    std::cout << "X: " << x << " Y: " << y << std::endl;
}

bool Player::inBounds() {
    bool xInRange = (x < gridWidth) && (x > gridWidth * -1);
    bool yInRange = (y < gridHeight) && (y > gridHeight * -1);

    if (xInRange && yInRange) {
        return true;
    } else {
        return false;
    }
}