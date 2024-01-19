#include "format.h"

#include <string>

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) {
  int hours_ = seconds / 3600;
  int minutes_ = (seconds % 3600) / 60;
  int seconds_ = (seconds % 3600) % 60;
  string HH, MM, SS;
  if (hours_ < 10)
    HH = "0" + std::to_string(hours_);
  else
    HH = std::to_string(hours_);
  if (minutes_ < 10)
    MM = "0" + std::to_string(minutes_);
  else
    MM = std::to_string(minutes_);
  if (seconds_ < 10)
    SS = "0" + std::to_string(seconds_);
  else
    SS = std::to_string(seconds_);
  string time_format = HH + ":" + MM + ":" + SS;

  return time_format;
}