#include "bullet.h"

Bullet::Bullet(double angle, float speed) {
  this->angle = angle;
  this->speed = speed;
}

Bullet::~Bullet() {}

void Bullet::update(float dt) {
  velocity = new Vector2(sin(angle) * speed * dt, cos(angle) * speed * dt);
}
