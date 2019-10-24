#include "Geometry.h"
#include "Sphere.h"
#include "Light.h"

using namespace rt;

int geometryCount = 8;

Geometry* scene[] = {
    new Sphere( -50.0f,  -25.0f,  175.0f,   30.0f,    0.3f,  0.0f,  0.0f),
    new Sphere( -10.0f,    0.0f,  100.0f,   10.0f,    0.3f,  0.3f,  0.0f),
    new Sphere(   0.0f,    0.0f,  200.0f,   40.0f,    0.0f,  0.3f,  0.0f),
    new Sphere(   0.0f,  -50.0f,  200.0f,   10.0f,    0.3f,  0.3f,  0.3f),
    new Sphere(  10.0f,    0.0f,   20.0f,    5.0f,    0.0f,  0.3f,  0.3f),
    new Sphere( -70.0f,    0.0f,  100.0f,   10.0f,    0.3f,  0.0f,  0.3f),
    new Sphere(  50.0f,   25.0f,   75.0f,   50.0f,    0.0f,  0.0f,  0.3f),
	new Sphere( -75.0f,   15.0f,   75.0f,    5.0f,   0.07f, 0.07f, 0.07f)
};

int lightCount = 2;
Light* lights[] = {
    new Light(-50.0f,  0.0f, 0.0f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 1),
    new Light( 20.0f, 20.0f, 0.0f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 1)
};
