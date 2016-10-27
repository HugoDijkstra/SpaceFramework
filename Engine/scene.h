#ifndef SCENE_H
#define SCENE_H

#include <Engine/entity.h>
#include <vector>

class Scene {
public:
  Scene();
  virtual ~Scene();
  std::vector<Entity *> entities;
  void addEntity(Entity *entity);
  void removeEntity(Entity *entity);
};

#endif
