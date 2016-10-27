#include <Engine/resourcemanager.h>

ResourceManager::ResourceManager(SDL_Renderer *renderer) {
  // path = SDL_GetBasePath();
  addImage(new Image(renderer, "gordon", "assets/gordon.jpg"));

  addImage(new Image(renderer, "zeertje", "assets/geertje.jpg"));
  addImage(new Image(renderer, "blimp", "assets/blimb.jpeg"));
}

ResourceManager::~ResourceManager() { textures.clear(); }

void ResourceManager::addImage(Image *image) {
  std::vector<Image *>::iterator it = textures.begin();
  while (it != textures.end()) {
    if ((*it)->getId() == image->getId()) {
      return;
    } else {
      ++it;
    }
  }
  textures.push_back(image);
}
Image *ResourceManager::getImage(std::string name) {
  std::vector<Image *>::iterator it = textures.begin();
  while (it != textures.end()) {
    if ((*it)->name.compare(name) == 0) {
      return (*it);
    } else {
      ++it;
    }
  }
  return NULL;
}

void ResourceManager::removeImage(Image *image) {
  std::vector<Image *>::iterator it = textures.begin();
  while (it != textures.end()) {
    if ((*it)->getId() == image->getId()) {
      it = textures.erase(it);
    } else {
      ++it;
    }
  }
}
