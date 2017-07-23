#include <iostream>
#include "desktopenvironments.h"

using namespace std;

int main() {
    bool failed = false;

    cout << "libdesktopenvironments demo" << endl
         << "===========================" << endl << endl;

    auto *desktopEnvironment = IDesktopEnvironment::getInstance();

    if (desktopEnvironment == nullptr) {
        cerr << "Error: could not detect desktop environment!" << endl;
        return 1;
    }

    cout << "Desktop environment: " << desktopEnvironment->name() << endl;

    string font;

    if (!desktopEnvironment->gtkInterfaceFont(font)) {
        cerr << "Error: could not detect font name!" << endl;
        failed = true;
    } else {
        cout << "Interface font:      " << font << endl;
    }

    delete desktopEnvironment;

    return failed ? 1 : 0;
}