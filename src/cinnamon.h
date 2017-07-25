#pragma once

#include "desktopenvironments.h"

class CinnamonDesktopEnvironment : public IDesktopEnvironment {
public:
    bool gtkInterfaceFont(std::string &font);
    std::string name();
};
