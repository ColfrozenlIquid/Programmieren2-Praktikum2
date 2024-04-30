#pragma once
#include "Level.h"
#include "KeyboardInput.h"

class Level;

class AbstractUI {
    public:
        AbstractUI();
        ~AbstractUI();

        virtual void draw(Level* level) = 0;
        virtual INPUT move() = 0;

    private:
};