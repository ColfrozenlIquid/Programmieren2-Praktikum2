//
// Created by Daniel on 17/04/2024.
//

#ifndef PRAKTIKUM2_CHARACTER_H
#define PRAKTIKUM2_CHARACTER_H


#include <string>
#include "Tile.h"
#include "AbstractUI.h"
#include "KeyboardInput.h"

typedef struct Coordinate {
    int row_pos;
    int column_pos;
} Coordinate;

class Tile;
class AbstractUI;

class Character {
    public:

        Character(std::string texture_path, AbstractUI* ui);
        ~Character();

        std::string getTexture();
        void setCurrentTile(Tile* tile);
        Coordinate getCurrentCoordinate();
        INPUT move();

        void setPositionCoordinate(int row_pos, int column_pos);
        Tile* getCurrentCharacterTile();

    private:
        std::string m_texture_path;
        Tile* m_current_tile_position;
        Coordinate m_current_player_coord;
        AbstractUI* m_abstractui;
};

#endif //PRAKTIKUM2_CHARACTER_H