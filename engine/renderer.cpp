#include <engine/renderer.h>

Renderer::Renderer() {
  lastTime = 0;
  deltatTime = 0;
  init();
}

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

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
  if (renderer == NULL) {
    std::cout << "Error in creating renderer: " << SDL_GetError() << std::endl;
    return;
  }
  SDL_RenderPresent(renderer);
}
void Renderer::rendererScene(Scene *scene) {

  // iterate through all the entities
  for (unsigned int i = 0; i < scene->entities.size(); i++) {
    // check if it has an image

    if (scene->entities[i]->image != NULL &&
        scene->entities[i]->image->image != NULL) {
      if (!scene->entities[i]->image->animationSheet) {

        SDL_RendererFlip flip = SDL_FLIP_NONE;
        Vector2 imageSize = scene->entities[i]->image->getImageSize() *
                            scene->entities[i]->size;
        SDL_Rect *rect =
            Vector2::toRect(scene->entities[i]->position -
                                Vector2(imageSize.x / 2, imageSize.y / 2),
                            imageSize);
        SDL_RenderCopyEx(renderer, scene->entities[i]->image->image, NULL, rect,
                         scene->entities[i]->angle, NULL, flip);
      } else {
        SDL_RendererFlip flip = SDL_FLIP_NONE;
        Vector2 imageSize = scene->entities[i]->image->getImageSize() *
                            scene->entities[i]->size;
        imageSize.x /= scene->entities[i]->image->spriteAmount;
        SDL_Rect *rect =
            Vector2::toRect(scene->entities[i]->position -
                                Vector2(imageSize.x / 2, imageSize.y / 2),
                            imageSize);
        SDL_RenderCopyEx(renderer, scene->entities[i]->image->image,
                         scene->entities[i]->image->curRect, rect,
                         scene->entities[i]->angle, NULL, flip);
      }
    }
  }
  SDL_RenderPresent(renderer);

  // set background color
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  // empty screen to background color
  SDL_RenderClear(renderer);
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
