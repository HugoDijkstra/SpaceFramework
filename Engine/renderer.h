#ifndef RENDERER_H
#define RENDERER_H

#include <Engine/scene.h>
#include <SDL.h>
#include <iostream>

class Renderer {
public:
  Renderer();
  virtual ~Renderer();

  SDL_Renderer *renderer;
  SDL_Window *window;

  double deltatTime = 0;
  double lastTime = 0;
  void rendererScene(Scene *scene);
  void updateDeltaTime();

private:
  void init();
};

#endif
