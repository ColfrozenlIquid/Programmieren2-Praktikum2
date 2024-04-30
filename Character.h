#pragma once
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

        INPUT move();
        
        Tile* getCurrentCharacterTile();

    private:
        std::string m_texture_path;
        Tile* m_current_tile_position;
        AbstractUI* m_abstractui;
};