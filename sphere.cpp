//
// This class sets up a sphere object with a center position and radius
// Sphere is a shape with a material, can be shadowed and intersected
//


#include "sphere.h"
// Debug
#include <iostream>

using namespace std;

// Default constructor
Sphere::Sphere() : center(Point()), radius(1) {
  material = new Material();
  checkshadow = false;
  castshadow = false;
}

// Input constructor
Sphere::Sphere(float x, float y, float z, float rad, Material* mat, bool checkshade, bool castshade) : center(Point(x, y, z)), radius(rad) {
  // Inherited members must be manually initialized
  this->material = mat;
  this->checkshadow = checkshade;
  this->castshadow = castshade;
}

// Takes in a ray and gives back the point of intersection and normal if there is one
void Sphere::intersect(Ray& ray, Local* local, bool shadows, int* retval) {
  // Necessary variables
  float discriminant, a, b, c, t1, t2;
  // Ray from camera to center of sphere
  Vector temp = ray.pos - center;
  
  // Need to find discriminant
  a = Vector::dot(ray.dir, ray.dir);
  b = 2 * Vector::dot(ray.dir, temp);
  c = Vector::dot(temp, temp) - (radius * radius);
  discriminant = (b * b) - (4 * a *c);
  
  *retval = 0;
  
  // If discriminant is negative then there are no real roots and no intersection
  if (discriminant >= 0) {
    // No need to store intersection information if point is in shadow
    if (shadows)
      *retval = 1;
    else  {
      t1 = (-b + sqrt(discriminant)) / (2 * a);
      t2 = (-b - sqrt(discriminant)) / (2 * a);

      // t1 is always larger than t2
      if (t1 > 0) {
        // 2 real positive roots, pick smaller if in range t_min : t_max
        // Outside sphere
        if (t2 > 0 && t2 < ray.t_max) {
          ray.t = t2;
          *retval = 1;
        }
        // One positive, one negative, choose positive
        // Inside sphere
        else if (t1 < ray.t_max){
          ray.t = t1;
          *retval = -1;
        }
        
        // If a t value is stored
        if (*retval) {
          // Store local information
          local->pos = ray.pos + (ray.dir * ray.t);
          temp = local->pos - center;
          local->normal = Vector::normalize(temp);
          local->material = material;
        }
      }
    }
  }
}



