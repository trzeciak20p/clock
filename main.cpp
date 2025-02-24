#include <chrono>
#include <iostream>
#include <string>
#include <map>
#include "src/settings.h"
#include "src/display.h"


inline int getSeconds(std::chrono::_V2::system_clock::time_point &time){
    return std::chrono::duration_cast<std::chrono::seconds>(time.time_since_epoch()).count();
}

inline int getMinutes(std::chrono::_V2::system_clock::time_point &time){
    return std::chrono::duration_cast<std::chrono::minutes>(time.time_since_epoch()).count();
}


void handleFlags(int argc, char const *argv[]){
    std::map<std::string, std::string> flags;
}

bool checkIfUpdate(std::chrono::_V2::system_clock::time_point &then, std::chrono::_V2::system_clock::time_point &now, bool display_seconds){
    if (display_seconds)
    {
        return getSeconds(now) != getSeconds(then);
    }
    return getMinutes(now) != getMinutes(then);
}

int main(int argc, char const *argv[]){
    
    // handleFlags(argc, argv);
    Settings settings = Settings();

    auto then = std::chrono::system_clock::now();
    display(then, settings);

    while (true)
    {
        auto now = std::chrono::system_clock::now();
        // std::cout << getSeconds(now) << " " << getSeconds(then) << "\r\n"; 
        if (checkIfUpdate(then, now, settings.display_seconds))
        {
            display(now, settings);

            then = now;
        }        
    }

    return 0;
}