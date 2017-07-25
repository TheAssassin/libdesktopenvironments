#include "deepin.h"

using namespace std;

bool DeepinDesktopEnvironment::gtkInterfaceFont(string &font) {
    // TODO: find proper way to query the font name from Deepin

    // last chance is to get the font from the GTK RC
    return getFontFromGtkRc(font);
}

string DeepinDesktopEnvironment::name() {
    return "Deepin";
}
