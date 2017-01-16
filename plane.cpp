//
// This class sets up a plane object with a given normal and distance from the camera
// A plane is a shape, so it also has a material and can recieve shadows
//


#include "plane.h"

// Default constructor
Plane::Plane() : normal(Vector()), distance(0) {
  // Must manually set parent members
  material = new Material();
  checkshadow = false;
  castshadow = false;
}

// Input constructor
Plane::Plane(float x, float y, float z, float dist, Material* mat, bool checkshade, bool castshade) : normal(Vector(x, y, z)), distance(dist) {
  this->material = mat;
  this->checkshadow = checkshade;
  this->castshadow = castshade;
}

// Check for ray intersection and return local information
void Plane::intersect(Ray& ray, Local* local, bool shadows, int *retval) {
  *retval = 0;
  
  // Check if ray is not parallel to the plane
  float nDotDir = Vector::dot(normal, ray.dir);
  if (nDotDir < 0) {
    // There is an intersection
    
    // There is something blocking the light, no need to store information
    if (shadows)
      *retval = 1;
    
    if (!*retval) {
      // Store useful information
      float t = -(Point::dot(ray.pos, normal) + distance) / nDotDir;
      if (t > 0)
        ray.t = t;
      local->pos = ray.pos + (ray.dir * ray.t);
      local->normal = normal;
      local->material = material;
      *retval = 1;
    }
  }
}



