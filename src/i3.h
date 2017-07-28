#pragma once

#include "desktopenvironments.h"

class I3DesktopEnvironment : public IDesktopEnvironment {
public:
    bool gtkInterfaceFont(std::string &font);
    std::string name();
};
