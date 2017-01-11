//
// Header file for the local class
// Store position, normal at point and material of object
//


#pragma once

#include "point.h"
#include "material.h"

//Class to keep track of local geometry at an intersection point
class Local {
public:
  Point pos;
  Vector normal;
  Material* material;
  Local();
  Local(Point p, Vector norm, Material* mat);
};

