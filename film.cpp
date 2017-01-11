//
// This class sets up the output image
//


#include "film.h"


// Draw image using the FreeImage library
void Film::writeImage(char* filename) {
  // Concatenate .png to the filename so it is output correctly
  filename = strcat(filename, ".png");
  
  // Open FreeImage library
  FreeImage_Initialise();
  
  // Get the image with the pixel array of colors
  FIBITMAP *img = FreeImage_ConvertFromRawBits(pixels, WIDTH, HEIGHT, WIDTH * 3, 24, 0xFF0000, 0x00FF00, 0x0000FF, false);
  
  // Confirmation that the image is made
  std::cout << "made image" << std::endl;
  
  // Create a png file with the image called 'filename'.png
  FreeImage_Save(FIF_PNG, img, filename, 0);
  
  // Close FreeImage library
  FreeImage_DeInitialise();
}
  
//Help from http://jcoppens.com/soft/howto/libs/freeimage.en.php
void Film::commit(Color& color) {
  // Sample is in the center of the pixel, need the position in the array 0.5 over
  int x = Sample::x - 0.5;
  int y = Sample::y - 0.5;
  // r, g, b need to be in the range 0 - 255 when put in the pixel array
  pixels[3*y*WIDTH + 3*x + 0] = color.b * 255;
  pixels[3*y*WIDTH + 3*x + 1] = color.g * 255;
  pixels[3*y*WIDTH + 3*x + 2] = color.r * 255;
}
