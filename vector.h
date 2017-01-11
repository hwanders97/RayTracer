//
// Header file for vector class, containing members x, y, z and operation overrides for vector
// combination
//


#pragma once

#include <cmath>


class Vector {
public:
  float x, y, z;
  Vector();
  Vector(float xv, float yv, float zv);
  Vector operator - ();
  Vector operator + (const Vector& other);
  Vector operator - (const Vector& other);
  Vector operator * (const float scalar);
  Vector operator / (const float scalar);
  float length();
  static Vector normalize(Vector& vec);
  static float dot(Vector& vec1, Vector& vec2);
  static Vector cross(Vector& vec1, Vector& vec2);
};





