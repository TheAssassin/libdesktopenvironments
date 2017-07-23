#pragma once

#include "desktopenvironments.h"

class LxqtDesktopEnvironment : public IDesktopEnvironment {
public:
    bool gtkInterfaceFont(string &font);
    string name();
};
