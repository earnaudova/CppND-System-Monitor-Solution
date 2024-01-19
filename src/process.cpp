#include "process.h"

#include <unistd.h>

#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

// TODO: Return this process's ID
int Process::Pid() const { return Process::pid_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() const {
  float utilization =
      ((static_cast<float>(LinuxParser::ActiveJiffies(Process::Pid())) /
        static_cast<float>(sysconf(_SC_CLK_TCK))) /
       static_cast<float>(LinuxParser::UpTime(Process::Pid())));
  return utilization;
}

// TODO: Return the command that generated this process
string Process::Command() const { return Process::command_; }

// TODO: Return this process's memory utilization
string Process::Ram() const { return LinuxParser::Ram(Process::Pid()); }

// TODO: Return the user (name) that generated this process
string Process::User() const { return Process::user_; }

// TODO: Return the age of this process (in seconds)
long Process::UpTime() { return LinuxParser::UpTime(Process::Pid()); }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const {
  bool res;
  res = CpuUtilization() < a.CpuUtilization();
  return res;
}