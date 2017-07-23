#pragma once

#include "desktopenvironments.h"

class I3DesktopEnvironment : public IDesktopEnvironment {
public:
    bool gtkInterfaceFont(string &font);
    string name();
};
