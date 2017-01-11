//
// This class sets up the shading for a point light, taking into account the light's color and
// position, and the material of what it is shading
//


#include "pointlight.h"

// Default constructor
PointLight::PointLight() : lightposition(Point()), lightcolor(Color()), c0(1), c1(0), c2(0) {};

// Input constructor
PointLight::PointLight(Point lightpos, Color lightcol) : lightposition(lightpos), lightcolor(lightcol), c0(1), c1(0), c2(0) {};

// Attenuation constructor
PointLight::PointLight(Point lightpos, Color lightcol, float c0, float c1, float c2) : lightposition(lightpos), lightcolor(lightcol), c0(c0), c1(c1), c2(c2) {};

// Create a ray from the local position to the light position
void PointLight::generateLightRay(Local& local, Ray* lray) {
  lray->dir = lightposition - local.pos;
  lray->dir = Vector::normalize(lray->dir);
  // Want the ray to start a little off from the object itself
  lray->pos = local.pos + lray->dir * 0.0001;
  // The point light is a certain distance away
  lray->t_max = lray->dir.length();
}

// Shade the object using its material properties and lambert and phong algorithms
void PointLight::shade(Local& local, Ray& lray, Ray& inray, Color* lcolor) {
  Material* mat = local.material;
  
  // Lambert - diffuse shading
  float dot = Vector::dot(lray.dir, local.normal);
  if (dot > 0) {
    *lcolor += lightcolor * mat->matcolor * dot * mat->diffuse;
  }
  
  // Phong - specular shading with reflection
  Vector spec = lray.dir - local.normal * (2 * Vector::dot(lray.dir, local.normal));
  dot = Vector::dot(spec, inray.dir);
  if (dot > 0)
    *lcolor += lightcolor * mat->specular * pow(dot, mat->shininess);
  
}



