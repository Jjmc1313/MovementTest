#ifndef KEYBOARDLISTENER_HPP_
#define KEYBOARDLISTENER_HPP_

#include <conio.h>

#include "player.hpp"

class KBListener {
    public:
    bool paused = false;

    void listen(Player&);
};

void KBListener::listen(Player& targetPlayer) {
    char ch;

    while (_kbhit()) {
        ch = _getch();
    }

    switch (ch) {
        case 119:
        case 72:
            if (targetPlayer.dirVector != DOWN) targetPlayer.dirVector = UP;
            break;
    
        case 115:
        case 80:
            if (targetPlayer.dirVector != UP) targetPlayer.dirVector = DOWN;
            break;
    
        case 97:
        case 75:
            if (targetPlayer.dirVector != RIGHT) targetPlayer.dirVector = LEFT;
            break;
    
        case 100:
        case 77:
            if (targetPlayer.dirVector != LEFT) targetPlayer.dirVector = RIGHT;
            break;
    
        // Quit
        case 113:
            targetPlayer.initialized = false;
            break;
    
        // Pause
        case 27:
            paused = !paused;
            break;
    
        default:
            break;
        }
        
    return;
}

#endif