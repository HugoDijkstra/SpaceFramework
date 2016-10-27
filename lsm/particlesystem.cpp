#include <lsm/particlesystem.h>

ParticleSystem::ParticleSystem(Scene *scene, Particle *particle, Vector2 pos,
                               Vector2 startingVelocity, float randomAmplifier,
                               Vector2 gravity, float spawnRate) {
  this->particle = particle;
  this->scene = scene;
  this->position = pos;
  this->particleSpawnRate = spawnRate;
  this->gravity = gravity;
  this->startingVelocity = startingVelocity;
  this->randomAmplifier = randomAmplifier;
}
ParticleSystem::~ParticleSystem() {}
void ParticleSystem::update(Input *input, float dt) {
  timeSinceLastSpawn += dt;
  if (timeSinceLastSpawn >= 1 / particleSpawnRate) {
  }
}
void ParticleSystem::spawnParticle() {
  Vector2 vel;
  vel.x = -startingVelocity.x;
  vel.y = -startingVelocity.y;

  vel += startingVelocity * (rand() * 2) * randomAmplifier;
  Particle *particle = new Particle(scene, position, vel, gravity);
  scene->addEntity(particle);
}
