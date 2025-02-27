#pragma once

#include <chrono>
#include <string>


inline int getSeconds(std::chrono::_V2::system_clock::time_point &time){
    return std::chrono::duration_cast<std::chrono::seconds>(time.time_since_epoch()).count();
}

inline int getMinutes(std::chrono::_V2::system_clock::time_point &time){
    return std::chrono::duration_cast<std::chrono::minutes>(time.time_since_epoch()).count();
}

inline std::string precidingZero(int num){
    return ((num < 10) ? '0' : '\0') + std::to_string(num); 
}