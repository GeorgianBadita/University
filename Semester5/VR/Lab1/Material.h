#include <random>
#include <ctime>
#include <time.h>
#include "Vector.h"
#include "Line.h"
#include "Color.h"
#include "Intersection.h"

#ifndef RT_MATERIAL_INCLUDED
#define RT_MATERIAL_INCLUDED

namespace rt {

    class Material {
    private:
        Color _ambient;
        Color _diffuse;
        Color _specular;
        int _shininess;

    public:
        Material() {
            _shininess = 0;
            srand(time(nullptr));
            double r1 = ((double) rand() / (RAND_MAX));
            double r2 = ((double) rand() / (RAND_MAX));
            double r3 = ((double) rand() / (RAND_MAX));
            double r4 = ((double) rand() / (RAND_MAX));
            double r5 = ((double) rand() / (RAND_MAX));
            double r6 = ((double) rand() / (RAND_MAX));
            double r7 = ((double) rand() / (RAND_MAX));
            double r8 = ((double) rand() / (RAND_MAX));
            double r9 = ((double) rand() / (RAND_MAX));
            _ambient = Color(r1, r2, r3);
            _diffuse = Color(r4, r5, r6);
            _specular = Color(r7, r8, r9);
            _shininess = 1;
        }

        Material(const Color& ambient, const Color& diffuse, const Color& specular, int shininess) {
            _ambient = Color(ambient);
            _diffuse = Color(diffuse);
            _specular = Color(specular);

            _shininess = shininess;
        }

        Material(float ar, float ag, float ab,
            float dr, float dg, float db,
            float sr, float sg, float sb,
            int shininess) {
            _ambient = Color(ar, ag, ab);
            _diffuse = Color(dr, dg, db);
            _specular = Color(sr, sg, sb);

            _shininess = shininess;
        }

        Material(const Material& mat) {
            _ambient = Color(mat.ambient());
            _diffuse = Color(mat.diffuse());
            _specular = Color(mat.specular());

            _shininess = mat.shininess();
        }

        inline const Color& ambient() const {
            return _ambient;
        }

        inline const Color& diffuse() const {
            return _diffuse;
        }

        inline const Color& specular() const {
            return _specular;
        }

        inline int shininess() const {
            return _shininess;
        }
    };
}

#endif
