//
// Header for RayTracer class, which has shapes and lights members to iterate through
// Contains main raytrace algorithm and helps calculate shadows and reflections
//


#pragma once

// Max reflection bounces for recursion
#define MAXDEPTH 5

#include <vector>
// Debug
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "sphere.h"
#include "plane.h"
#include "pointlight.h"

using namespace std;

class RayTracer {
public:
  RayTracer(vector<Shape*> shapesarr, vector<Light*> lightsarr);
  bool trace(Ray& ray, int depth, Color* color);
  
private:
  void findintersection(Ray& ray, Local* loc, int* num);
  bool shadowintersection(Ray& lray, int shapenum);
  void generateReflectRay(Local& local, Ray& ray, Ray* reflectRay);
  vector<Shape*> shapes;
  vector<Light*> lights;
};

