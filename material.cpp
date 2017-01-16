//
// This class stores material information: the material color as well as diffuse and specular
// coefficients and shininess, reflection and refraction factors
//


#include "material.h"

// Default constructor
Material::Material() : matcolor(Color()), diffuse(0), specular(0), shininess(0), reflection(0), refraction(0) {};

// Input constructor
Material::Material(Color mat, float diff, float spec, float shine, float reflect, float refract) : matcolor(mat), diffuse(diff), specular(spec), shininess(shine), reflection(reflect), refraction(refract) {};

