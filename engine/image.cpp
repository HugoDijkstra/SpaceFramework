#include <engine/image.h>

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

Image::Image(SDL_Renderer *renderer, std::string name, std::string path,
             int spriteSizeX, int spriteOffset, int spriteAmount, float step) {
  animationSheet = true;
  LoadImage(renderer, path);
  this->name = name;
  this->spriteSizeX = spriteSizeX;
  this->spriteOffset = spriteOffset;
  this->spriteAmount = spriteAmount;
  setClips();
  id = ids++;
  this->step = step;
  currentSprite = 0;
}

Image::Image(SDL_Texture *texture) { image = texture; }
Image::~Image() {
  if (image != NULL)
    SDL_DestroyTexture(image);
}
void Image::setClips() {
  for (unsigned int i = 0; i < spriteAmount; i++) {
    SDL_Rect *rect = new SDL_Rect();
    rect->x = i * spriteSizeX + spriteOffset;
    rect->y = 0;
    rect->h = imageSize.y;
    rect->w = spriteSizeX;
    clips.push_back(rect);
  }
  curRect = clips[0];
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
