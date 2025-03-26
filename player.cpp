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
        if (inputVector != DOWN) inputVector = UP;
        break;

    case 80:
        if (inputVector != UP) inputVector = DOWN;
        break;

    case 75:
        if (inputVector != RIGHT) inputVector = LEFT;
        break;

    case 77:
        if (inputVector != LEFT) inputVector = RIGHT;
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
}

void Player::drawGrid() {
    system("cls");

    // draws +---+ line at top 
    std::cout << "+";
    for (int w = 0; w < gridWidth * 2; w++) {
        std::cout << "--";
    }
    std::cout << "+" << std::endl;

    // Draws grid
    for (int yPos = gridHeight * -1; yPos < gridHeight; yPos++) {
        std::cout << "|";
        for (int xPos = gridWidth * -1; xPos < gridWidth; xPos++) {
            if (xPos == x && yPos == y) {
                std::cout << marker << marker;
            } else {
                std::cout << "  ";
            }
        }
        std::cout << "|" << std::endl;
    }

    // draws +---+ line at bottom
    std::cout << "+";
    for (int w = 0; w < gridWidth * 2; w++) {
        std::cout << "--";
    }
    std::cout << "+" << std::endl;

    // Outputs coordinates
    std::cout << "X: " << x << " Y: " << y << std::endl;
}

bool Player::inBounds() {
    bool xInRange = (x <= gridWidth) && (x >= gridWidth * -1);
    bool yInRange = (y <= gridHeight) && (y >= gridHeight * -1);

    if (xInRange && yInRange) {
        return true;
    } else {
        return false;
    }
}