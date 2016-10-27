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
void Entity::update(Input *input, float dt) {
  if (input->getKey(100)) {
    angle += 30 * dt;
  } else if (input->getKey(97)) {
    angle -= 30 * dt;
  }
  if (input->getKey(119)) {
    position += Vector2(cos((angle - 90) * 0.0174532925f) * dt,
                        sin((angle - 90) * 0.0174532925f) * dt) *
                50;
  }
  if (input->getKeyDown(32)) {
    std::cout << position.x << "," << position.y << " < Position : Angle > "
              << angle << std::endl;
  }
}
