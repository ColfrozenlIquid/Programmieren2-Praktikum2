//
// Created by Daniel on 17/04/2024.
//

#include <iostream>
#include "Level.h"
#include "Wall.h"
#include "Floor.h"
#include "Portal.h"

Level::Level(std::string level, int rows, int columns, AbstractUI* ui) : m_rows(rows), m_columns(columns) {
    generateLevel(level);
    Character* player_character = new Character("player_texture", ui);
    placeCharacter(player_character, 3, 3);
    connectPortals();
}

Level::~Level() {}

void Level::generateLevel(std::string level) {
    std::vector<Tile*> row_vector;
    for (int i = 0; char character : level) {
        if (row_vector.size() < m_columns) {
            if (character == '#') {
                row_vector.push_back(new Wall(i/m_rows, i%m_columns));
            }
            else if (character == '.') {
                row_vector.push_back(new Floor(i/m_rows, i%m_columns));
            }
            else if (character == 'O') {
                row_vector.push_back(new Portal(i/m_rows, i%m_columns));
            }
            i++;
        }
        if (row_vector.size() == m_columns) {
            m_level_data.push_back(row_vector);
            row_vector.clear();
        }
    }
}

void Level::connectPortals() {
    int count = 0;
    std::pair<Tile*, Tile*> portals_pair = {nullptr, nullptr};
    for (auto row : m_level_data) {
        for (auto tile : row) {
            if (typeid(*tile) == typeid(Portal)) {
                std::cout << "Found portal" << std::endl;
                if (count + 1 > 2) {
                    std::cout << "too many portals, reimplement method" << std::endl;
                    return;
                }
                if (!portals_pair.first) {
                    portals_pair.first = tile;
                    count++;
                    continue;
                }
                if (!portals_pair.second) {
                    portals_pair.second = tile;
                    count++;
                    break;
                }
            }
        }
    }
    std::cout << "Portals pair #1: " << portals_pair.first << ", #2: " << portals_pair.second << std::endl;
    dynamic_cast<Portal*>(portals_pair.first)->setDestinationPortal(dynamic_cast<Portal*>(portals_pair.second));
    dynamic_cast<Portal*>(portals_pair.second)->setDestinationPortal(dynamic_cast<Portal*>(portals_pair.first));
}

void Level::printLevelToConsole() {
    for (auto i : m_level_data) {
        for (auto j : i) {
            std::cout << j->getTexture();
        }
        std::cout << "\n";
    }
}

Tile* Level::getTile(int row, int column) {
    return m_level_data[row][column];
}

const Tile* Level::getTile(int row, int column) const {
    return m_level_data[row][column];
}

void Level::placeCharacter(Character* character, int row, int column) {
    character->setCurrentTile(m_level_data[row][column]);
    character->setPositionCoordinate(row, column);
    m_level_data[row][column]->setCurrentCharacter(character);
    m_character_vec.push_back(character);

}

std::vector<std::vector<Tile*>> Level::getMapData() {
    return m_level_data;
}

std::vector<Character*> Level::getCharacters() {
    return m_character_vec;
}

int Level::getMaxRows() {
    return m_rows;
}

int Level::getMaxColumns() {
    return m_columns;
}