#include <chrono>
#include <iostream>
#include <string>

// #include <ctime>
// #include <iomanip>


inline int getSeconds(std::chrono::_V2::system_clock::time_point &time){
    return std::chrono::duration_cast<std::chrono::seconds>(time.time_since_epoch()).count();
}

inline std::string precidingZero(int num){
    if(num < 10){
        return "0" + std::to_string(num);
    }
    return std::to_string(num);
}

void display(std::chrono::_V2::system_clock::time_point &time){
    system("clear");

    // std::cout << getSeconds(time) << "\r\n";
    time_t tt = std::chrono::system_clock::to_time_t(time);
    tm *lt = localtime(&tt);
    // tm *lt = localtime((const time_t*) std::chrono::system_clock::to_time_t(time) );     //there must be some way to do that (segmentation fault)
    std::cout << "╔══╦══╦══╗\r\n";
    std::cout << "║" << precidingZero(lt->tm_hour) << "║" << precidingZero(lt->tm_min) << "║" << precidingZero(lt->tm_sec) << "║\r\n";
    std::cout << "╚══╩══╩══╝";
    std::cout << std::flush; 
}


int main(int argc, char const *argv[])
{
    auto then = std::chrono::system_clock::now();
    
    while (true)
    {
        auto now = std::chrono::system_clock::now();
        // std::cout << getSeconds(now) << " " << getSeconds(then) << "\r\n"; 
        if (getSeconds(now) != getSeconds(then))    // checking if update is needed
        {
            display(now);

            then = now;
        }        
    }

    return 0;
}