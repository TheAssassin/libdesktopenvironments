#pragma once

#include "desktopenvironments.h"

class DeepinDesktopEnvironment : public IDesktopEnvironment {
public:
    bool gtkInterfaceFont(string &font);
    string name();
};
