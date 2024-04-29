//
// Created by Daniel on 17/04/2024.
//

#ifndef PRAKTIKUM2_TERMINALUI_H
#define PRAKTIKUM2_TERMINALUI_H


#include "AbstractUI.h"
#include "InputType.h"

class TerminalUI : public AbstractUI {
    public:
        TerminalUI();
        ~TerminalUI();

        INPUT move();
        void draw(Level* level);

    private:
};


#endif //PRAKTIKUM2_TERMINALUI_H
