//
// This class stores information about the local point: the position of the point, and normal
// and material of the object at that point
//


#include "local.h"

// Default constructor
Local::Local() : pos(Point()), normal(Vector()), material(new Material()) {};

// Input constructor
Local::Local(Point p, Vector norm, Material* mat) : pos(p), normal(norm), material(mat) {};
