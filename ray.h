//
// Header file for ray class
// Stores ray position, direction and t value, which is a distance along the ray, also has min and max
// for t
//


#pragma once

#include "point.h"

// Ray shoots from eye position into a given direction of a pixel
// Ray = pos + dir * t
class Ray {
public:
  Point pos;
  Vector dir;
  float t_max, t_min, t;
  Ray();
  Ray(Point position, Vector direction);
  Ray(Point position, Vector direction, float tval);
};


