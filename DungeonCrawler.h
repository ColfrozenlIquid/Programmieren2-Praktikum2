#pragma once
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