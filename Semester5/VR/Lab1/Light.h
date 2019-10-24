#include "Vector.h"
#include "Line.h"
#include "Color.h"
#include "Intersection.h"

#ifndef RT_LIGHT_INCLUDED
#define RT_LIGHT_INCLUDED

namespace rt {

    class Light {
    private:
        Vector _position;
        Color _ambient;
        Color _diffuse;
        Color _specular;
        int _intensity;

    public:
        Light() {
            _intensity = 0;
        }

        Light(const Vector& position,
            const Color& ambient,
            const Color& diffuse,
            const Color& specular,
            int intensity) {
            _position = Vector(position);
            _ambient = Color(ambient);
            _diffuse = Color(diffuse);
            _specular = Color(specular);

            _intensity = intensity;
        }

        Light(float x, float y, float z,
            float ar, float ag, float ab,
            float dr, float dg, float db,
            float sr, float sg, float sb,
            int sh) {
            _position = Vector(x, y, z);
            _ambient = Color(ar, ag, ab);
            _diffuse = Color(dr, dg, db);
            _specular = Color(sr, sg, sb);

            _intensity = sh;
        }

        Light(const Light& light) {
            _position = Vector(light.position());
            _ambient = Color(light.ambient());
            _diffuse = Color(light.diffuse());
            _specular = Color(light.specular());

            _intensity = light.intensity();
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

        inline const Vector& position() const {
            return _position;
        }

        inline int intensity() const {
            return _intensity;
        }
    };
}

#endif
