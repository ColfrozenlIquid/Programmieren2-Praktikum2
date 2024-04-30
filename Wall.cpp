//
// Created by Daniel on 17/04/2024.
//

#include "Wall.h"
#include <iostream>

Wall::Wall(int row, int column) : Tile(row, column) {
    m_texture = "#";
}

Wall::~Wall() {}

std::string Wall::getTexture() {
    if (this->hasCharacter()) {
        return m_current_character->getTexture();
    }
    return m_texture;
}

// bool Wall::moveTo(Tile* destTile, Character* who) {
//     std::cout << "Caling moveto on Wall" << std::endl;
//     if (onLeave(destTile, who)) {
//         if (destTile->onEnter(who).first) {
//             destTile->setCurrentCharacter(who);
//             this->setCurrentCharacter(nullptr);
//         }
//     }
//     return true;
// }

bool Wall::onLeave(Tile* destTile, Character* who) {
    return true;
}

std::pair<bool, Tile*> Wall::onEnter(Character* who) {
    std::pair<bool, Tile*> result = {false, nullptr};
    return result;
}