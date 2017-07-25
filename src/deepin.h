#pragma once

#include "desktopenvironments.h"

class DeepinDesktopEnvironment : public IDesktopEnvironment {
public:
    bool gtkInterfaceFont(std::string &font) override;
    std::string name() override;
};
