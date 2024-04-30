//
// Created by Daniel on 17/04/2024.
//

#include "Portal.h"

Portal::Portal(int row, int column) : Tile(row, column) {
    m_texture = "O";
}

Portal::~Portal() {}

std::string Portal::getTexture() {
    if (this->hasCharacter()) {
        return m_current_character->getTexture();
    }
    return m_texture;
}

bool Portal::moveTo(Tile* destTile, Character* who) {
    if (onLeave(destTile, who)) {
        if (destTile->onEnter(who).first) {
            this->m_destination_portal->setCurrentCharacter(who);
            this->setCurrentCharacter(nullptr);
        }
    }
    return true;
}

bool Portal::onLeave(Tile* destTile, Character* who) {
    return true;
}

std::pair<bool, Tile*> Portal::onEnter(Character* who) {
    std::pair<bool, Tile*> result = {true, m_destination_portal};
    return result;
}

void Portal::setDestinationPortal(Tile* tile) {
    m_destination_portal = dynamic_cast<Portal*>(tile);
}