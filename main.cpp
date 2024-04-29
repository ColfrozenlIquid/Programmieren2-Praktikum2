#include <iostream>
#include "DungeonCrawler.h"

int main() {
    DungeonCrawler dungeonCrawler;
    bool running = true;
    while (running) {
        running = dungeonCrawler.turn();
    }
    return 0;
}
