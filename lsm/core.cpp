#include <cstdlib>
#include <engine/entity.h>
#include <engine/image.h>
#include <engine/input.h>
#include <engine/renderer.h>
#include <engine/resourcemanager.h>
#include <engine/scene.h>
#include <engine/scenemanager.h>
#include <iostream>
#include <lsm/entities/planet.h>
#include <lsm/entities/spaceship.h>
#include <string>
#include <time.h>

Renderer *renderer;
Scene *scene;
Image *image;
ResourceManager *resourceManager;
Spaceship *spaceShip;
Planet *planet;

bool quit = false;

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  renderer = new Renderer();
  Input::getInstance()->update();
  scene = new Scene();

  ResourceManager::getInstance()->loadImages(renderer->getRenderer());
  planet = Planet::generatePlanet(renderer->getRenderer(), Vector2(1, 1));
  spaceShip = new Spaceship();
  spaceShip->scene = scene;
  // if (planet != NULL)
  // scene->addEntity(planet);
  scene->addEntity(spaceShip);
  // Main game loop:
  int lastSize = 0;
  while (!Input::getInstance()->mustquit) {
    Input::getInstance()->update();
    renderer->updateDeltaTime();
    for (unsigned int i = 0; i < scene->entities.size(); i++) {
      scene->entities[i]->update(renderer->getDeltaTime());
    }
    if (scene->entities.size() > lastSize) {
      lastSize = scene->entities.size();
      std::cout << "Bigger" << std::endl;
    }

    renderer->rendererScene(scene);
    scene->hasEntity(planet);
    for (unsigned int i = 0; i < 282; i++) {
      if (Input::getInstance()->getKeyDown(i)) {
        std::cout << i << " : keyPressed" << std::endl;
      }
    }
  }

  std::cout << "Ended" << std::endl;
  delete renderer;
  delete scene;

  return 0;
}
