CC = g++
ifeq ($(shell sw_vers 2>/dev/null | grep Mac | awk '{ print $$2}'),Mac)
CFLAGS = -g -DGL_GLEXT_PROTOTYPES -DOSX -Wno-deprecated-register -Wno-deprecated-declarations -Wno-shift-op-parentheses
INCFLAGS = -I/usr/X11/include -I./include/
LDFLAGS = -L./osxlib/ -lm -lstdc++ -lfreeimage
else
CFLAGS = -g -DGL_GLEXT_PROTOTYPES 
INCFLAGS = -I./include/ -I/usr/X11R6/include -I/sw/include \
		-I/usr/sww/include -I/usr/sww/pkg/Mesa/include
LDFLAGS = -L/usr/X11R6/lib -L/sw/lib -L/usr/sww/lib \
		-L/usr/sww/bin -L/usr/sww/pkg/Mesa/lib -lX11 -lfreeimage
endif

RM = /bin/rm -f 
all: scene.o film.o raytracer.o color.o camera.o local.o material.o light.o sphere.o \
		plane.o pointlight.o ray.o sample.o point.o vector.o
	$(CC) $(CFLAGS) -o output scene.o film.o raytracer.o color.o camera.o \
		local.o material.o light.o sphere.o plane.o pointlight.o \
		ray.o sample.o point.o vector.o $(INCFLAGS) $(LDFLAGS)




scene.o: scene.cpp scene.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c scene.cpp
scene.h: film.o raytracer.o


film.o: film.cpp film.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c film.cpp
film.h: color.o camera.o


raytracer.o: raytracer.cpp raytracer.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c raytracer.cpp
raytracer.h: sphere.o plane.o pointlight.o


sphere.o: sphere.cpp sphere.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c sphere.cpp
sphere.h: shape.h


plane.o: plane.cpp plane.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c plane.cpp
plane.h: shape.h


shape.h: ray.o local.o color.o


pointlight.o: pointlight.cpp pointlight.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c pointlight.cpp
pointlight.h: light.h


light.h: ray.o local.o color.o


color.o: color.cpp color.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c color.cpp


camera.o: camera.cpp camera.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c camera.cpp
camera.h: ray.o sample.o


local.o: local.cpp local.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c local.cpp
local.h: point.o material.o


material.o: material.cpp material.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c material.cpp
material.h: color.cpp color.h


ray.o: ray.cpp ray.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c ray.cpp
ray.h: point.o


sample.o: sample.cpp sample.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c sample.cpp


point.o: point.cpp point.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c point.cpp
point.h: vector.o


vector.o: vector.cpp vector.h
	$(CC) $(CFLAGS) $(INCFLAGS) -c vector.cpp


clean: 
	$(RM) *.o output


 
