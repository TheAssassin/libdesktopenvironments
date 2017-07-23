#pragma once

#include "desktopenvironments.h"

using namespace std;

class XfceDesktopEnvironment : public IDesktopEnvironment {
public:
    bool gtkInterfaceFont(string &font);
    string name();
};
