//
// This is the general light class that contains a method to compute the lighting using material
// properties and lambertian and phong lighting algorithms
//


#include "light.h"

// Default constructor
Light::Light() : lightposition(Point()), lightcolor(Color()) {};


// Input constructor
Light::Light(Point lightpos, Color lightcol) : lightposition(lightpos), lightcolor(lightcol) {} ;

