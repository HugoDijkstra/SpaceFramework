#ifndef PARTICLE_H
#define PARTICLE_H

#include <Engine/entity.h>
#include <Engine/scene.h>

class Particle : public Entity {
public:
  Particle(Scene *scene, Vector2 pos, Vector2 velocity, Vector2 gravity);
  virtual ~Particle();

  Vector2 velocity;
  Vector2 gravity;

  Scene *scene;
  float timeAlife = 0;

  void update(Input *input, float dt);
};

#endif
