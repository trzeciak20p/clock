#pragma once

#include <iostream>
#include "settings.h"

void displayHelp(){
    std::cout << "Usage: clock [flags]\r\n" <<
        "-h, -help \t\tdisplays help\r\n" <<
        "-d, -date \t\tenable date display\r\n" <<
        "-ns, -no-seconds \thides seconds\r\n" <<
        "-m, -mode <mode> \tchanges the looks\r\n" << 
        "\t\t\t<text, small, digital, analog>\r\n"; 
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
            throw "";
        } 
    }
    for (int i = 1; i < argc; i++)
    {
        std::string arg(argv[i]); 
        if(arg == "-d" || arg == "-date"){
            settings.display_date = true;        
        }if(arg == "-a" || arg == "-ascii-only"){
            settings.ascii_only = true;
        }else if(arg == "-ns" || arg == "-no-seconds"){
            settings.display_seconds = false;
        }else if(arg == "-m" || arg == "-mode"){
            if (++i == argc)
            {
                throw (std::string)"No mode specified after -m";
            }       
            settings.setDisplayMode(argv[i]);
            if (settings.display_mode == t_display_mode::INVALID)
            {
                throw "Unrecognized mode value: " + (std::string)argv[i] + "\r\nUse: text, small, digital, analog";
            }               
        }else if(!(arg == "-h" || arg == "-help")){
            throw "Unrecognized parameter: " + arg;
        }  
    }
}

