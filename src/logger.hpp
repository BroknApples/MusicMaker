#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <cmath>

enum LogHeader {
  DEBUG_LOG,
  RUNTIME_LOG,
  MISC_LOG,
  HEADER_COUNT
};

class Logger {
 private:
  std::vector<std::vector<std::string>> log_;

  std::chrono::high_resolution_clock::time_point start_time_;

 public:
  Logger();

  double getTime();

  void log(LogHeader header, std::string data);
  void printInTerminal();
};

#endif // LOGGER_HPP