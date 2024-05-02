#include "KeyboardInput.h"

KeyboardInput::KeyboardInput() {}

KeyboardInput::~KeyboardInput() {}

INPUT KeyboardInput::getKeyboardInput() {
    std::string input;
    std::cout << "> ";
    std::getline(std::cin, input);

    switch (input[0]) {
        case 'w': case 'W' :
            return INPUT::UP;
        case 's' : case 'S' :
            return INPUT::DOWN;
        case 'a' : case 'A' : 
            return INPUT::LEFT;
        case 'd' : case 'D' :
            return INPUT::RIGHT;
        case 'q' : case 'Q' :
            return INPUT::QUIT;
        default :
            std::cerr << "Invalid input" << std::endl;
            return INPUT::NONE;
    }
}