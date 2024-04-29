//
// Created by Daniel on 17/04/2024.
//

#ifndef PRAKTIKUM2_PORTAL_H
#define PRAKTIKUM2_PORTAL_H


#include "Tile.h"

class Portal : public Tile {
    public:
        Portal(int row, int column);
        ~Portal();

        std::string getTexture();

        bool moveTo(Tile* destTile, Character* who);
        bool onLeave(Tile* destTile, Character* who);
        std::pair<bool, Tile*> onEnter(Character* who);

    private:
        Portal* m_destination_portal;
};


#endif //PRAKTIKUM2_PORTAL_H
