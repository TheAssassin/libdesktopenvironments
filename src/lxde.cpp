// own header
#include "lxde.h"

using namespace std;

bool LxdeDesktopEnvironment::gtkInterfaceFont(string &font) {
    auto configDirectory = pathToConfigHome();

    ifstream configFile;
    configFile.open(configDirectory + "/lxde/config");

    if(!configFile)
        configFile.open(configDirectory + "/lxsession/Lubuntu/desktop.conf");

    if(!configFile)
        configFile.open(configDirectory + "/lxsession/LXDE/desktop.conf");

    if(!configFile)
        return false;

    string pattern = "sGtk/FontName=";

    string line;
    if(searchLineInFile(configFile, pattern, line)) {
        font = line.substr(line.find(pattern) + pattern.length());
        return true;
    }

    // last chance is to get the font from the GTK RC
    return getFontFromGtkRc(font);
}

string LxdeDesktopEnvironment::name() {
    return "LXDE";
}
