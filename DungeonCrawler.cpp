//
// Created by Daniel on 17/04/2024.
//

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
        Coordinate current_character_position = character->getCurrentCoordinate();
        Tile* current_character_tile = character->getCurrentCharacterTile();
        std::pair<Tile*, Coordinate> destination_tile = getDestinationTile(player_input, current_character_position);
        bool result = current_character_tile->moveTo(destination_tile.first, character);
        std::cout << "Result is: " << result << std::endl;
        if (result) {
            std::cout << "Moving player" << std::endl;
            character->setCurrentTile(destination_tile.first);
            character->setPositionCoordinate(destination_tile.second.row_pos, destination_tile.second.column_pos);
        }
    }
    // KeyboardInput::getKeyboardInput();
    // INPUT player_input = m_UI->move();
    // m_level.
    return true;
}

std::pair<Tile*, Coordinate> DungeonCrawler::getDestinationTile(INPUT player_input, Coordinate current_character_position) {
    std::cout << "Current character position: (" << current_character_position.column_pos << ", " << current_character_position.row_pos << ")" << std::endl;
    Coordinate destination_coordinate = current_character_position;
    switch (player_input) {
    case INPUT::UP :
        destination_coordinate.column_pos = current_character_position.column_pos;
        if ((current_character_position.row_pos - 1) >= 0) {
            destination_coordinate.row_pos -= 1;
        }
        break;
    case INPUT::DOWN :
        destination_coordinate.column_pos = current_character_position.column_pos;
        if ((current_character_position.row_pos + 1) < m_level->getMaxRows()) {
            destination_coordinate.row_pos += 1;
        }
        break;
    case INPUT::LEFT :
        destination_coordinate.row_pos = current_character_position.row_pos;
        if ((current_character_position.column_pos - 1) >= 0) {
            destination_coordinate.column_pos -= 1;
        }
        break;
    case INPUT::RIGHT :
        destination_coordinate.row_pos = current_character_position.row_pos;
        if ((current_character_position.column_pos + 1) < m_level->getMaxColumns()) {
            destination_coordinate.column_pos += 1;
        }
    default:
        break;
    }
    std::cout << "Destination character position: (" << destination_coordinate.column_pos << ", " << destination_coordinate.row_pos << ")" << std::endl;
    return {m_level->getTile(destination_coordinate.row_pos, destination_coordinate.column_pos), destination_coordinate};
}