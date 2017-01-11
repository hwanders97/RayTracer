//
// This class stores the position of each pixel sample
//


#include "sample.h"

// Default constructor
Sample::Sample() {
  x = y = 0.5;
}

// Iterates through the samples, going row by row
bool Sample::next() {
  if (x < WIDTH - 1) {
    x++;
  } else {
    // Next row
    x = 0.5;
    if (y < HEIGHT - 1) {
      y++;
    } else return false;
  }
  return true;
}

// Static members must be declared outside of class
// Starts at 0.5 because the ray is sent to the center of a pixel
float Sample::x = 0.5;
float Sample::y = 0.5;
