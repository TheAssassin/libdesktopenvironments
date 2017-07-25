#pragma once

#include "desktopenvironments.h"

class GnomeDesktopEnvironment : public IDesktopEnvironment {
private:
    bool configToolPath(std::string &path);

public:
    bool gtkInterfaceFont(std::string &font);
    std::string name();
};
