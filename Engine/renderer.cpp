#include <Engine/renderer.h>

Renderer::Renderer() { init(); }

void Renderer::init() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cout << "Error in initiating SDL: " << SDL_GetError() << std::endl;
    return;
  }
  window = SDL_CreateWindow("lsp", 0, 0, 1260, 720, 0);
  if (window == NULL) {
    std::cout << "Error in creating window: " << SDL_GetError() << std::endl;
    return;
  }

  renderer = SDL_CreateRenderer(window, -1, 0);
  if (renderer == NULL) {
    std::cout << "Error in creating renderer: " << SDL_GetError() << std::endl;
    return;
  }
  SDL_RenderPresent(renderer);
}
void Renderer::rendererScene(Scene *scene) {
  SDL_RenderClear(renderer);

  for (unsigned int i = 0; i < scene->entities.size(); i++) {
    if (scene->entities[i]->image != NULL &&
        scene->entities[i]->image->image != NULL) {
      SDL_RendererFlip flip = SDL_FLIP_NONE;
      Vector2 ImageSize = scene->entities[i]->image->getImageSize();
      ImageSize.x *= scene->entities[i]->imageSize.x;
      ImageSize.y *= scene->entities[i]->imageSize.y;
      SDL_Rect *rect = Vector2::toRect(scene->entities[i]->position, ImageSize);
      SDL_RenderCopyEx(renderer, scene->entities[i]->image->image, NULL, rect,
                       scene->entities[i]->angle, NULL, flip);
    }
  }
  SDL_RenderPresent(renderer);
}

Renderer::~Renderer() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void Renderer::updateDeltaTime() {
  double now = SDL_GetTicks();
  deltatTime = (now - lastTime) / 1000;
  lastTime = now;
}
