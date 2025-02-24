#pragma once

#include <chrono>
#include <string>
#include "settings.h"


void display(std::chrono::_V2::system_clock::time_point &time, const Settings &settings);

inline std::string precidingZero(int num){
    return ((num < 10) ? "0" : "") + std::to_string(num); 
}