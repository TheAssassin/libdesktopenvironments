#pragma once

#include "desktopenvironments.h"

class MateDesktopEnvironment : public IDesktopEnvironment {
public:
    bool gtkInterfaceFont(std::string &font);
    std::string name();
};
