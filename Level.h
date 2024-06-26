#pragma once
#include <string>
#include <vector>
#include "Tile.h"

class Character;
class Tile;
class AbstractUI;

class Level {
    public:
        Level(std::string level, int rows, int columns, AbstractUI* ui);
        ~Level();

        Tile* getTile(int row, int column);
        const Tile* getTile(int row, int column) const;
        void printLevelToConsole();

        std::vector<std::vector<Tile*>> getMapData();
        std::vector<Character*> getCharacters();

        int getMaxRows();
        int getMaxColumns();

    private:
        void generateLevel(std::string level_string);
        void placeCharacter(Character* character, int row, int column);
        void connectPortals();

        std::vector<std::vector<Tile*>> m_level_data;
        std::vector<Character*> m_character_vec;
        const int m_rows;
        const int m_columns;
};