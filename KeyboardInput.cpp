//
// Created by Daniel on 17/04/2024.
//

#include <string>
#include <iostream>
#include "KeyboardInput.h"

KeyboardInput::KeyboardInput() {}

KeyboardInput::~KeyboardInput() {}

INPUT KeyboardInput::getKeyboardInput() {
    std::string input;
    std::cout << "> ";
    std::cin >> input;
    if (input[0] == 'w' || input[0] == 'W') {
        return INPUT::UP;
    }
    if (input[0] == 's' || input[0] == 'S') {
        return INPUT::DOWN;
    }
    if (input[0] == 'a' || input[0] == 'A') {
        return INPUT::LEFT;
    }
    if (input[0] == 'd' || input[0] == 'D') {
        return INPUT::RIGHT;
    }
    if (input[0] == 'q' || input[0] == 'Q') {
        return INPUT::QUIT;
    }
    std::cout << "Invalid input" << std::endl;
    return INPUT::NONE;
}