#include "bullet.h"

Bullet::Bullet(double angle, float speed) {
  this->angle = angle;
  this->speed = speed;
  setTexture(ResourceManager::getInstance()->getImage("Laser"));
  size = Vector2(0.05f, 0.05f);
}

Bullet::Bullet(Entity *ship, float speed) {
  this->angle = ship->angle;
  this->speed = speed;
  this->position = ship->position;
  setTexture(ResourceManager::getInstance()->getImage("Laser"));
  size = Vector2(0.05f, 0.05f);
}

Bullet::~Bullet() {}

void Bullet::update(float dt) {
  Vector2 forward = Vector2(cos((angle + 90) * 0.0174532925f),
                            sin((angle + 90) * 0.0174532925f));
  Vector2 acc = forward * speed;
  position += acc * dt;
}
