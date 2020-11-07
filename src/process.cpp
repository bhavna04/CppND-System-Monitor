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
int Process::Pid() const { return processID_; }

// DONE: Return this process's CPU utilization
float Process::CpuUtilization() const { return cpuUsage; }

// DONE: Return the command that generated this process
std::string Process::Command() const { return cmd_; }

// DONE: Return this process's memory utilization
std::string Process::Ram() const { return mem_; }

// DONE: Return the user (name) that generated this process
std::string Process::User() const
{ 
    return user_ ;
}

// DONE: Return the age of this process (in seconds)
long int Process::UpTime() const
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
    mem_ = LinuxParser::Ram(Pid());
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
    cpuUsage = LinuxParser::ProcessCpuUtilization(Pid(),UpTime());
}   