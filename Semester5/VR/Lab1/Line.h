#include "Vector.h"

#ifndef RT_LINE_INCLUDED
#define RT_LINE_INCLUDED

namespace rt {

    class Line {
    private:
        Vector _x0;
        Vector _dx;

    public:
        Line() {
            _x0 = Vector(0.0, 0.0, 0.0);
            _dx = Vector(1.0, 0.0, 0.0);
        }

        Line(const Vector& x0, const Vector& x1, bool parametric) {
            _x0 = Vector(x0);

            if (parametric) {
                _dx = Vector(x1);
            }
            else {
                _dx = Vector(x1 - x0);
            }
            _dx.normalize();
        }

        Line(const Line& line) {
            _x0 = Vector(line._x0);
            _dx = Vector(line._dx);
        }

        inline Vector x0() const {
            return _x0;
        }

        inline Vector dx() const {
            return _dx;
        }

        inline Vector vec(float t) const {
            return Vector(_dx*t + _x0);
        }
    };
}

#endif
