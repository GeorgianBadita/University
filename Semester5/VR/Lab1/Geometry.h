#include "Material.h"
#include "Vector.h"
#include "Line.h"
#include "Intersection.h"

#ifndef RT_GEOMETRY_INCLUDED
#define RT_GEOMETRY_INCLUDED

namespace rt {

    class Geometry {
    private:
        Color _color;
        Material _material;

    public:
        Geometry() {
            _material = Material();
            _color = Color();
        }

        Geometry(const Material& material) {
            _material = Material(material);
            _color = Color();
        }

        Geometry(const Color& color) {
            _material = Material();
            _color = Color(color);
        }

        Geometry(const Geometry& geometry) {
            _material = Material(geometry.material());
            _color = Color(geometry.color());
        }

        virtual ~Geometry() {
        }

        virtual Intersection getIntersection(const Line& line,
            float minDist,
            float maxDist) {
            Intersection in(false, this, &line, 0);
            return in;
        };

        inline const Material& material() const {
            return _material;
        }

        inline const Color& color() const {
            return _color;
        }

        virtual inline const Vector normal(const Vector& vec) const {
            return Vector(1, 0, 0);
        }
    };
}

#endif
