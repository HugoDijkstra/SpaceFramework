#ifndef IMAGE_H
#define IMAGE_H

#include <SDL.h>
#include <string>

#include <Engine/vector2.h>
#include <SDL2/SDL_image.h>

class Image {
public:
  Image();
  Image(SDL_Renderer *renderer, std::string name, std::string path);
  virtual ~Image();
  std::string name;
  int id = 0;
  SDL_Texture *image;
  void LoadImage(SDL_Renderer *renderer, std::string path);
  int getId() { return id; }

  Vector2 getImageSize() { return imageSize; };

private:
  Vector2 imageSize;
  Vector2 position;
  static int ids;
};

#endif
