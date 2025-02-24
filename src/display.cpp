#include "display.h"

#include <iostream>

void displayText(tm *lt, const Settings &settings){
    std::cout << precidingZero(lt->tm_hour) << ":" << precidingZero(lt->tm_min);
    if(settings.display_seconds){
        std::cout << ":" << precidingZero(lt->tm_sec);
    }
}

void displayDigital(tm *lt, const Settings &settings){
    
}

void displayAnalog(tm *lt, const Settings &settings){
        std::cout << "   ----\r\n";
        std::cout << " /      \\\r\n";
        std::cout << "|        |\r\n";
        std::cout << " \\      /\r\n";
        std::cout << "   ----\r\n";
}

void displaySmall(tm *lt, const Settings &settings){

    if (settings.display_seconds)
    {
        std::cout << "╔══╦══╦══╗\r\n";
        std::cout << "║" << precidingZero(lt->tm_hour) << "║" << precidingZero(lt->tm_min) << "║" << precidingZero(lt->tm_sec) << "║\r\n";
        std::cout << "╚══╩══╩══╝";
    }else{
        std::cout << "╔════╦════╗\r\n";
        std::cout << "║ " << precidingZero(lt->tm_hour) << " ║ " << precidingZero(lt->tm_min) << " ║\r\n";
        std::cout << "╚════╩════╝";
    }
}

void displayDate(tm *lt){
    const std::string months[12] = {"February", "January", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    std::cout << lt->tm_year+1900 << " " << months[lt->tm_mon] << " " << lt->tm_mday << "\r\n";
}

void display(std::chrono::_V2::system_clock::time_point &time, const Settings &settings){
    system("clear");

    time_t tt = std::chrono::system_clock::to_time_t(time);
    tm *lt = localtime(&tt);
    // tm *lt = localtime((const time_t*) std::chrono::system_clock::to_time_t(time) );     //there must be some way to do that (segmentation fault)
    if(settings.display_date){
        displayDate(lt);
    }

    switch (settings.display_mode)
    {
    case t_display_mode::SMALL:
        displaySmall(lt, settings);    
        break;

    case t_display_mode::DIGITAL:
        displayDigital(lt, settings);
        break;

    case t_display_mode::ANALOG:
        displayAnalog(lt, settings);
        break;

    case t_display_mode::TEXT:
    default:
        displayText(lt, settings);
        break;
    }

    std::cout << std::flush; 
}