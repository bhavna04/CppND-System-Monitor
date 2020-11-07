#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "linux_parser.h"
class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp
  void CalculateCPUUsage();

  // TODO: Declare any necessary private members
 private:
    unsigned long int prev_idle=0;
    unsigned long int prev_nonIdle = 0;
    unsigned long int idle_ =0;
    unsigned long int nonIdle = 0;
};

#endif