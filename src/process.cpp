#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid) :processID_(pid)
{
    GetUser();
    GetCommand();
    memUtilization();
    GetUpTime();
    GetCpuUtilization();
}

// DONE: Return this process's ID
int Process::Pid() { return processID_; }

// DONE: Return this process's CPU utilization
float Process::CpuUtilization() { return cpuUsage; }

// DONE: Return the command that generated this process
std::string Process::Command() { return cmd_; }

// DONE: Return this process's memory utilization
std::string Process::Ram() { return mem_; }

// DONE: Return the user (name) that generated this process
std::string Process::User() 
{ 
    return user_ ;
}

// DONE: Return the age of this process (in seconds)
long int Process::UpTime() 
{ 
    return upTime_; 
}

// DONE: Overload the "less than" comparison operator for Process objects
bool Process::operator<(Process const& a) const 
{ 
    return a.cpuUsage < cpuUsage;
}

void Process::GetUser()
{
   user_ = LinuxParser::User(Pid()); 
}

void Process::memUtilization()
{
    std::string ram;
    ram = LinuxParser::Ram(Pid());
    mem_ = (std::to_string(std::stof(ram) * 0.001));
}

void Process::GetUpTime()
{
    upTime_ = LinuxParser::UpTime(Pid());
}

void Process::GetCommand()
{
    cmd_ = LinuxParser::Command(Pid());
}

void Process::GetCpuUtilization()
{
    vector<float> cpuTime = LinuxParser::CpuUtilization(Pid());
    float total_time = cpuTime[LinuxParser::kUTime] + cpuTime[LinuxParser::kSTime]+cpuTime[LinuxParser::kCUTime]+cpuTime[LinuxParser::kCSTime];
    float upTime = LinuxParser::UpTime();
    float seconds = upTime -cpuTime[LinuxParser::kStartTime];
    cpuUsage = 100*(total_time/seconds);
}   