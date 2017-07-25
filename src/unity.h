#pragma once

#include "desktopenvironments.h"
#include "gnome.h"

class UnityDesktopEnvironment : public GnomeDesktopEnvironment {
public:
    std::string name() override;
};
