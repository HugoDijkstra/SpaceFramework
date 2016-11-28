#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <engine/entity.h>
#include <engine/scene.h>
#include <lsa/entities/bullet.h>
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
