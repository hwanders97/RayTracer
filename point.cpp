//
// This class is different from the vector class because it does not have a direction, just an
// x, y, z position in space. Can combine points and vectors.
//


#include "point.h"

// Default constructor
Point::Point() : x(0), y(0), z(0) {};

// Input constructor
Point::Point(float xp, float yp, float zp) : x(xp), y(yp), z(zp) {};

// Change the sign of the point's coordinates
Point Point::operator - () {
  return Point(-x, -y, -z);
}

// Add points
Point Point::operator + (const Vector& other) {
  return Point(x + other.x, y + other.y, z + other.z);
}

// Subtracting 2 points gives a vector
Vector Point::operator - (const Point& other) {
  return Vector(x - other.x, y - other.y, z - other.z);
}

// Find the dot product between a point and a vector, same as dot product between vectors
float Point::dot(const Point& p, const Vector& v) {
  return (p.x * v.x + p.y * v.y + p.z * v.z);
}


