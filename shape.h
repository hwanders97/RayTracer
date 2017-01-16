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
  // If true, when the closest ray intersection is this shape, it will check for shadows on this shape
  // If false, this shape will be engulfed by light no matter what
  bool checkshadow;
  // If true, when other shapes are checked for shadows, this shape could block the light and induce
  // a shadow on another shape
  // If false, this shape will be skipped and not block the light
  bool castshadow;
  virtual void intersect(Ray& ray, Local* local, bool shadows, int* retval) = 0;
};


