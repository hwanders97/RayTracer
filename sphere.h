//
// Header file for sphere class, with members center and radius and inherited members material and
// shadow
// Can calculate ray-sphere intersection
//


#pragma once

#include "shape.h"

class Sphere: public Shape {
public:
  Point center;
  float radius;
  Sphere();
  Sphere(float x, float y, float z, float rad, Material* mat, bool shade);
  bool intersect(Ray& ray, Local* local, bool shadows);
};


