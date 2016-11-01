#ifndef BULLET_H
#define BULLET_H

#include <Engine/entity.h>
#include <cmath>

class Bullet : public Entity {
public:
  Bullet(double angle, float speed);
  virtual ~Bullet();
  Vector2 *velocity;
  float speed;

  void update(float dt);

private:
};

#endif
