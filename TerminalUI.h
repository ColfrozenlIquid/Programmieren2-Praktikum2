#pragma once
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