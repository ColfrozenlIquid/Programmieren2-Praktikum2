#pragma once
#include "Tile.h"

class Portal : public Tile {
    public:
        Portal(int row, int column);
        ~Portal();

        std::string getTexture();

        bool moveTo(Tile* destTile, Character* who) {return Tile::moveTo(destTile, who);}
        bool onLeave(Tile* destTile, Character* who);
        std::pair<bool, Tile*> onEnter(Character* who);

        void setDestinationPortal(Tile* tile);

    private:
        Portal* m_destination_portal;
};