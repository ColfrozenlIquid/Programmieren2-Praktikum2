//
// Created by Daniel on 17/04/2024.
//

#ifndef PRAKTIKUM2_CHARACTER_H
#define PRAKTIKUM2_CHARACTER_H


#include <string>
#include "Tile.h"
#include "AbstractUI.h"
#include "KeyboardInput.h"

class Tile;
class AbstractUI;

class Character {
    public:
        Character(std::string texture_path, AbstractUI* ui);
        ~Character();

        std::string getTexture();
        void setCurrentTile(Tile* tile);
        Tile* getCurrentPosition();
        INPUT move();

    private:
        std::string m_texture_path;
        Tile* m_current_tile_position;
        AbstractUI* m_abstractui;
};

#endif //PRAKTIKUM2_CHARACTER_H
