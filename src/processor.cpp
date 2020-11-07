#include "processor.h"

#include <string>
#include <vector>

using std::string;
using std::vector;
using namespace LinuxParser;

// DONE: Return the aggregate CPU utilization
float Processor::Utilization() {
  
  
  CalculateCPUUsage();
  unsigned long int totalTime = idle_ + nonIdle;
  unsigned long int PrevTotal = prev_nonIdle + prev_idle;

  unsigned long int delta_total = totalTime - PrevTotal;
  unsigned long int delta_idle = idle_ - prev_idle;

  float cpuUtilization = (float)(delta_total - delta_idle) / delta_total;
  prev_nonIdle = nonIdle;
  prev_idle = idle_;
  return cpuUtilization;
}

void Processor::CalculateCPUUsage()
{
  vector<string> cpuTime = CpuUtilization();

  idle_ = std::stoul(cpuTime[kIdle_]) + std::stoul(cpuTime[kIOwait_]);

  nonIdle =
      std::stoul(cpuTime[kUser_]) + std::stoul(cpuTime[kNice_]) + std::stoul(cpuTime[kSteal_])
      + std::stoul(cpuTime[kSystem_])+ std::stoul(cpuTime[kSoftIRQ_]) 
      + std::stoul(cpuTime[kIRQ_]) + std::stoul(cpuTime[kGuest_]) + 
      std::stoul(cpuTime[kGuestNice_]);
}