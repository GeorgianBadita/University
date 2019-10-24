#include <iostream>
#include "Vector.h"

#ifndef RT_INTERSECTION_INCLUDED
#define RT_INTERSECTION_INCLUDED

namespace rt {

    class Geometry;
    class Line;

    class Intersection {
    private:
        bool _valid;
        float _t;
        Vector _vec;
        const Geometry* _geometry;
        const Line* _line;

    public:
        Intersection() {
            _geometry = NULL;
            _line = NULL;
            _valid = false;
            _t = 0;
            _vec = Vector();
        }

        Intersection(bool b, const Geometry* geometry, const Line* line, float t) {
            _geometry = geometry;
            _line = line;
            _valid = b;
            _t = t;
            _vec = line->vec(t);
        }

        inline bool valid() const {
            return _valid;
        }

        inline float t() const {
            return _t;
        }

        inline const Vector& vec() const {
            return _vec;
        }

        inline const Geometry* geometry() const {
            return _geometry;
        }

        inline const Line* line() const {
            return _line;
        }
    };
}

#endif
