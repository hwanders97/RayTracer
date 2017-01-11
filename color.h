//
// Header file for the color class
// A color has values r, g, b and overrides Color combination operations
//


#pragma once

//Class to implment color functionality with simple r,g,b values
class Color {
public:
  float r, g, b;
  Color();
  Color(float rc, float gc, float bc);
  Color operator + (const Color& other);
  void operator += (const Color& other);
  Color operator * (const Color& other);
  void operator *= (const Color& other);
  Color operator * (const float scalar);
  void operator *= (const float scalar);
  Color operator / (const float scalar);
  void operator /= (const float scalar);
};

