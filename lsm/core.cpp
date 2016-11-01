#include <Engine/entity.h>
#include <Engine/image.h>
#include <Engine/input.h>
#include <Engine/renderer.h>
#include <Engine/resourcemanager.h>
#include <Engine/scene.h>
#include <cstdlib>
#include <iostream>
#include <lsm/entities/spaceship.h>
#include <string>
#include <time.h>

Renderer *renderer;
Scene *scene;
Image *image;
ResourceManager *resourceManager;
Spaceship *spaceShip;

bool quit = false;

int main(int argc, char const *argv[]) {
  srand(time(NULL));

  renderer = new Renderer();
  Input::getInstance()->update();
  scene = new Scene();
  ResourceManager::getInstance()->loadImages(renderer->renderer);
  spaceShip = new Spaceship();
  spaceShip->scene = scene;
  spaceShip->setTexture(ResourceManager::getInstance()->getImage("SpaceShip"));
  scene->addEntity(spaceShip);
  // Main game loop:
  while (!Input::getInstance()->mustquit) {
    Input::getInstance()->update();
    renderer->updateDeltaTime();
    for (unsigned int i = 0; i < scene->entities.size(); i++) {
      scene->entities[i]->update(renderer->deltatTime);
    }
    renderer->rendererScene(scene);
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
