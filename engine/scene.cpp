/**
 * Copyright 2016 hugodijkstra
 *
 * @file scene.cpp
 *
 * @brief The implementation of the scene class.
 */

#include <engine/scene.h>

int Scene::ids = 0;
Scene::Scene() { id = ids++; }
Scene::Scene(std::string name) {
  this->name = name;
  id = ids++;
}

Scene::~Scene() { entities.clear(); }
void Scene::addEntity(Entity *entity) {
  std::vector<Entity *>::iterator it = entities.begin();
  while (it != entities.end()) {
    if ((*it)->getId() == entity->getId()) {
      return;
    } else {
      ++it;
    }
  }
  entities.push_back(entity);
}

void Scene::removeEntity(Entity *entity) {
  std::vector<Entity *>::iterator it = entities.begin();
  while (it != entities.end()) {
    if ((*it)->getId() == entity->getId()) {
      Entity *tmp = (*it);
      it = entities.erase(it);
      delete tmp;
    } else {
      ++it;
    }
  }
}
bool Scene::hasEntity(Entity *entity) {
  std::vector<Entity *>::iterator it = entities.begin();
  while (it != entities.end()) {
    if ((*it)->getId() == entity->getId()) {
      return true;
    } else {
      ++it;
    }
  }
  return false;
}
