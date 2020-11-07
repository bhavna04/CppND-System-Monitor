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
        
        time = StringToTime(t);
        time += ":";
        
        t = (seconds/60) % 60;
        time += StringToTime(t);
        time += ":";
        

        t = seconds % 60;
        time += StringToTime(t);
    }
    
    return time; 
}

string Format::StringToTime(long time)
{
    string str = "";
    if(time < 10)
    {
        str+="0";
    }
    
    str += std::to_string(time);
    return str;
}