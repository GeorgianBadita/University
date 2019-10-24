#include "Vector.h"
#include "Line.h"
#include "Intersection.h"
#include "Geometry.h"
#include "Material.h"

#ifndef RT_SPHERE_INCLUDED
#define RT_SPHERE_INCLUDED

namespace rt {

    class Sphere : public Geometry {
    private:
        Vector _center;
        float _radius;

    public:
        Sphere(const Vector& center, float radius, const Material& material)
            : Geometry(material) {
            _center = Vector(center);
            _radius = radius;
        }

        Sphere(float x, float y, float z, float radius, float r, float g, float b)
            : Geometry(Color(r, g, b)) {
            _center = Vector(x, y, z);
            _radius = radius;
        }

        Sphere(float x, float y, float z, float radius,
            float ar, float ag, float ab,
            float dr, float dg, float db,
            float sr, float sg, float sb,
            int sh)
            : Geometry(Material(ar, ag, ab, dr, dg, db, sr, sg, sb, sh)) {
            _center = Vector(x, y, z);
            _radius = radius;
        }

        ~Sphere() {
        }

        virtual Intersection getIntersection(const Line& line,
            float minDist,
            float maxDist);

        inline float& radius() {
            return _radius;
        }

        inline Vector& center() {
            return _center;
        }

        virtual const Vector normal(const Vector& vec) const;
    };
}

#endif
