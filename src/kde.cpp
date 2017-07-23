// own header
#include "kde.h"
// global headers
#include <fstream>
#include <sstream>

bool KDesktopEnvironment::configToolPath(string &path) {
    string programPath;
    
    auto type = [&programPath](string programName) {
        stringstream command;
        command << "type '" << programName << "' 2>&1 1>/dev/null";
        return callProgramAndGetFirstLineOfOutput(command.str(), programPath);
    };

    if (type("kde4-config")) {
        path = programPath;
        return true;
    }

    if (type("kde5-config")) {
        path = programPath;
        return true;
    }

    if (type("kde-config")) {
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
