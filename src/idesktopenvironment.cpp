// own header
#include "desktopenvironments.h"

// global headers
#include <sstream>
#include <typeinfo>
#include <vector>

// implementation headers
#include "gnome.h"
#include "budgie.h"
#include "cinnamon.h"
#include "deepin.h"
#include "i3.h"
#include "kde.h"
#include "lxde.h"
#include "lxqt.h"
#include "mate.h"
#include "unity.h"
#include "xfce.h"

void IDesktopEnvironment::stripNewlineCharacters(string &str) {
    str.erase(remove(str.begin(), str.end(), '\n'), str.end());
}

bool IDesktopEnvironment::stringStartsWith(const string str, const string prefix) {
    return std::equal(prefix.begin(), prefix.end(), str.begin());
}

void IDesktopEnvironment::stringToLower(string &str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}

bool IDesktopEnvironment::searchLineInFile(ifstream &file, const string pattern, string &line) {
    string currentLine;
    while (getline(file, currentLine)) {
        if (currentLine.find(pattern) != string::npos) {
            line = currentLine;
            return true;
        }
    }
    return false;
}

bool IDesktopEnvironment::searchLineInGtkRc(const string pattern, string &output) {
    if (pattern.length() <= 0)
        return false;

    stringstream pathToGtk2Rc;
    pathToGtk2Rc << getenv("HOME") << "/.gtkrc-2.0";

    stringstream pathToGtk3Rc;
    pathToGtk3Rc << pathToConfigHome() << "/.gtk-3.0/settings.ini";

    vector<string> gtkRcPaths = {pathToGtk2Rc.str(), pathToGtk3Rc.str()};

    for(auto &gtkRcPath : gtkRcPaths) {
        ifstream gtkRcFile(gtkRcPath.c_str());

        if (gtkRcFile) {
            string currentOutput;

            if (searchLineInFile(gtkRcFile, pattern, currentOutput)) {
                output = currentOutput;
                return true;
            }
        }
    }

    return false;
}

string IDesktopEnvironment::pathToConfigHome() {
    char *xdgConfigHome = getenv("XDG_CONFIG_HOME");

    string configDirectory;

    if(xdgConfigHome != nullptr) {
        configDirectory = xdgConfigHome;
    } else {
        stringstream path;
        path << getenv("HOME") << "/.config";
        configDirectory = path.str();
    }

    return configDirectory;
}

bool IDesktopEnvironment::getFontFromGtkRc(string &font) {
    string pattern;
    string output;

    pattern = "gtk-font-name=";
    if(searchLineInGtkRc(pattern, output)) {
        font = output.substr(output.find(pattern) + pattern.length());
        removeQuotationMarks(font);
        return true;
    }

    // fallback if above isn't found
    pattern = "font_name=";
    if(searchLineInGtkRc(pattern, output)) {
        font = output.substr(output.find(pattern) + pattern.length());
        removeQuotationMarks(font);
        return true;
    }

    return false;
}

void IDesktopEnvironment::removeQuotationMarks(string &str) {
    str.erase(remove(str.begin(), str.end(), '"'), str.end());
    str.erase(remove(str.begin(), str.end(), '\''), str.end());
}

bool IDesktopEnvironment::callProgramAndGetFirstLineOfOutput(const string command, string &output) {
    FILE *stream = popen(command.c_str(), "r");

    if (stream == nullptr)
        return false;

    char *line;
    size_t lineSize = 0;
    if(!getline(&line, &lineSize, stream))
        return false;

    output = line;
    free(line);

    auto retCode = pclose(stream);

    if (retCode != 0)
        return false;

    stripNewlineCharacters(output);

    return true;
}

IDesktopEnvironment* IDesktopEnvironment::getInstance(const string desktopEnvironment) {
    string copy = desktopEnvironment;

    stringToLower(copy);

    if (copy.length() > 0) {
        if (stringStartsWith(copy, "kde")) {
            return new KDesktopEnvironment();
        } else if (stringStartsWith(copy, "cinnamon")) {
            return new CinnamonDesktopEnvironment();
        } else if (stringStartsWith(copy, "gnome")) {
            return new GnomeDesktopEnvironment();
        } else if (stringStartsWith(copy, "unity")) {
            return new UnityDesktopEnvironment();
        } else if(stringStartsWith(copy, "budgie")) {
            return new BudgieDesktopEnvironment();
        } else if (stringStartsWith(copy, "mate")) {
            return new MateDesktopEnvironment();
        } else if (stringStartsWith(copy, "xfce")) {
            return new XfceDesktopEnvironment();
        } else if (stringStartsWith(copy, "lxde")) {
            return new LxdeDesktopEnvironment();
        } else if (stringStartsWith(copy, "lxqt")) {
            return new LxqtDesktopEnvironment();
        } else if (stringStartsWith(copy, "deepin")) {
            return new DeepinDesktopEnvironment();
        } else if (stringStartsWith(copy, "i3")) {
            return new I3DesktopEnvironment();
        }
    }

    return nullptr;
}

IDesktopEnvironment* IDesktopEnvironment::getInstance() {
    char *xdgCurrentDesktop = getenv("XDG_CURRENT_DESKTOP");

    if (xdgCurrentDesktop != nullptr) {
        string xdgCurrentDesktopValue = xdgCurrentDesktop;

        if (xdgCurrentDesktopValue.length() > 0) {
            // lower case for comparison
            stringToLower(xdgCurrentDesktopValue);

            // fix Cinnamon's "interpretion" of XDG_CURRENT_DESKTOP, which usually is "X-Cinnamon"
            if(xdgCurrentDesktopValue.find("cinnamon") != string::npos)
                xdgCurrentDesktopValue = "cinnamon";

            return getInstance(xdgCurrentDesktopValue);
        }
    }

    return nullptr;
}
