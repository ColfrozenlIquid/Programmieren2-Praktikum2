//
// Created by Daniel on 17/04/2024.
//

#include "TerminalUI.h"
#include "KeyboardInput.h"

TerminalUI::TerminalUI() {}

TerminalUI::~TerminalUI() {}

INPUT TerminalUI::move() {
    return KeyboardInput::getKeyboardInput();
}

void TerminalUI::draw(Level* level) {
    level->printLevelToConsole();
}