#include "spaceship.h"

Spaceship::Spaceship() {
  imageSize = Vector2(0.2f, 0.2f);
  speed = 0.5f;
  velocity = Vector2(0, 0);
  setTexture(ResourceManager::getInstance()->getImage("SpaceShip"));
}

Spaceship::~Spaceship() {}

void Spaceship::update(float dt) {
  Input *input = Input::getInstance();

  if (input->getKey(100)) {
    angle += 120 * dt;
  } else if (input->getKey(97)) {
    angle -= 120 * dt;
  }

  if (input->getKeyDown(32)) {
    shoot();
  }

  if (input->getKey(119)) {
    Vector2 forward = Vector2(cos((angle - 90) * 0.0174532925f),
                              sin((angle - 90) * 0.0174532925f));
    Vector2 acc = forward * speed;
    velocity += acc * dt;
  }
  position -= velocity;
  if (position.x < 0) {
    position.x = 1260;
  }
  if (position.x > 1260)
    position.x = 0;
  if (position.y < 0)
    position.y = 720;
  if (position.y > 720)
    position.y = 0;
}

void Spaceship::shoot() { scene->addEntity(new Bullet(this, 200)); }
