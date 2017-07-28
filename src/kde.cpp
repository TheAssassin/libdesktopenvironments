// own header
#include "kde.h"
// global headers
#include <fstream>
#include <sstream>

using namespace std;

bool KDesktopEnvironment::configToolPath(string &path) {
    string programPath;

    if (type("kde4-config", programPath)) {
        path = programPath;
        return true;
    }

    if (type("kde5-config", programPath)) {
        path = programPath;
        return true;
    }

    if (type("kde-config", programPath)) {
        path = programPath;
        return true;
    }

    return false;
}

bool KDesktopEnvironment::searchInKdeConfig(const string pattern, string &output) {
    string kdeConfigProgram;

    if (configToolPath(kdeConfigProgram)) {
        stringstream command;
        command << kdeConfigProgram << " " << "--localprefix";

        string kdeConfigDir;

        if (!callProgramAndGetFirstLineOfOutput(command.str(), kdeConfigDir)) {
            cerr << "Failed to call KDE configuration program " << kdeConfigProgram << "!" << endl;
            return false;
        }

        stringstream pathToKdeGlobals;
        pathToKdeGlobals << kdeConfigDir << "/share/config/kdeglobals";

        ifstream kdeGlobalsFile(pathToKdeGlobals.str().c_str());

        string line;
        if (searchLineInFile(kdeGlobalsFile, pattern, line)) {
            output = line;
            return true;
        }

        return false;
    }

    return false;
}

bool KDesktopEnvironment::gtkInterfaceFont(string &font) {
    string output;
    string pattern = "Font=";

    if(searchInKdeConfig(pattern, output)) {
        font = output.substr(output.find(pattern) + pattern.length());
        removeQuotationMarks(font);
        return true;
    }

    // last chance is to get the font from the GTK RC
    return getFontFromGtkRc(font);
}

string KDesktopEnvironment::name() {
    return "KDE";
}
