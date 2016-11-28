/**
 * Copyright 2016 hugodijkstra
 *
 * @file scene.h
 *
 * @brief The definition of the scene class.<br>The scene class holds all the
 entities.
 */

#ifndef SCENE_H
#define SCENE_H

#include <engine/entity.h>
#include <string>
#include <vector>

class Scene {
public:
  Scene();
  Scene(std::string name);
  virtual ~Scene();
  std::vector<Entity *> entities;
  void addEntity(Entity *entity);
  void removeEntity(Entity *entity);
  int getId() { return id; }
  std::vector<Scene *> scenes;
  bool hasEntity(Entity *entity);

private:
  std::string name;
  static int ids;
  int id;
};

#endif
