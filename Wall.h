#pragma once
#include "Tile.h"

class Wall : public Tile {
    public:
        Wall(int row, int column);
        ~Wall();

        std::string getTexture();

        bool moveTo(Tile* destTile, Character* who) {return Tile::moveTo(destTile, who);}
        bool onLeave(Tile* destTile, Character* who);
        std::pair<bool, Tile*> onEnter(Character* who);

    private:
};