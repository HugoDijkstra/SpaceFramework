/**
 * Copyright 2016 hugodijkstra
 *
 * @file resourcemanager.h
 *
 * @brief The definition of the ResourceManager class.
 * Holds the images and makes them easily accessable.
 */

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SDL.h>
#include <string>
#include <vector>

#include <engine/image.h>

class ResourceManager {
public:
  virtual ~ResourceManager();
  std::string path = "";
  void addImage(Image *image);
  void removeImage(Image *image);
  static ResourceManager *getInstance();
  Image *getImage(std::string name);
  void setRenderer(SDL_Renderer *renderer) { this->renderer = renderer; }
  void loadImages(SDL_Renderer *renderer);

private:
  ResourceManager();
  SDL_Renderer *renderer;
  static ResourceManager *instance;
  std::vector<Image *> textures;
};

#endif
