#include <Engine/image.h>

int Image::ids = 0;
Image::Image() {
  image = NULL;
  id = ids++;
}
Image::Image(SDL_Renderer *renderer, std::string name, std::string path) {
  LoadImage(renderer, path);
  this->name = name;
  id = ids++;
  std::cout << id << " < image is : name > " << name << std::endl;
}
Image::~Image() {
  if (image != NULL)
    SDL_DestroyTexture(image);
}
void Image::LoadImage(SDL_Renderer *renderer, std::string path) {
  image = IMG_LoadTexture(renderer, path.c_str());
  if (image == NULL) {
    std::cout << "Error in loading image: " << SDL_GetError() << std::endl;
    return;
  }
  int x, y;
  SDL_QueryTexture(image, NULL, NULL, &x, &y);
  imageSize.x = x;
  imageSize.y = y;
}
