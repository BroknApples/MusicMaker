#include "logger.hpp"

/**
 * @brief Default logger
 */
Logger::Logger() {
  // allocate default logger space
  log_.reserve(100);
  start_time_ = std::chrono::high_resolution_clock::now();
}

/**
 * @brief get time elapsed since program start
 */
double Logger::getTime() {
  auto curr_time = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> t =  curr_time - start_time_;
  double time_elapsed = t.count();

  // round to two decimal places
  time_elapsed = std::ceil(time_elapsed * 100.0) / 100.0;
  return time_elapsed;
}

void Logger::log(LogHeader header, std::string data) {
  log_[header].push_back(data);
}

/**
 * Print all log data to console
 */
void Logger::printInTerminal() {
  for (int i = 0; i < HEADER_COUNT; i++) {
    // print header
    switch(i) {
      case DEBUG_LOG:
        std::cout << "[Debug]" << std::endl;
        break;
      case RUNTIME_LOG:
        std::cout << "[Runtime]" << std::endl;
        break;
      case MISC_LOG:
        std::cout << "[Misc]" << std::endl;
        break;
    }

    // print data
    const int kSize = log_[i].size();
    for (int j = 0; j < kSize; j++) {
      double time = getTime();
      std::cout << time << ": " << log_[i][j] << std::endl;
    }
  }
}