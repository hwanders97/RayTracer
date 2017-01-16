//
// This class creates the scene with its objects and lights, a raytracer and camera and renders
// the scene with the raytracer algorithm.
//


#include "scene.h"

// Default constructor
Scene::Scene(char* name) {
  // Initialize filename string
  filename = strcpy(filename, name);
  
  // Setup lights + objects + raytracer + camera
  
  // Scene's camera
  camera = new Camera(Point(0, 10, 0), Point(0, 0, -10), Vector(0, 0, -1));
//  camera = new Camera();
  vector<Shape*> shapes;
  vector<Light*> lights;
  
  // Materials
  //                              matcolor    diff spec shine reflect refract
  Material* red = new Material(Color(1, 0, 0), 0.5, 0.5, 20, 0, 1);
  Material* green = new Material(Color(0, 1, 0), 0.5, 0.5, 20, 0, 1);
  Material* blue = new Material(Color(0, 0, 1), 0.5, 0.5, 20, 0, 1);
  Material* bubble = new Material(Color(1, 1, 1), 0.2, 0.5, 20, 0, 1.1);
  Material* mirror = new Material(Color(), 1, 0, 20, 1, 1);
  Material* floor = new Material(Color(0.7, 0.5, 0.8), 0.6, 0, 20, 0, 1);

  
  // Spheres
  // Red row
  shapes.push_back(new Sphere(10, 2, -15, 1, new Material(Color(0.3, 0, 0), 0.5, 1, 20, 0, 1), true, true));
  shapes.push_back(new Sphere(6, 2, -15, 1, new Material(Color(0.5, 0, 0), 0.5, 0.75, 20, 0, 1), true, true));
  shapes.push_back(new Sphere(2, 2, -15, 1, new Material(Color(0.6, 0, 0), 0.5, 0.5, 20, 0, 1), true, true));
  shapes.push_back(new Sphere(-2, 2, -15, 1, new Material(Color(0.6, 0, 0), 0.5, 0.5, 20, 0, 1), true, true));
  shapes.push_back(new Sphere(-6, 2, -15, 1, new Material(Color(0.75, 0, 0), 0.7, 0.3, 20, 0, 1), true, true));
  shapes.push_back(new Sphere(-10, 2, -15, 1, new Material(Color(1, 0, 0), 0.9, 0.1, 20, 0, 1), true, true));
  
  // Green row
  shapes.push_back(new Sphere(10, 2, -10, 1, new Material(Color(0, 0.3, 0), 0.5, 1, 20, 0, 1), true, true));
  shapes.push_back(new Sphere(6, 2, -10, 1, new Material(Color(0, 0.5, 0), 0.5, 0.75, 20, 0, 1), true, true));
  shapes.push_back(new Sphere(2, 2, -10, 1, new Material(Color(0, 0.6, 0), 0.5, 0.5, 20, 0, 1), true, true));
  shapes.push_back(new Sphere(-2, 2, -10, 1, new Material(Color(0, 0.6, 0), 0.5, 0.5, 20, 0, 1), true, true));
  shapes.push_back(new Sphere(-6, 2, -10, 1, new Material(Color(0, 0.75, 0), 0.7, 0.3, 20, 0, 1), true, true));
  shapes.push_back(new Sphere(-10, 2, -10, 1, new Material(Color(0, 1, 0), 0.9, 0.1, 20, 0, 1), true, true));
  
  // Blue row
  shapes.push_back(new Sphere(10, 2, -5, 1, new Material(Color(0, 0, 0.3), 0.5, 1, 20, 0, 1), true, true));
  shapes.push_back(new Sphere(6, 2, -5, 1, new Material(Color(0, 0, 0.5), 0.5, 0.75, 20, 0, 1), true, true));
  shapes.push_back(new Sphere(2, 2, -5, 1, new Material(Color(0, 0, 0.6), 0.5, 0.5, 20, 0, 1), true, true));
  shapes.push_back(new Sphere(-2, 2, -5, 1, new Material(Color(0, 0, 0.6), 0.5, 0.5, 20, 0, 1), true, true));
  shapes.push_back(new Sphere(-6, 2, -5, 1, new Material(Color(0, 0, 0.75), 0.7, 0.3, 20, 0, 1), true, true));
  shapes.push_back(new Sphere(-10, 2, -5, 1, new Material(Color(0, 0, 1), 0.9, 0.1, 20, 0, 1), true, true));
  
  
  //Bubble spheres
  shapes.push_back(new Sphere(0, 6.5, -3, 2.7, bubble, true, true));
  
  
  // Mirror spheres
  shapes.push_back(new Sphere(-15, 6, -20, 7, mirror, true, true));
  
  
  // Planes
  // Floor
  shapes.push_back(new Plane(0, 1, 0, 2, floor, true, true));


  
  // Lights
//  lights.push_back(new PointLight(Point(15, 15, -10), Color(0.4, 0.6, 0.4)));
//  lights.push_back(new PointLight(Point(-15, 15, -10), Color(0.2, 0.55, 0.4)));
  lights.push_back(new PointLight(Point(0, 20, -10), Color(1, 1, 1)));

  
  //Make raytracer with these shapes and lights
  raytracer = new RayTracer(shapes, lights);
}

// Renders the scene by sending rays through each pixel, getting the color of the intersection
// and adding that color to the pixel array
void Scene::render() {
  Ray ray;
  Film film;
  
  while (Sample::next()) {
    Color color;
    ray = camera->generateRay();
    raytracer->trace(ray, 1, &color);
    film.commit(color);
  }
  film.writeImage(filename);
  
  // Pseudocode algorithm:
  // while(getsample)
  //  camera generate ray
  //  trace ray, get final color
  //  film commit color
  // film write image
}


// Main function to instantiate the scene and render it
int main(int argc, char* argv[]) {
  // Must have a second argument as the output file name
  if (argv[1] == '\0')
    cout << "Second argument requires a file name. Will output to \"filename\".png" << endl;
  else {
    Scene* scene = new Scene(argv[1]);
    scene->render();
  }
  return 0;
}


