#include "cinnamon.h"

using namespace std;

bool CinnamonDesktopEnvironment::gtkInterfaceFont(string &font) {
    // Cinnamon uses the GNOME infrastructure, too
    if(callProgramAndGetFirstLineOfOutput("gsettings get org.cinnamon.desktop.interface font-name", font)) {
        removeQuotationMarks(font);
        return true;
    }

    // last chance is to get the font from the GTK RC
    return getFontFromGtkRc(font);
}

string CinnamonDesktopEnvironment::name() {
    return "Cinnamon";
}
