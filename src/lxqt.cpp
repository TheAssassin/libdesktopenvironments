// own header
#include "lxqt.h"

using namespace std;

bool LxqtDesktopEnvironment::gtkInterfaceFont(string &font) {
    // TODO: find proper method to query the font from LXQt

    // last chance is to get the font from the GTK RC
    return getFontFromGtkRc(font);
}

string LxqtDesktopEnvironment::name() {
    return "LXQt";
}
