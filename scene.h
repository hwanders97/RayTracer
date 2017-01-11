//
// Header file for scene class
// Contains a raytracer and camera and renders the image using the generic raytracer algorithm
//


#pragma once

#include "film.h"
#include "raytracer.h"

class Scene {
public:
  Scene(char* name);
  void render();
  
private:
  RayTracer* raytracer;
  Camera* camera;
  char* filename;
};

