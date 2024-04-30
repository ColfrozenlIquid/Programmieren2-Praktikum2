#pragma once
#include <iostream>
#include "InputType.h"


class KeyboardInput {
    public:
        KeyboardInput();
        ~KeyboardInput();

        static INPUT getKeyboardInput();

    private:
};