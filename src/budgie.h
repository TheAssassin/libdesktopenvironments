#pragma once

#include "gnome.h"

class BudgieDesktopEnvironment : public GnomeDesktopEnvironment {
public:
    std::string name() override;
};
