#pragma once

#include "desktopenvironments.h"

class MateDesktopEnvironment : public IDesktopEnvironment {
public:
    bool gtkInterfaceFont(string &font);
    string name();
};
