//
// Header for point class, with members x, y, z
// Only has position, no direction
//


#pragma once

#include "vector.h"

//Point class with operator overload functionality
class Point {
public:
  float x, y, z;
  Point();
  Point(float xp, float yp, float zp);
  Point operator - ();
  Point operator + (const Vector& other);
  Vector operator - (const Point& other);
  static float dot(const Point& p, const Vector& v);
};


