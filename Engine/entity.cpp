#include <Engine/entity.h>
int Entity::ids = 0;
Entity::Entity() { id = ids++; }
Entity::Entity(Vector2 pos) {
  id = ids++;
  position = pos;
}
Entity::~Entity() { delete image; }
void Entity::setTexture(SDL_Renderer *renderer, std::string name,
                        std::string path) {
  image = new Image(renderer, name, path);
}
void Entity::update(float dt) {}
