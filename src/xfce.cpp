#include "xfce.h"

bool XfceDesktopEnvironment::gtkInterfaceFont(string &font) {
    return callProgramAndGetFirstLineOfOutput("xfconf-query -c xsettings -p /Gtk/FontName", font);
}

string XfceDesktopEnvironment::name() {
    return "XFCE";
}
