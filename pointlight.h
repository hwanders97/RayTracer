//
// Header file for PointLight class
// Stores the light's color and position, generates a ray from an object to itself and shades
// a point with the general lighting algorithm (found in light.cpp)
//


#pragma once

#include "light.h"

class PointLight: public Light {
public:
  PointLight();
  PointLight(Point lightpos, Color lightcol);
  PointLight(Point lightpos, Color lightcol, float c0, float c1, float c2);
  void generateLightRay(Local& local, Ray* lray);
  void shade(Local& local, Ray& lray, Ray& inray, Color* lcolor);
    
private:
  Point lightposition;
  Color lightcolor;
  // Attenuation
  float c0, c1, c2;
};


