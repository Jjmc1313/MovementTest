#ifndef KEYBOARDLISTENER_HPP_
#define KEYBOARDLISTENER_HPP_

#include <conio.h>

#include "player.hpp"

class KBListener {
    public:
    bool paused;

    void listen(Player&);
};

#endif