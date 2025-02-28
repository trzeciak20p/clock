#include "clock.h"

#include <iostream>
#include <chrono>
#include "settings.h"
#include "timeHelper.h"
#include "templates.h"

Clock::Clock(Settings *settings): settings(settings) {
    
    then = std::chrono::system_clock::now();
    now = std::chrono::system_clock::now();
    
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

void Clock::initialDraw(){
	std::cout << "\e[2J\e[H";   // clear terminal, return to it's (0,0)
    if (settings->display_date)
    {
        drawDate();
    }
    std::cout << "\e[?25l";     // hides cursor
    std::cout << body;
    std::cout << "\r\n\e[s";    // save cursor position after the body
    drawTime();
    std::cout << std::flush;
}

void Clock::drawDate(){
    time_t tt = std::chrono::system_clock::to_time_t(now);
    tm *lt = localtime(&tt);
    constexpr const char* months[12] = {"February", "January", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    std::cout << lt->tm_year+1900 << " " << months[lt->tm_mon] << " " << lt->tm_mday << "\r\n";
}

void Clock::drawTime(){
    time_t tt = std::chrono::system_clock::to_time_t(now);
    tm *lt = localtime(&tt);

    drawStringAt(precidingZero(lt->tm_hour), hours_pos);
    drawStringAt(precidingZero(lt->tm_min), minutes_pos);
    if(settings->display_seconds){
        drawStringAt(precidingZero(lt->tm_sec), seconds_pos);
    }
    std::cout << "\e[u";    // load saved cursor position (so text after closing app doesn't override clock)
    std::cout << std::flush;
}

void Clock::updateNow(){
    now = std::chrono::system_clock::now();
}

void Clock::updateThen(){
    then = now;
}

bool Clock::checkForDraw(){
    if (settings->display_seconds)
    {
        return getSeconds(now) != getSeconds(then);
    }
    return getMinutes(now) != getMinutes(then);
}

inline void Clock::drawStringAt(std::string str, t_pos pos){
    std::cout << "\e[" << pos.y << ';' << pos.x << 'H' << str;
}
