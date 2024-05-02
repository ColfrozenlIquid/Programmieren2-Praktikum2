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
    if (character){
        character->setCurrentTile(this);
    }
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
    //is character allowed to leave current tile
    if (onLeave(destTile, who)) {
        std::pair<bool, Tile*> entry_tile = destTile->onEnter(who);
        if (entry_tile.first) {
            //check for portal condition
            if (entry_tile.second) {
                entry_tile.second->setCurrentCharacter(who);
                this->setCurrentCharacter(nullptr);
            }
            else {
                destTile->setCurrentCharacter(who);
                this->setCurrentCharacter(nullptr);
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