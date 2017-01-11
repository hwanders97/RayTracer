//
// This is the general light class that contains a method to compute the lighting using material
// properties and lambertian and phong lighting algorithms
//


#include "light.h"

// Default constructor
Light::Light() : lightposition(Point()), lightcolor(Color()) {};


// Input constructor
Light::Light(Point lightpos, Color lightcol) : lightposition(lightpos), lightcolor(lightcol) {} ;


// Calculates the lighting using lambert and phong algorithms
Color Light::ComputeLight(Vector direction, Color lightcolor, Vector normal, Vector intersectdir, Vector halfvec, Color diffuse, Color specular, float shininess, float reflection, float c0, float c1, float c2, float r) {
  // Lambert lighting
  float nDotL = Vector::dot(normal, direction);
  // Attenuation calculation
  float attenuation = 1 / (c0 + (c1 * r) + (c2 * r * r));
  // Must be positive or 0
  float mul = nDotL > 0.0 ? nDotL : 0.0;
  Color lambert = diffuse * mul;
  //Color lambert;
  // Phong lighting
  float nDotH = Vector::dot(normal, halfvec);
  float reflect = Vector::dot(direction, normal) * 2;
  Vector phongdir = direction - (normal * reflect);
  phongdir = Vector::normalize(phongdir);
  float phongterm = Vector::dot(phongdir, intersectdir) * reflection;
  //nDotH = nDotH > 0 ? nDotH : 0;
  mul = phongterm > 0 ? phongterm : nDotH;
  // Must be positive or 0
  mul = nDotH > 0.0 ? nDotH : 0.0;
  Color phong = specular * pow(mul, shininess);
  
  // Final color adds the lambert and phong lighting and takes into account the light's color
  Color temp = (lambert + phong);
  Color finalcolor = temp * lightcolor * attenuation;
  return finalcolor;
}



