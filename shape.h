//
// Header file for abstract shape class
// All shapes have a material, can be shadowed and intersected
//


#pragma once

#include "ray.h"
#include "local.h"
#include "color.h"

class Shape {
public:
  Material* material;
  bool shadow;
  virtual bool intersect(Ray& ray, Local* local, bool shadows) = 0;
};


