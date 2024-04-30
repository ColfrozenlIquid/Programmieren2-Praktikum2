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