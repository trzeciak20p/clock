#include <chrono>
#include <iostream>
#include <string>
#include <array>
#include "src/clock.h"
#include "src/timeHelper.h"
#include "src/terminalHelper.h"
#include "src/settings.h"


int main(int argc, char const *argv[]){
    Settings settings = Settings();
    try{
        handleFlags(argc, argv, settings);
    }catch(const std::string e){
        std::cerr << e << "\r\n";
        std::cerr << "Use -h for help\r\n";
        return -1;
    }catch(const char * e){     // temporary
        displayHelp();
        return 0;
    }

    Clock clock(&settings);
    clock.initialDraw();
    while (true)
    {
        clock.updateNow();
        if (clock.checkForDraw())
        {
            clock.drawTime();
            clock.updateThen();
        }        
    }

    return 0;
}