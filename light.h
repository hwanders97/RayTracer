//
// This is the header class for a general light
// A light has a position and a color, can send a ray from an object to itself, and calculate color
// shading
//


#pragma once

#include "local.h"
#include "ray.h"
#include "color.h"

class Light {
public:
  Light();
  Light(Point lightpos, Color lightcol);
  virtual void generateLightRay(Local& local, Ray* lray) = 0;
  virtual void shade(Local& local, Ray& lray, Ray& inray, Color* lcolor) = 0;
  
private:
  Point lightposition;
  Color lightcolor;
};


