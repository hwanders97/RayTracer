//
// This contains the main raytracer algorithm and also helps find intersections and deals with
// shadows and reflections
//


#include "raytracer.h"

// Constructor to initialize the array of shapes and lights
RayTracer::RayTracer(vector<Shape*> shapesarr, vector<Light*> lightsarr) : shapes(shapesarr), lights(lightsarr) {};

// Algorithm to look at all shapes and finds the closest object intersection, if any
void RayTracer::findintersection(Ray& ray, Local* loc, int* num, int* finalhit) {
  // Minimum starts out large
  double min_t = 10000000;
  Local local, min_local;
  // If it stays -1 then there's no intersection
  int min_shapenum = -1;
  // Keep track of whether anything is hit and if inside or outside
  int hit = 0, min_hit = 0;

  // Loop through all shapes in the scene
  for (int i = 0; i < shapes.size(); i++) {
    shapes[i]->intersect(ray, &local, false, &hit);
    // If there is an intersection keep track of the closest one, with the smallest t value
    if (hit && ray.t < min_t) {
      min_shapenum = i;
      min_t = ray.t;
      min_local = local;
      min_hit = hit;
    }
  }
  // Store the intersection information, which contains the local geometry (pos, normal and mat),
  // the shape that was hit with the ray, and whether it was hit inside or outside (1 or -1)
  *loc = min_local;
  *num = min_shapenum;
  *finalhit = min_hit;
}

// Check if the light ray intersects with an other objects and is in shadow
bool RayTracer::shadowintersection(Ray& lray, int shapenum) {
  Local local;
  int hit;
  for (int i = 0; i < shapes.size(); i++) {
    //Doesn't shadow itself
    if (i != shapenum && shapes[i]->castshadow) {
      shapes[i]->intersect(lray, &local, true, &hit);
      // True if there is something between the object and the light
      if (hit)
        return true;
    }
  }
  // No shadow
  return false;
}

// Create the reflection ray using the reflection algorithm
void RayTracer::generateReflectRay(Local& local, Ray& ray, Ray* reflectRay) {
  reflectRay->dir = ray.dir - local.normal * (2 * Vector::dot(local.normal, ray.dir));
  // Want the ray to start a little off from the object itself
  reflectRay->pos = local.pos + reflectRay->dir * 0.0001;
}

// Create the refraction ray using the refraction algorithm
void RayTracer::generateRefractRay(float origRefract, Local& local, Ray& ray, Ray* refractRay, int hit) {
  Vector normal = local.normal * hit; // Reverse normal if inside sphere
  float nDotRay = -Vector::dot(normal, ray.dir);
  float indexRatio = origRefract / local.material->refraction;
  float root = sqrt(1 - indexRatio * indexRatio * (1 - nDotRay * nDotRay));
  refractRay->dir = (ray.dir * indexRatio) + (normal * (indexRatio * nDotRay - root));
  refractRay->dir = Vector::normalize(refractRay->dir);
  refractRay->pos = local.pos + refractRay->dir * 0.0001;
}

// Main trace algorithm
bool RayTracer::trace(Ray& ray, int depth, Color* color, float index) {
  Local local;
  int shapenum, hit = 0;

  //Recursive check
  if (depth > MAXDEPTH)
    return false;
  
  // Find an intersection
  findintersection(ray, &local, &shapenum, &hit);
  //cout << hit << endl;
  // No intersection, return, will stay black
  if (hit == 0)
    return false;

  //There is an intersection, calculate lighting
  for (int i = 0; i < lights.size(); i++) {
    Ray lray;
    // Create light ray from the object to the light source
    lights[i]->generateLightRay(local, &lray);
    
    // See if shadows are allowed on the surface, if not just add the color
    if (!shapes[shapenum]->checkshadow)
      lights[i]->shade(local, lray, ray, color);
    // Check for shadow, if nothing is blocking the ray from the object to the light then add color
    else if (!shadowintersection(lray, shapenum))
      lights[i]->shade(local, lray, ray, color);
  }

  // Mirror reflection
  if (local.material->reflection > 0) {
    Color reflectColor;
    // Get reflected ray
    Ray reflectRay;
    generateReflectRay(local, ray, &reflectRay);
    
    // Recursive call to reflected ray
    trace(reflectRay, depth + 1, &reflectColor, index);
    *color += reflectColor * local.material->reflection;
  }
  
  // Water refraction
  if (local.material->refraction > 1) { // 1 is the normal index of refraction
    Color refractColor;
    // Get refracted ray
    Ray refractRay;
    generateRefractRay(index, local, ray, &refractRay, hit);

    // Recursive call to refracted ray
    trace(refractRay, depth + 1, &refractColor, local.material->refraction);
    *color += refractColor;
  }
  
  return true;
}







