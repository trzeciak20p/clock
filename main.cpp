#include <chrono>
#include <iostream>
#include <string>
#include <array>
#include "src/settings.h"
#include "src/display.h"


inline int getSeconds(std::chrono::_V2::system_clock::time_point &time){
    return std::chrono::duration_cast<std::chrono::seconds>(time.time_since_epoch()).count();
}

inline int getMinutes(std::chrono::_V2::system_clock::time_point &time){
    return std::chrono::duration_cast<std::chrono::minutes>(time.time_since_epoch()).count();
}

void handleFlags(int argc, char const *argv[], Settings &settings){    
    if(argc < 2){
        return;
    }
    if (argv[1][0] != '-')
    {
        throw "unexpected value: " + (std::string)argv[1];
    }

    for (int i = 1; i < argc; i++)
    {
        std::string arg(argv[i]); 
        if(arg == "-h" || arg == "-help"){
            displayHelp();
            throw (std::string)"";
        } 
    }
    for (int i = 1; i < argc; i++)
    {
        std::string arg(argv[i]); 
        if(arg == "-d" || arg == "-date"){
            settings.display_date = true;
        }else if(arg == "-ns" || arg == "-no-seconds"){
            settings.display_seconds = false;
        }else if(arg == "-m" || arg == "-mode"){
            if (++i == argc)
            {
                throw (std::string)"no mode specified after -m";
            }       
            settings.setDisplayMode(argv[i]);
            if (settings.display_mode == t_display_mode::INVALID)
            {
                throw "unrecognized mode value: " + (std::string)argv[i] + "\r\nuse: text, small, digital, analog";
            }               
        }else if(!(arg == "-h" || arg == "-help")){
            throw "urecognized parameter: " + arg;
        }  
    }
}

bool checkIfUpdate(std::chrono::_V2::system_clock::time_point &then, std::chrono::_V2::system_clock::time_point &now, bool display_seconds){
    if (display_seconds)
    {
        return getSeconds(now) != getSeconds(then);
    }
    return getMinutes(now) != getMinutes(then);
}

int main(int argc, char const *argv[]){
    Settings settings = Settings();
    try{
        handleFlags(argc, argv, settings);
    }catch(const std::string e){
        std::cerr << e << '\n';
        return -1;
    } 

    auto then = std::chrono::system_clock::now();
    display(then, settings);

    while (true)
    {
        auto now = std::chrono::system_clock::now();
        if (checkIfUpdate(then, now, settings.display_seconds))
        {
            display(now, settings);
            then = now;
        }        
    }

    return 0;
}