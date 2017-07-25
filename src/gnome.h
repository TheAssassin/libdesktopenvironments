#pragma once

#include "desktopenvironments.h"

class GnomeDesktopEnvironment : public IDesktopEnvironment {
public:
    bool gtkInterfaceFont(std::string &font) override;
    std::string name() override;
};
