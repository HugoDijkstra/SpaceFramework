#include <Engine/resourcemanager.h>
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
  this->addImage(new Image(renderer, "SpaceShip", "assets/SpaceShip.gif"));
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
Image *ResourceManager::getImage(std::string name) {
  std::vector<Image *>::iterator it = textures.begin();
  while (it != textures.end()) {
    if ((*it)->name.compare(name) == 0) {
      std::cout << "Image gotten" << std::endl;
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
