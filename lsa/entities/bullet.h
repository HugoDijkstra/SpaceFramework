#ifndef BULLET_H
#define BULLET_H

#include <cmath>
#include <engine/entity.h>
#include <engine/resourcemanager.h>

class Bullet : public Entity {
public:
  Bullet(double angle, float speed);
  Bullet(Entity *ship, float speed);
  virtual ~Bullet();
  Vector2 velocity;
  float speed;

  void update(float dt);

private:
};

#endif
