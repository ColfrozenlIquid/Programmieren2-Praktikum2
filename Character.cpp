//
// Created by Daniel on 17/04/2024.
//

#include "Character.h"

Character::Character(std::string texture_path, AbstractUI* ui) : m_texture_path(texture_path), m_abstractui(ui) {}

Character::~Character() {}

std::string Character::getTexture() {
    return "X";
}

void Character::setCurrentTile(Tile* tile) {
    m_current_tile_position = tile;
}

INPUT Character::move() {
    return m_abstractui->move();
}

Tile* Character::getCurrentPosition() {
    return m_current_tile_position;
}