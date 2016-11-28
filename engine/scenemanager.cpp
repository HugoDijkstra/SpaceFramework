/**
 * Copyright 2016 hugodijkstra
 *
 * @file scenemanager.cpp
 *
 * @brief The definition of the Scenemanager class.<br>The Scenemanager holds
 all the scenes.<br>Scenemanager is a singleton.
 */

#include "scenemanager.h"

Scenemanager::Scenemanager() {}

Scenemanager::~Scenemanager() {}

Scenemanager *Scenemanager::getInstance() {
  if (instance == NULL) {
    instance = new Scenemanager();
  }
  return instance;
}
Scene *Scenemanager::getScene(std::string name) {}

void Scenemanager::addScene(Scene *scene) {
  std::vector<Scene *>::iterator it = scenes.begin();
  while (it != scenes.end()) {
    if ((*it)->getId() == scene->getId()) {
      return;
    } else {
      ++it;
    }
  }
  scenes.push_back(scene);
}
