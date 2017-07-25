#pragma once

#include "desktopenvironments.h"

class DeepinDesktopEnvironment : public IDesktopEnvironment {
public:
    bool gtkInterfaceFont(std::string &font);
    std::string name();
};
