#include <Engine/entity.h>
#include <Engine/image.h>
#include <Engine/input.h>
#include <Engine/renderer.h>
#include <Engine/resourcemanager.h>
#include <Engine/scene.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <time.h>

Renderer *renderer;
Scene *scene;
Image *image;
ResourceManager *resourceManager;
Input *input;

Entity *geertje;
bool quit = false;

int main(int argc, char const *argv[]) {
  srand(time(NULL));

  renderer = new Renderer();

  input = new Input();
  scene = new Scene();
  resourceManager = new ResourceManager(renderer->renderer);
  geertje = new Entity(Vector2(100, 10));
  geertje->setTexture(resourceManager->getImage("zeertje"));
  scene->addEntity(geertje);

  while (!input->mustquit) {
    input->update();
    renderer->updateDeltaTime();
    geertje->update(input, renderer->deltatTime);
    for (unsigned int i = 0; i < scene->entities.size(); i++) {
      scene->entities[i]->update(input, renderer->deltatTime);
    }
    renderer->rendererScene(scene);
    for (unsigned int i = 0; i < 282; i++) {
      if (input->getKeyDown(i)) {
        std::cout << i << " : keyPressed" << std::endl;
      }
    }
  }

  std::cout << "Ended" << std::endl;
  delete renderer;
  delete scene;
  delete input;

  return 0;
}
