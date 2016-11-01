#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <Engine/entity.h>
#include <Engine/scene.h>
#include <lsm/entities/bullet.h>
class Spaceship : public Entity {
public:
  Spaceship();
  virtual ~Spaceship();
  void virtual update(float dt);
  void shoot();
  Scene *scene;

  float speed;

  Vector2 velocity;

private:
};

#endif
