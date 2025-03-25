#include <iostream>

#include "player.hpp"

int main() {
    Player player;
    player.init();

    while (player.initialized /*&& player.inBounds()*/) {
        player.listen();
        player.updatePos();
    }

    return 0;
}