//
// Created by Daniel on 17/04/2024.
//

#include "Floor.h"

Floor::Floor(int row, int column) : Tile(row, column) {
    m_texture = ".";
}

Floor::~Floor() {}

std::string Floor::getTexture() {
    if (this->hasCharacter()) {
        return m_current_character->getTexture();
    }
    return m_texture;
}

bool Floor::moveTo(Tile* destTile, Character* who) {
    if (onLeave(destTile, who)) {
        if (destTile->onEnter(who).first) {
            destTile->setCurrentCharacter(who);
            this->setCurrentCharacter(nullptr);
        }
    }
    return true;
}

bool Floor::onLeave(Tile* destTile, Character* who) {
    return true;
}

//bool = is tile enterable
//Tile* = nullptr if not using portal else portal tile
std::pair<bool, Tile*> Floor::onEnter(Character* who) {
    std::pair<bool, Tile*> result = {true, nullptr};
    return result;
}