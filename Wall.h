//
// Created by Daniel on 17/04/2024.
//

#ifndef PRAKTIKUM2_WALL_H
#define PRAKTIKUM2_WALL_H


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


#endif //PRAKTIKUM2_WALL_H
