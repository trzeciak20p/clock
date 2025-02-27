#include "clock.h"

#include <iostream>
#include <chrono>
#include "timeHelper.cpp"
#include "settings.h"

Clock::Clock(Settings settings): settings(settings) {
    
    then = std::chrono::system_clock::now();
    now = std::chrono::system_clock::now();
    
    switch (settings.display_mode)
    {
        // case t_display_mode::SMALL:
        //     displaySmall(lt, settings);    
        //     break;

        // case t_display_mode::DIGITAL:
        //     displayDigital(lt, settings);
        //     break;

        // case t_display_mode::ANALOG:
        //     displayAnalog(lt, settings);
        //     break;

        case t_display_mode::TEXT:
        default:
            // body[0] = "  :  :";
            hours_pos = {1,1};
            minutes_pos = {hours_pos.x+3, hours_pos.y};
            if (settings.display_seconds)
            {
                seconds_pos = {minutes_pos.x+3, minutes_pos.y};
            }       
            break;
    }
    // debug
    hours_pos = {2,2};
    minutes_pos = {5, 2};
    if (settings.display_seconds)
    {
        seconds_pos = {8, 2};
    }  

    if (settings.display_date)
    {
        hours_pos.y += 1;
        minutes_pos.y += 1;
        seconds_pos.y += 1;
    }
    


}

void Clock::initialDraw(){
    system("clear");
    std::cout << "\e[?25l";     // hides cursor
    std::cout << "╔══╦══╦══╗\r\n" <<
                 "║  ║  ║  ║\r\n" <<
                 "╚══╩══╩══╝";
    
    // for (const char *line : body)
    // {
    //     /* code */
    // }

    drawTime();
    std::cout << std::flush;
}

void Clock::drawTime(){
    time_t tt = std::chrono::system_clock::to_time_t(now);
    tm *lt = localtime(&tt);

    drawStringAt(precidingZero(lt->tm_hour), hours_pos);
    drawStringAt(precidingZero(lt->tm_min), minutes_pos);
    if(settings.display_seconds){
        drawStringAt(precidingZero(lt->tm_sec), seconds_pos);
    }
    std::cout << std::flush;
}

void Clock::updateNow(){
    now = std::chrono::system_clock::now();
}

void Clock::updateThen(){
    then = now;
}

bool Clock::checkForDraw(){
    if (settings.display_seconds)
    {
        return getSeconds(now) != getSeconds(then);
    }
    return getMinutes(now) != getMinutes(then);
}

inline void Clock::drawStringAt(std::string str, t_pos pos){
    std::cout << "\e[" << pos.y << ';' << pos.x << 'H' << str;
}
