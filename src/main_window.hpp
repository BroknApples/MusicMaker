#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <string>

#include <SFML/Window.hpp>

class MainWindow{
 private:
  std::string window_name;
  int window_width;
  int window_height;

 public:
  MainWindow(std::string window_name, int width, int height);

  void init();
  void run();
};

#endif // MAIN_WINDOW_H