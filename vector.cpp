//
// This class sets up vector properties, which has a direction in x, y, z
// Also contains vector combination overrides
//

#include "vector.h"

// Default constructor
Vector::Vector() : x(0), y(0), z(0) {};

// Input constructor
Vector::Vector(float xv, float yv, float zv) : x(xv), y(yv), z(zv) {};

// Reverse sign of vector components
Vector Vector::operator - () {
  return Vector(-x, -y, -z);
}

// Vector addition
Vector Vector::operator + (const Vector& other) {
  return Vector(x + other.x, y + other.y, z + other.z);
}

// Vector subtraction
Vector Vector::operator - (const Vector& other) {
  return Vector(x - other.x, y - other.y, z - other.z);
}

// Vector-scalar multiplication
Vector Vector::operator * (const float scalar) {
  return Vector(x * scalar, y * scalar, z * scalar);
}

// Vector-scalar division
Vector Vector::operator / (const float scalar) {
  return Vector(x / scalar, y / scalar, z / scalar);
}

// Vector length
float Vector::length() {
  return sqrt(x * x + y * y + z * z);
}

// Vector normalize: vector / vector length
Vector Vector::normalize (Vector& vec) {
  return vec / vec.length();
}

// Dot product
float Vector::dot(Vector& vec1, Vector& vec2) {
  return (vec1.x*vec2.x + vec1.y*vec2.y + vec1.z*vec2.z);
}

// Cross product
Vector Vector::cross(Vector& vec1, Vector& vec2) {
  return Vector(vec1.y*vec2.z - vec1.z*vec2.y, vec1.z*vec2.x - vec1.x*vec2.z, vec1.x*vec2.y - vec1.y*vec2.x);
}








