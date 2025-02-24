#pragma once

#include <fstream>

enum t_display_mode{
    TEXT,
    SMALL,
    DIGITAL,
    ANALOG
};

class Settings
{
    public:
        Settings(int argc, char const *argv);
        Settings();

        bool display_date = false;
        bool display_seconds = false;
        t_display_mode display_mode = t_display_mode::TEXT;
};