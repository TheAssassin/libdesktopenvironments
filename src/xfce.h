#pragma once

#include "desktopenvironments.h"

class XfceDesktopEnvironment : public IDesktopEnvironment {
public:
    bool gtkInterfaceFont(std::string &font);
    std::string name();
};
