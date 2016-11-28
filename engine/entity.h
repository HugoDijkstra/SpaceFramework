#ifndef ENTITY_H
#define ENTITY_H

#include <SDL.h>
#include <cmath>
#include <engine/image.h>
#include <engine/input.h>
#include <engine/vector2.h>
#include <iostream>
#include <string>

class Entity {
public:
  ///@brief default constuctor for basic entity.
  Entity();
  ///@brief constuctor for basic entity with a position.
  Entity(Vector2 pos);
  ///@brief deconstructor
  virtual ~Entity();
  ///@brief The position of the entity in a \ref Vector2.
  Vector2 position;
  ///@brief The texture of the entity represented with \ref Image, if it is
  /// null, it wont be rendered
  Image *image;
  ///@brief The size of
  Vector2 size;
  double angle;
  void setTexture(SDL_Renderer *renderer, std::string name, std::string path);
  void setTexture(Image *image) { this->image = image; }
  void virtual update(float dt);
  int getId() { return id; }
  int id;
  void destroy();
  static int ids;

private:
};

#endif
