#pragma once

#include <chrono>
#include <string>
#include "settings.h"


void display(std::chrono::_V2::system_clock::time_point &time, const Settings &settings);

inline std::string precidingZero(int num){
    if(num < 10){
        return "0" + std::to_string(num);
    }
    return std::to_string(num);
}