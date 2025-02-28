#include "clock.h"

const char* getClockBodyText(bool seconds_ver){
    if (seconds_ver)
    {
        return "  :  :";
    }
    return "  :";
}
const char* getClockBodySmall(bool seconds_ver){
    if (seconds_ver)
    {
        return "╔══╦══╦══╗\r\n║  ║  ║  ║\r\n╚══╩══╩══╝";
    }
    return "╔════╦════╗\r\n║    ║    ║\r\n╚════╩════╝";
}
const char* getClockBodyDigital(bool seconds_ver){
    if (seconds_ver)
    {
        return "  :  :";
    }
    return "  :";
}
const char* getClockBodyAnalog(bool seconds_ver){
    if (seconds_ver)
    {
        return "  :  :";
    }
    return "  :";
}

void Clock::loadTemplate(){
    switch (settings->display_mode)
    {
        case t_display_mode::SMALL:
            body = getClockBodySmall(settings->display_seconds);
            hours_pos = {2,2};
            minutes_pos = {5,2};
            seconds_pos = {8,2}; 
            if (!settings->display_seconds)
            {
                hours_pos = {3,2};
                minutes_pos = {8,2};
            }        
            break;

        case t_display_mode::DIGITAL:
            body = getClockBodyDigital(settings->display_seconds);
            // break;

        case t_display_mode::ANALOG:
            body = getClockBodyAnalog(settings->display_seconds);
            // break;

        case t_display_mode::TEXT:
        default:
            body = getClockBodyText(settings->display_seconds);
            hours_pos = {1,1};
            minutes_pos = {4, 1};
            seconds_pos = {7, 1};                 
            break;
    }

    if (settings->display_date)
    {
        hours_pos.y += 1;
        minutes_pos.y += 1;
        seconds_pos.y += 1;
    }
}