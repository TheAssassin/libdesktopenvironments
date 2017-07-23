#pragma once

#include "desktopenvironments.h"

class KDesktopEnvironment : public IDesktopEnvironment {
private:
    static bool configToolPath(string &path);
    static bool searchInKdeConfig(const string pattern, string &output);
    static bool searchInGtkRc(const string patter, string &output);

public:
    bool gtkInterfaceFont(string &font);
    string name();
};
