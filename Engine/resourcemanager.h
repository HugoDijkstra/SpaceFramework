#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SDL.h>
#include <string>
#include <vector>

#include <Engine/image.h>

class ResourceManager {
public:
  ResourceManager(SDL_Renderer *renderer);
  virtual ~ResourceManager();
  std::string path = "";
  void addImage(Image *image);
  void removeImage(Image *image);

  Image *getImage(std::string name);

private:
  std::vector<Image *> textures;
};

#endif
