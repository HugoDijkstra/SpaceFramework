#include "planet.h"

Planet::Planet() { id = ids++; }

Planet::~Planet() {}
Planet *Planet::generatePlanet(SDL_Renderer *renderer, Vector2 size) {
  Planet *planet = new Planet();
  planet->image = ResourceManager::getInstance()->getImage("Planet00");
  planet->size = size;
  planet->position = Vector2(400, 400);
  return planet;
}

void Planet::update(float dt) {
  if (image->animationSheet) {
    image->curRect = image->clips[currentSprite];
    timer += dt;
    if (timer >= 1) {
      timer = 0;
      currentSprite++;
      if (currentSprite >= image->spriteAmount) {
        currentSprite = 0;
      }
    }

    /*std::cout << "Planet id: " << this->getId() << ", position: (" <<
       position.x
              << "," << position.y << ")" << ','
              << "Image exists: " << ((bool)image != NULL) << std::endl;*/
  }
}
