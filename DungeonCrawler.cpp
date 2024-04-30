#include "DungeonCrawler.h"
#include "TerminalUI.h"

DungeonCrawler::DungeonCrawler() {
    std::string level_String = "###########O.......##........##........##........##........############O.......##........###########";
    this->m_UI = new TerminalUI();
    m_level = new Level(level_String, 10, 10, m_UI);
}

DungeonCrawler::~DungeonCrawler() {}

bool DungeonCrawler::turn() {
    m_UI->draw(m_level);
    for (Character* character : m_level->getCharacters() ) {
        INPUT player_input = character->move();
        if (player_input == INPUT::QUIT) {
            return false;
        }
        Tile* current_character_tile = character->getCurrentCharacterTile();
        Tile* destination_character_tile = getDestinationTile(player_input, current_character_tile);
        current_character_tile->moveTo(destination_character_tile, character);
    }
    return true;
}

Tile* DungeonCrawler::getDestinationTile(INPUT player_input, Tile* current_tile) {
    int current_row = current_tile->getRow();
    int current_column = current_tile->getColumn();
    int destination_row = current_row;
    int destination_column = current_column;

    switch (player_input) {
        case INPUT::UP :
            destination_column = current_column;
            if ((current_row - 1) >= 0) {
                destination_row -= 1;
            }
            break;
        case INPUT::DOWN :
            destination_column = current_column;
            if ((current_row + 1) < m_level->getMaxRows()) {
                destination_row += 1;
            }
            break;
        case INPUT::LEFT :
            destination_row = current_row;
            if ((current_column - 1) >= 0) {
                destination_column -= 1;
            }
            break;
        case INPUT::RIGHT :
            destination_row = current_row;
            if ((current_column + 1) < m_level->getMaxColumns()) {
                destination_column += 1;
            }
        default:
            break;
    }

    return m_level->getTile(destination_row, destination_column);
}