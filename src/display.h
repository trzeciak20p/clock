#pragma once

#include <chrono>
#include <string>
#include "settings.h"

void displayHelp();
void displayText(tm *lt, const Settings &settings);
void displaySmall(tm *lt, const Settings &settings);
void displayDigital(tm *lt, const Settings &settings);
void displayAnalog(tm *lt, const Settings &settings);
void display(std::chrono::_V2::system_clock::time_point &time, const Settings &settings);
