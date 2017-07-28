#pragma once

#include "desktopenvironments.h"

class KDesktopEnvironment : public IDesktopEnvironment {
private:
    static bool configToolPath(std::string &path);
    static bool searchInKdeConfig(std::string pattern, std::string &output);

public:
    bool gtkInterfaceFont(std::string &font);
    std::string name();
};
