//
// Created by Daniel on 17/04/2024.
//

#include "Tile.h"

Tile::Tile(int row, int column) :
        m_column(column),
        m_row(row) {
    this->m_current_character = nullptr;
    m_texture = "";
}

Tile::~Tile() {}

const signed int Tile::getColumns() {
    return this->m_column;
}

const signed int Tile::getRows() {
    return this->m_row;
}

void Tile::setCurrentCharacter(Character* character) {
    this->m_current_character = character;
}

bool Tile::hasCharacter() {
    if (m_current_character != nullptr) {
        return true;
    }
    return false;
}

Character* Tile::getCharacter() {
    return m_current_character;
}

bool Tile::moveTo(Tile* destTile, Character* who) {
    std::cout << "Calling moveto on Tile" << std::endl;
    if (onLeave(destTile, who)) {
        std::pair<bool, Tile*> entry_tile = destTile->onEnter(who);
        if (entry_tile.first) {
            if (entry_tile.second) {
                entry_tile.second->setCurrentCharacter(who);
                this->setCurrentCharacter(nullptr);
                who->setCurrentTile(entry_tile.second);
            }
            else {
                destTile->setCurrentCharacter(who);
                this->setCurrentCharacter(nullptr);
                who->setCurrentTile(destTile);
            }
            return true;
        }
    }
    return false;
}

int Tile::getRow() {
    return m_row;
}

int Tile::getColumn() {
    return m_column;
}

// bool Tile::moveTo(Tile* destTile, Character* who) {
//     if (!destTile->hasCharacter()){
//         destTile->setCurrentCharacter(who);
//         this->m_current_character = nullptr;
//         return true;
//     }
//     return false;
// }

// bool Tile::onLeave(Tile* destTile, Character* who) {

// }

// std::pair<bool, Tile*> Tile::onEnter(Character* who) {

// }