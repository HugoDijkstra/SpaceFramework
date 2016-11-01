#ifndef ENTITY_H
#define ENTITY_H

#include <Engine/image.h>
#include <Engine/input.h>
#include <Engine/vector2.h>
#include <SDL.h>
#include <cmath>
#include <iostream>
#include <string>

class Entity {
public:
  Entity();
  Entity(Vector2 pos);
  virtual ~Entity();
  Vector2 position;
  Image *image;
  Vector2 imageSize;
  double angle;
  int id;
  void setTexture(SDL_Renderer *renderer, std::string name, std::string path);
  void setTexture(Image *image) { this->image = image; }
  void virtual update(float dt);
  int getId() { return id; }

private:
  static int ids;
};

#endif
