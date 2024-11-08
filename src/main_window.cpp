#include "main_window.hpp"

/**
 * @brief main loop: run program
 */
void MainWindow::run() {
  // Create a render window
  sf::RenderWindow window(sf::VideoMode({width_, height_}), window_name_);

  // init
  init(&window);

  // TODO: MAKE LOGGER ADD TIME TO THE STRING ITSELF, NOT WHEN IT'S PRINTED
  //////////// test
  //
  //
  //
  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  int i = 0;
  sf::Clock deltaClock;
  while (window.isOpen())
  {
      if (i % 60 == 0) logger_.printInTerminal();
      sf::Event event;
      while (window.pollEvent(event))
      {
          ImGui::SFML::ProcessEvent(window, event);

      }

      ImGui::SFML::Update(window, deltaClock.restart());

      ImGui::ShowDemoWindow();

      ImGui::Begin("Hello, world!");
      ImGui::Button("Look at this pretty button");
      ImGui::End();

      window.clear();
      window.draw(shape);
      ImGui::SFML::Render(window);
      window.display();
  }
    //
    //
    //
    //

  // cleanup
  cleanup();
}

/**
 * @brief initialize all services
 */
void MainWindow::init(sf::RenderWindow* window) {
  // settings
  window->setFramerateLimit(60);

  // init services
  if (!ImGui::SFML::Init(*window)) {
    logger_.log(DEBUG_LOG, "Could not create window.");
  }
  logger_.log(DEBUG_LOG, "Successfully created window.");
}

/**
 * @brief clear memory
 */
void MainWindow::cleanup() {
  ImGui::SFML::Shutdown();
}