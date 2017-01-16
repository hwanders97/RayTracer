//
// Header file for plane class
// Stores normal of plane, distance from the camera and calculates ray intersections
//


#pragma once

#include "shape.h"

class Plane: public Shape {
public:
  Vector normal;
  float distance;
  Plane();
  Plane(float x, float y, float z, float dist, Material* mat, bool checkshade, bool castshade);
  void intersect(Ray& ray, Local* local, bool shadows, int* retval);
};


