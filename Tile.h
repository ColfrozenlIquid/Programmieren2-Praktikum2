#ifndef PRAKTIKUM2_TILE_H
#define PRAKTIKUM2_TILE_H

#include <utility>
#include <string>
#include <iostream>
#include "Character.h"

class Character;

class Tile {
    public:
        const signed int getColumns();
        const signed int getRows();

        void setCurrentCharacter(Character* character);
        virtual std::string getTexture() = 0;

        virtual bool moveTo(Tile* destTile, Character* who);
        virtual bool onLeave(Tile* destTile, Character* who) = 0;
        virtual std::pair<bool, Tile*> onEnter(Character* who) = 0;

        bool hasCharacter();
        Character* getCharacter();

        int getRow();
        int getColumn();

    protected:

        Tile(int row, int column);
        ~Tile();

        std::string m_texture;
        Character* m_current_character;
        const int m_row;
        const int m_column;

    private:
};

#endif //PRAKTIKUM2_TILE_H