#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <linux_parser.h>
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  Process(int);
  int Pid() const;                               // TODO: See src/process.cpp
  std::string User() const;                      // TODO: See src/process.cpp
  std::string Command() const;                   // TODO: See src/process.cpp
  float CpuUtilization() const;                  // TODO: See src/process.cpp
  std::string Ram() const;                       // TODO: See src/process.cpp
  long int UpTime() const;                       // TODO: See src/process.cpp
  bool operator<(Process const& a) const;  // TODO: See src/process.cpp
  void GetUser();
  void memUtilization();
  void GetUpTime();
  void GetCommand();
  void GetCpuUtilization();

  // DONE: Declare any necessary private members
 private:
    int processID_ =0 ;
    std::string user_;
    std::string cmd_;
    std::string mem_;
    long int upTime_=0;
    float cpuUsage = 0;
};

#endif