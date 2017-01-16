//
// Header file for the material class
// Stores colors and values to be calculated for lambert and phong shading with lighting
//


#pragma once

#include "color.h"

class Material {
public:
  Color matcolor;
  float diffuse, specular, shininess, reflection, refraction;
  Material();
  Material(Color mat, float diff, float spec, float shine, float reflect, float refract);
};

