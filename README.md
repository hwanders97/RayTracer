# RayTracer
This is a raytracer that creates realistic images with spheres and planes, reflections and shadows.

To run the program use the command "make" to create an executable output file named "output". To create the image run ./output "filename",
where you put in any string in place of "filename". The picture created will be called "filename".png, where filename is your input string.

To change objects in the scene read through the Scene class to see how to create spheres, planes and lights. Also take a look at the
Material class to understand the components of a shape's material. 
You can also change the camera position and view direction by changing the values where the camera is initialized in the Scene initializer.
