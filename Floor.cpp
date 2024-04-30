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

bool Floor::onLeave(Tile* destTile, Character* who) {
    return true;
}

std::pair<bool, Tile*> Floor::onEnter(Character* who) {
    std::pair<bool, Tile*> result = {true, nullptr};
    return result;
}