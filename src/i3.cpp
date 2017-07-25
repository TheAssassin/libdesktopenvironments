#include "i3.h"

using namespace std;

bool I3DesktopEnvironment::gtkInterfaceFont(string &font) {
    // TODO: Find proper way to query the font name from i3

    // last chance is to get the font from the GTK RC
    return getFontFromGtkRc(font);
}

string I3DesktopEnvironment::name() {
    return "i3";
}
