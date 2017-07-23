#pragma once

#include "desktopenvironments.h"

class GnomeDesktopEnvironment : public IDesktopEnvironment {
private:
    bool configToolPath(string &path);

public:
    bool gtkInterfaceFont(string &font);
    string name();
};
