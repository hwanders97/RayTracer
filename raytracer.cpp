//
// This contains the main raytracer algorithm and also helps find intersections and deals with
// shadows and reflections
//


#include "raytracer.h"

// Constructor to initialize the array of shapes and lights
RayTracer::RayTracer(vector<Shape*> shapesarr, vector<Light*> lightsarr) : shapes(shapesarr), lights(lightsarr) {};

// Algorithm to look at all shapes and finds the closest object intersection, if any
void RayTracer::findintersection(Ray& ray, Local* loc, int* num) {
  // Minimum starts out large
  double min_t = 10000000;
  Local local, min_local;
  // If it stays -1 then there's no intersection
  int min_shapenum = -1;

  // Loop through all shapes in the scene
  for (int i = 0; i < shapes.size(); i++) {
    // If there is an intersection keep track of the closest one, with the smallest t value
    if (shapes[i]->intersect(ray, &local, false) && ray.t < min_t) {
      min_shapenum = i;
      min_t = ray.t;
      min_local = local;
    }
  }
  // Store the intersection information, which contains the local geometry (pos, normal and mat)
  // and the shape that was hit with the ray
  *loc = min_local;
  *num = min_shapenum;
}

// Check if the light ray intersects with an other objects and is in shadow
bool RayTracer::shadowintersection(Ray& lray, int shapenum) {
  Local local;
  for (int i = 0; i < shapes.size(); i++) {
    //Doesn't shadow itself
    if (i != shapenum) {
      // True if there is something between the object and the light
      if (shapes[i]->intersect(lray, &local, true))
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

// Main trace algorithm
bool RayTracer::trace(Ray& ray, int depth, Color* color) {
  Local local;
  int shapenum;

  //Recursive check
  if (depth > MAXDEPTH)
    return false;
  
  //Find an intersection
  findintersection(ray, &local, &shapenum);
  //No intersection, return, will stay black
  if (shapenum == -1)
    return false;

  //There is an intersection, calculate lighting
  for (int i = 0; i < lights.size(); i++) {
    Ray lray;
    // Create light ray from the object to the light source
    lights[i]->generateLightRay(local, &lray);
    
    //See if shadows are allowed on the surface, if not just add the color
    if (!shapes[shapenum]->shadow)
      lights[i]->shade(local, lray, ray, color);
    //Check for shadow, if nothing is blocking the ray from the object to the light then add color
    else if (!shadowintersection(lray, shapenum))
      lights[i]->shade(local, lray, ray, color);
  }

  // Mirror reflection
  if (local.material->reflection > 0) {
    Color nextColor;
    // Get reflected ray
    Ray reflectRay;
    generateReflectRay(local, ray, &reflectRay);
    
    // Recursive call to reflected ray
    trace(reflectRay, depth + 1, &nextColor);
    *color += nextColor * local.material->reflection;
  }
  
  return true;
}







