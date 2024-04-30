//
// Created by Daniel on 17/04/2024.
//

#ifndef PRAKTIKUM2_DUNGEONCRAWLER_H
#define PRAKTIKUM2_DUNGEONCRAWLER_H

#include <iostream>

#include "AbstractUI.h"
#include "Level.h"
#include "KeyboardInput.h"
#include "Character.h"

class DungeonCrawler {
    public:
        DungeonCrawler();
        ~DungeonCrawler();

        bool turn();


    private:
        Tile* getDestinationTile(INPUT player_input, Tile* current_tile);

        AbstractUI* m_UI;
        Level* m_level;
};


#endif //PRAKTIKUM2_DUNGEONCRAWLER_H
