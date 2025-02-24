#include "settings.h"

#include <string>

void Settings::setDisplayMode(std::string mode){
    display_mode = t_display_mode::INVALID;
    if (mode == "text" || mode == "t")
    {
        display_mode = t_display_mode::TEXT;
    }else if (mode == "small" || mode == "s")
    {
        display_mode = t_display_mode::SMALL;
    }else if (mode == "digital" || mode == "d")
    {
        display_mode = t_display_mode::DIGITAL;
    }else if (mode == "analog" || mode == "a")
    {
        display_mode = t_display_mode::ANALOG;
    }
}