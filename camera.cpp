//
// This class sets up the camera at a position "lookfrom" looking at "lookat" with an up vector "up"
// The camera creates a ray from the camera position to a given sample, based on the width and height
//


#include "camera.h"

// Default constructor sets up the
Camera::Camera() {
  lookfrom = Point(0, 0, 1);
  lookat = Point(0, 0, 0);
  up = Vector(0, 1, 0);
}

// Constructor to set camera position
Camera::Camera(Point from, Point at, Vector upvec) : lookfrom(from), lookat(at), up(upvec) {};

// Creates a ray in the direction of a given sample
Ray Camera::generateRay() {
  // Set up camera coordinate frame
  Vector temp = lookfrom - lookat;
  Vector w = Vector::normalize(temp);
  temp = Vector::cross(up, w);
  Vector u = Vector::normalize(temp);
  Vector v = Vector::cross(w, u);
  
  // Calculate with field of view
  float tany = tan((FOVY / 2) * PI/180);
  // Keep aspect ratio 1:1
  float tanx = tany * WIDTH / HEIGHT;
  float alpha = tanx / (WIDTH / 2);
  float beta = tany / (HEIGHT / 2);
  // Get sample coordinates and use them to calculate the direction of the ray
  Vector direction = u * alpha * (Sample::x - (WIDTH / 2)) + v * beta * (Sample::y - (HEIGHT / 2)) - w;
  // Return ray with the starting position of the camera and the normalized direction to the sample
  Ray ray(lookfrom, Vector::normalize(direction));
  return ray;
}

