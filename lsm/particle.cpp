#include <lsm/particle.h>

Particle::Particle(Scene *scene, Vector2 pos, Vector2 velocity,
                   Vector2 gravity) {
  this->position = pos;
  this->velocity = velocity;
  this->gravity = gravity;
  this->scene = scene;
}
Particle::~Particle() {}

void Particle::update(Input *input, float dt) {
  position += velocity * dt;
  velocity += gravity * dt;
  if (this->timeAlife >= 5) {
    scene->removeEntity(this);
    delete this;
  }
}
