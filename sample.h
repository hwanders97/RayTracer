//
// Header file for the sample class
// Contains definitions for the width and height of the picture, stores x, y values for the sample
// of each pixel
//


#pragma once

#define WIDTH 640
#define HEIGHT 480

class Sample {
public:
  static float x, y;
  Sample();
  static bool next();
};


