#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>
#include <engine/entity.h>
#include <engine/scene.h>
#include <iostream>

class Renderer {
public:
  Renderer();
  virtual ~Renderer();

  SDL_Renderer *getRenderer() { return renderer; }
  double getDeltaTime() { return deltatTime; };
  double getLastTime() { return lastTime; };
  void rendererScene(Scene *scene);
  void updateDeltaTime();

private:
  double deltatTime;
  double lastTime;
  SDL_Window *window;
  SDL_Renderer *renderer;
  void init();
};

#endif
