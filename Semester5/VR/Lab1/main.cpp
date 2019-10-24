#include <cmath>
#include <iostream>
#include <string>

#include "Vector.h"
#include "Line.h"
#include "Geometry.h"
#include "Sphere.h"
#include "Image.h"
#include "Color.h"
#include "Intersection.h"
#include "Material.h"

#include "Scene.h"

using namespace std;
using namespace rt;

float imageToViewPlane(int n, int imgSize, float viewPlaneSize) {
    float u = (float)n*viewPlaneSize / (float)imgSize;
    u -= viewPlaneSize / 2;
    return u;
}

const Intersection findFirstIntersection(const Line& ray,
    float minDist, float maxDist) {
    Intersection intersection;

    for (int i = 0; i < geometryCount; i++) {
        Intersection in = scene[i]->getIntersection(ray, minDist, maxDist);
        if (in.valid()) {
            if (!intersection.valid()) {
                intersection = in;
            }
            else if (in.t() < intersection.t()) {
                intersection = in;
            }
        }
    }

    return intersection;
}

int main() {
    Vector viewPoint(-50, 10, 0);
    Vector viewDirection(50, -10, 100);
    Vector viewUp(0, -1, 0);

	viewDirection.normalize();
	viewUp.normalize();

    float frontPlaneDist = 0.0001;
    float backPlaneDist = 1000;

    float viewPlaneDist = 64;
    float viewPlaneWidth = 160;
    float viewPlaneHeight = 120;

    int imageWidth = 1024;
    int imageHeight = 768;

    Vector viewParallel = viewUp^viewDirection;
    viewParallel.normalize();

    Image image(imageWidth, imageHeight);

	for(int i = 0; i<imageHeight; i++){
	    for(int j = 0; j<imageWidth; j++){
	        image.setPixel(j, i, Color(0, 0, 0));
	    }
	}


	for(int i = 0; i<imageHeight; i++){
	    for(int j = 0; j<imageWidth; j++){
	        auto offsetUp = imageToViewPlane(i, imageHeight, viewPlaneHeight);
	        auto offsetRight = imageToViewPlane(j, imageWidth, viewPlaneWidth);
	        auto v = viewPoint + viewDirection * viewPlaneDist + viewUp * offsetUp +
	                        viewParallel * offsetRight;
	        auto ray = Line(viewPoint, v, false);
	        auto in = findFirstIntersection(ray, frontPlaneDist, backPlaneDist);
	        if(in.valid()){
	            Color color = in.geometry()->color();
	            for(int lightIndex = 0; lightIndex < lightCount; lightIndex ++) {
                    Vector L = lights[lightIndex]->position();
                    Vector C = viewPoint;
                    Vector V = in.vec();
                    Vector E = C - V;
                    E.normalize();
                    Vector N = in.geometry()->normal(V);
                    Vector T = L - V;
                    T.normalize();
                    Vector R = N * (N * T) * 2 - T;
                    R.normalize();
                    Material material = in.geometry()->material();
                    color *= lights[lightIndex]->ambient();
                    if (N * T > 0) {
                        color += material.diffuse() * lights[lightIndex]->diffuse() * (N * T);
                    }
                    if (E * R > 0) {
                        color += material.specular() * lights[lightIndex]->specular() * pow(E * R, material.shininess());
                    }

                    color *= lights[lightIndex]->intensity();
                }
	            image.setPixel(j, i, color);
	        }
	    }
	}


    image.store("scene.png");

    for (int i = 0; i < geometryCount; i++) {
        delete scene[i];
    }

	for (int i = 0; i < lightCount; i++) {
		delete lights[i];
	}

    return 0;
}
