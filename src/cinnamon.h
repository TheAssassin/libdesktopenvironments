#pragma once

#include "desktopenvironments.h"

class CinnamonDesktopEnvironment : public IDesktopEnvironment {
public:
    bool gtkInterfaceFont(std::string &font) override;
    std::string name() override;
};
