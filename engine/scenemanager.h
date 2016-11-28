#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <engine/scene.h>
#include <string>
#include <vector>

class Scenemanager {
public:
  virtual ~Scenemanager();

  void addScene(Scene *scene);
  ///@brief Get scene by name.

  Scene *getScene(int index) { return scenes[index]; }
  Scene *getScene(std::string name);
  static Scenemanager *getInstance();

private:
  Scenemanager();
  static Scenemanager *instance;
  std::vector<Scene *> scenes;
};

#endif
