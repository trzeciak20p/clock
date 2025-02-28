#pragma once

#include <string>

enum t_display_mode{
    INVALID,
    TEXT,
    SMALL,
    DIGITAL,
    ANALOG
};


class Settings
{
    public:
        Settings(){};
        void setDisplayMode(std::string mode);

        bool display_date = false;
        bool display_seconds = true;
        bool ascii_only = false;
        t_display_mode display_mode = t_display_mode::TEXT;
};