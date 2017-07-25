#pragma once

#include "desktopenvironments.h"

class XfceDesktopEnvironment : public IDesktopEnvironment {
public:
    bool gtkInterfaceFont(std::string &font) override;
    std::string name() override;
};
