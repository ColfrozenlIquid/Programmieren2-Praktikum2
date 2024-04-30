#ifndef PRAKTIKUM2_FLOOR_H
#define PRAKTIKUM2_FLOOR_H


#include "Tile.h"

class Floor : public Tile {
    public:
        Floor(int row, int column);
        ~Floor();

        std::string getTexture();

        bool moveTo(Tile* destTile, Character* who) {return Tile::moveTo(destTile, who);}
        bool onLeave(Tile* destTile, Character* who);
        std::pair<bool, Tile*> onEnter(Character* who);

    private:
};

#endif //PRAKTIKUM2_FLOOR_H