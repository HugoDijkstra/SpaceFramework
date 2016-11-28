/**
 * Copyright 2016 hugodijkstra
 *
 * @file resourcemanager.cpp
 *
 * @brief The implementation of the ResourceManager class.<br>This class is a
 * singleton
 */

#include <engine/resourcemanager.h>

//@brief A static instance of the ResourceManager.
ResourceManager *ResourceManager::instance = NULL;
ResourceManager::ResourceManager() {}

ResourceManager::~ResourceManager() { textures.clear(); }
ResourceManager *ResourceManager::getInstance() {
  if (ResourceManager::instance == NULL) {
    ResourceManager::instance = new ResourceManager();
  }
  return ResourceManager::instance;
}

void ResourceManager::loadImages(SDL_Renderer *renderer) {
  this->addImage(new Image(renderer, "SpaceShip", "assets/spaceship.png"));
  this->addImage(new Image(renderer, "Laser", "assets/laser.png"));
  this->addImage(
      new Image(renderer, "Planet00", "assets/planet00.png", 16, 0, 4, 1.4f));
}
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

//@brief Get image by image name.
Image *ResourceManager::getImage(std::string name) {
  std::vector<Image *>::iterator it = textures.begin();
  while (it != textures.end()) {
    if ((*it)->name.compare(name) == 0) {
      return (*it);
    } else {
      ++it;
    }
  }
  std::cout << "Image not found" << std::endl;
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
