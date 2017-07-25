// own header
#include "gnome.h"
// global headers
#include <sstream>

using namespace std;

bool GnomeDesktopEnvironment::gtkInterfaceFont(string &font) {
    // first of all, try to read font from the GTK RC
    if (getFontFromGtkRc(font))
        return true;

    auto type = [](string programName) {
        string programPath;
        stringstream command;
        command << "type '" << programName << "'";
        return callProgramAndGetFirstLineOfOutput(command.str(), programPath);
    };

    // next, try to find gsettings, and call it to get the font value
    if (type("gsettings") && callProgramAndGetFirstLineOfOutput("gsettings get org.gnome.desktop.interface font-name", font)) {
        removeQuotationMarks(font);
        return true;
    }

    // if gsettings is not available, gconftool-2 might be available
    if (type("gconftool-2") && callProgramAndGetFirstLineOfOutput("gconftool-2 -g /desktop/gnome/interface/font_name", font)) {
        removeQuotationMarks(font);
        return true;
    }

    return false;
}

string GnomeDesktopEnvironment::name() {
    return "GNOME";
}
