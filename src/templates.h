#pragma once

const char* getClockBodyText(bool seconds_ver){
    if (seconds_ver)
    {
        return "  :  :";
    }
    return "  :";
}
const char* getClockBodySmall(bool seconds_ver){
    if (seconds_ver)
    {
        return "╔══╦══╦══╗\r\n║  ║  ║  ║\r\n╚══╩══╩══╝";
    }
    return "╔════╦════╗\r\n║    ║    ║\r\n╚════╩════╝";
}
const char* getClockBodyDigital(bool seconds_ver){
    if (seconds_ver)
    {
        return "  :  :";
    }
    return "  :";
}
const char* getClockBodyAnalog(bool seconds_ver){
    if (seconds_ver)
    {
        return "  :  :";
    }
    return "  :";
}