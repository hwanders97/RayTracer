//
// This class sets up the color class that has the values r, g, b and overrides operations to combine
// colors
//


#include "color.h"

// Default constructor
Color::Color() : r(0), g(0), b(0) {};

// Input constructor
Color::Color(float rc, float gc, float bc) : r(rc), g(gc), b(bc) {};

// Addition
Color Color::operator + (const Color& other) {
  // Addition of colors averages the sum of each component
  return Color((r + other.r) / 2, (g + other.g) / 2, (b + other.b) / 2);
}

// Side effect addition
void Color::operator += (const Color& other) {
  // Average the sum
//  r = (r + other.r) / 2;
//  g = (g + other.g) / 2;
//  b = (b + other.b) / 2;
  
  // Bound by 1
    r += other.r;
    g += other.g;
    b += other.b;
    if (r > 1) r = 1;
    if (g > 1) g = 1;
    if (b > 1) b = 1;
}

// Multiplication
Color Color::operator * (const Color& other) {
  // All input is between 0 and 1 so no bound is necessary
  return Color(r * other.r, g * other.g, b * other.b);
}

// Side effect multiplication
void Color::operator *= (const Color& other) {
  r *= other.r;
  g *= other.g;
  b *= other.b;
}

// Scalar multiplication
Color Color::operator * (const float scalar) {
  // Need to be bound by 1 because scalar can be greater than 1
  float nr = r * scalar;
  float ng = g * scalar;
  float nb = b * scalar;
  if (nr > 1) nr = 1;
  if (ng > 1) ng = 1;
  if (nb > 1) nb = 1;
  return Color(nr, ng, nb);
}

// Side effect scalar multiplication
void Color::operator *= (const float scalar) {
  r *= scalar;
  g *= scalar;
  b *= scalar;
  if (r > 1) r = 1;
  if (g > 1) g = 1;
  if (b > 1) b = 1;
}

// Scalar division
Color Color::operator / (const float scalar) {
  // Need to be bound by 1 because scalar can be less than 1
  float nr = r / scalar;
  float ng = g / scalar;
  float nb = b / scalar;
  if (nr > 1) nr = 1;
  if (ng > 1) ng = 1;
  if (nb > 1) nb = 1;
  return Color(nr, ng, nb);
}

// Side effect scalar division;
void Color::operator /= (const float scalar) {
  r /= scalar;
  g /= scalar;
  b /= scalar;
  if (r > 1) r = 1;
  if (g > 1) g = 1;
  if (b > 1) b = 1;
}




















