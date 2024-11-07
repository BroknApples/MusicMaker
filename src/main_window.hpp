#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <imgui.h>
#include <imgui-SFML.h>
#include <SFML/Graphics.hpp>

#include "logger.hpp"

class MainWindow{
 private:
  // window data
  int width_;
  int height_;
  sf::String window_name_;

  Logger& logger_;

  void init(sf::RenderWindow& window);
  void cleanup();

 public:
  // Initialize instance
  MainWindow(sf::String window_name, int width, int height, Logger& logger)
    : window_name_(window_name), width_(width), height_(height), logger_(logger) {};

  void run();
};

#endif // MAIN_WINDOW_H