//
// Class to create a ray from a certain position in a certain direction
// Has a value t which is how far along the ray a point is, has min and max values to restrain t
//


#include "ray.h"

// Default constructor
Ray::Ray() : pos(Point()), dir(Vector()), t(0), t_min(0), t_max(1000000) {};

// Input constructor
Ray::Ray(Point position, Vector direction) : pos(position), dir(direction), t_min(0), t_max(1000000) {};

// Input constructor with t
Ray::Ray(Point position, Vector direction, float tval) : pos(position), dir(direction), t(tval), t_min(0), t_max(1000000) {};

