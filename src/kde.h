#pragma once

#include "desktopenvironments.h"

class KDesktopEnvironment : public IDesktopEnvironment {
private:
    static bool configToolPath(std::string &path);
    static bool searchInKdeConfig(const std::string pattern, std::string &output);
    static bool searchInGtkRc(const std::string patter, std::string &output);

public:
    bool gtkInterfaceFont(std::string &font);
    std::string name();
};
