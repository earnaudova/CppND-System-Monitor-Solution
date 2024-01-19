#include "processor.h"

#include "linux_parser.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
  long total_new = LinuxParser::Jiffies();
  long idle_new = LinuxParser::IdleJiffies();
  long total = total_new - Processor::total_old_;
  long idle = idle_new - Processor::idle_old_;
  float cpu_utilization =
      static_cast<float>(total - idle) / static_cast<float>(total);

  total_old_ = total_new;
  idle_old_ = idle_new;

  return cpu_utilization;
}