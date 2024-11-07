#include "main_window.hpp"
#include "logger.hpp"

int main(int argc, char* argv[]) {
  Logger logger;

  MainWindow window("Test Window", 1920, 1080, logger);
  window.run();

  logger.printInTerminal();
  return 0;
}