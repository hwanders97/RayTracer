//
// Header for the film class
// Has an array of pixels to store the color of the picture
//


#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <FreeImage.h>
#include "color.h"
#include "camera.h"

class Film {
public:
  void commit(Color& color);
  void writeImage(char* filename);

private:
  //Array to keep track of each pixel, need enough room for each r, g, b value
  BYTE pixels[3 * WIDTH * HEIGHT];
  
};
