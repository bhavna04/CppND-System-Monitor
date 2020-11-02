#include <string>

#include "format.h"

using std::string;

// DONE: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
string Format::ElapsedTime(long seconds) 
{ 
    string time = "00:00:00";
    long t=0;
    if(seconds > 0)
    {
        t = seconds/3600;
        time = std::to_string(t) + ":";
        t = (seconds/60) % 60;
        time += std::to_string(t)+":";
        t = seconds % 60;
        time += std::to_string(t);
    }
    
    return time; 
}