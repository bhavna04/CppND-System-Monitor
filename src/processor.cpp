#include "processor.h"

#include <string>
#include <vector>

using std::string;
using std::vector;
// DONE: Return the aggregate CPU utilization
float Processor::Utilization() {
  vector<string> cpuTime = LinuxParser::CpuUtilization();
  unsigned long int guest_nice = std::stoul(cpuTime.back());
  cpuTime.pop_back();
  unsigned long int guest = std::stoul(cpuTime.back());
  cpuTime.pop_back();
  unsigned long int steal = std::stoul(cpuTime.back());
  cpuTime.pop_back();
  unsigned long int softirq = std::stoul(cpuTime.back());
  cpuTime.pop_back();
  unsigned long int irq = std::stoul(cpuTime.back());
  cpuTime.pop_back();

  int iowait = std::stoul(cpuTime.back());
  cpuTime.pop_back();
  int idle = std::stoul(cpuTime.back());
  cpuTime.pop_back();
  unsigned long int system = std::stoul(cpuTime.back());
  cpuTime.pop_back();
  unsigned long int nice = std::stoul(cpuTime.back());
  cpuTime.pop_back();
  unsigned long int user = std::stoul(cpuTime.back());
  cpuTime.pop_back();

  unsigned long idle_ = idle + iowait;

  unsigned long int nonIdle =
      user + nice + steal + system + softirq + irq + guest + guest_nice;
  unsigned long int totalTime = idle_ + nonIdle;
  unsigned long int PrevTotal = prev_nonIdle + prev_idle;

  unsigned long int delta_total = totalTime - PrevTotal;
  unsigned long int delta_idle = idle_ - prev_idle;

  float cpuUtilization = (float)(delta_total - delta_idle) / delta_total;
  prev_nonIdle = nonIdle;
  prev_idle = idle_;
  return cpuUtilization;
}
