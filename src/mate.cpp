#include "mate.h"

bool MateDesktopEnvironment::gtkInterfaceFont(string &font) {
    if(!callProgramAndGetFirstLineOfOutput("gsettings get org.mate.interface font-name", font))
        return false;

    removeQuotationMarks(font);
    return true;
}

string MateDesktopEnvironment::name() {
    return "MATE";
}
