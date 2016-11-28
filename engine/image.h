#ifndef IMAGE_H
#define IMAGE_H

#include <SDL.h>
#include <string>
#include <vector>

#include <SDL2/SDL_image.h>
#include <engine/vector2.h>

class Image {
public:
  Image();
  Image(SDL_Texture *texture);
  Image(SDL_Renderer *renderer, std::string name, std::string path);
  Image(SDL_Renderer *renderer, std::string name, std::string path,
        int spriteSizeX, int spriteOffset, int spriteAmount, float step);
  virtual ~Image();
  std::string name;
  int id = 0;
  SDL_Texture *image;
  void LoadImage(SDL_Renderer *renderer, std::string path);
  std::vector<SDL_Rect *> clips;
  SDL_Rect *curRect;
  bool animationSheet;
  float step;
  int spriteSizeX;
  int spriteOffset;
  int currentSprite;
  int spriteAmount;
  void setClips();

  int getId() { return id; }

  Vector2 getImageSize() { return imageSize; };

private:
  Vector2 imageSize;
  Vector2 position;
  static int ids;
};

#endif
