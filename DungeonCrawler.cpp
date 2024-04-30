//
// Created by Daniel on 17/04/2024.
//

#include "DungeonCrawler.h"
#include "TerminalUI.h"

DungeonCrawler::DungeonCrawler() {
    std::string level_String = "###########OO......##........##........##........##........############O.......##........###########";
    this->m_UI = new TerminalUI();
    m_level = new Level(level_String, 10, 10, m_UI);
}

DungeonCrawler::~DungeonCrawler() {}

bool DungeonCrawler::turn() {
    m_UI->draw(m_level);
    for (Character* character : m_level->getCharacters() ) {
        Tile* current_character_position = character->getCurrentPosition();
        INPUT player_input = character->move();
        if (player_input == INPUT::QUIT) {
            return false;
        }
    }
    // KeyboardInput::getKeyboardInput();
    // INPUT player_input = m_UI->move();
    // m_level.
    return true;
}

Tile* getDestinationTile(INPUT player_input, Tile* current_character_position) {
    
}