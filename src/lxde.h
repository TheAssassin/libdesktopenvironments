#pragma once

#include "desktopenvironments.h"

class LxdeDesktopEnvironment : public IDesktopEnvironment {
public:
    bool gtkInterfaceFont(string &font);
    string name();
};
