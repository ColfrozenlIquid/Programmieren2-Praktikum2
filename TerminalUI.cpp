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