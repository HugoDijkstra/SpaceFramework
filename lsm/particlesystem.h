#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include <engine/entity.h>
#include <engine/scene.h>
#include <engine/vector2.h>
#include <lsm/particle.h>

class ParticleSystem : public Entity {
public:
  ParticleSystem(Scene *scene, Particle *particle, Vector2 pos,
                 Vector2 startingVelocity, float randomAmplifier,
                 Vector2 gravity, float spawnRate);
  virtual ~ParticleSystem();
  long timeSinceLastSpawn = 0;
  Vector2 position;
  Vector2 startingVelocity;
  Vector2 gravity;

  Scene *scene;
  float randomAmplifier = 0;
  int particleSpawnRate = 0;
  Particle *particle;

  void spawnParticle();
  void update(Input *input, float dt);
};

#endif
