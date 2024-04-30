#ifndef PRAKTIKUM2_ABSTRACTUI_H
#define PRAKTIKUM2_ABSTRACTUI_H


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

#endif //PRAKTIKUM2_ABSTRACTUI_H