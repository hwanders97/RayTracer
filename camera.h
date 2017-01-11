//
// This is the header file for the camera class
// Defines pi and field of view in the y direction
//


#pragma once

#define PI 3.141592653
#define FOVY 90

#include "ray.h"
#include "sample.h"

//This class generates a ray pointing from the eye to a sample
class Camera {
public:
  Camera();
  Camera(Point from, Point at, Vector upvec);
  Ray generateRay();
  
private:
  Point lookfrom, lookat;
  Vector up;
};


