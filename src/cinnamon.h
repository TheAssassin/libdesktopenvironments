#pragma once

#include "desktopenvironments.h"

class CinnamonDesktopEnvironment : public IDesktopEnvironment {
public:
    bool gtkInterfaceFont(string &font);
    string name();
};
