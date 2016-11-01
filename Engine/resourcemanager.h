#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SDL.h>
#include <string>
#include <vector>

#include <Engine/image.h>

class ResourceManager {
public:
  virtual ~ResourceManager();
  std::string path = "";
  void addImage(Image *image);
  void removeImage(Image *image);
  static ResourceManager *getInstance();
  Image *getImage(std::string name);
  void setRenderer(SDL_Renderer *renderer);
  void loadImages(SDL_Renderer *renderer);

private:
  ResourceManager();
  static ResourceManager *instance;
  std::vector<Image *> textures;
};

#endif
