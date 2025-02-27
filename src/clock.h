#pragma once

#include <chrono>
#include "settings.h"


struct t_pos{
    int x;
    int y;
};


class Clock{
    public:
        Clock(Settings *settings);
        void initialDraw();
        void drawDate();
        void drawTime();     
        void updateThen();      // sets then to now
        void updateNow();       
        bool checkForDraw();    // checks if time should be redrawn
    
    private:
        void drawStringAt(std::string str, t_pos pos);
        
        const char *body{};
        Settings *settings{};
        t_pos hours_pos{};
        t_pos minutes_pos{};
        t_pos seconds_pos{};

        std::chrono::_V2::system_clock::time_point then{};
        std::chrono::_V2::system_clock::time_point now{};
};