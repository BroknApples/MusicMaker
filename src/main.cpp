#include <iostream>

#include "main_window.hpp"

int main(int argc, char* argv[]) {
  MainWindow window("Test Window", 1920, 1080);
  window.init();
  window.run();
  return 0;
}