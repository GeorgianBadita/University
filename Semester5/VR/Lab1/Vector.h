#include <cmath>

#ifndef RT_VECTOR_INCLUDED
#define RT_VECTOR_INCLUDED

namespace rt {

    class Vector {
    private:
        float _xyz[3];

    public:
        Vector() {
            _xyz[0] = 0;
            _xyz[1] = 0;
            _xyz[2] = 0;
        }

        Vector(float x, float y, float z) {
            _xyz[0] = x;
            _xyz[1] = y;
            _xyz[2] = z;
        }

        Vector(const Vector& v) {
            _xyz[0] = v._xyz[0];
            _xyz[1] = v._xyz[1];
            _xyz[2] = v._xyz[2];
        }

        inline float& x() {
            return _xyz[0];
        }

        inline float& y() {
            return _xyz[1];
        }

        inline float& z() {
            return _xyz[2];
        }

        inline Vector operator + (const Vector& v) const {
            return Vector(_xyz[0] + v._xyz[0],
                _xyz[1] + v._xyz[1],
                _xyz[2] + v._xyz[2]);
        }

        inline Vector& operator += (const Vector& v) {
            _xyz[0] += v._xyz[0];
            _xyz[1] += v._xyz[1];
            _xyz[2] += v._xyz[2];
            return *this;
        }

        inline Vector operator - (const Vector& v) const {
            return Vector(_xyz[0] - v._xyz[0],
                _xyz[1] - v._xyz[1],
                _xyz[2] - v._xyz[2]);
        }

        inline Vector& operator -= (Vector& v) {
            _xyz[0] -= v._xyz[0];
            _xyz[1] -= v._xyz[1];
            _xyz[2] -= v._xyz[2];
            return *this;
        }

        inline float operator * (const Vector& v) const {
            return _xyz[0] * v._xyz[0] + _xyz[1] * v._xyz[1] + _xyz[2] * v._xyz[2];
        }

        inline Vector operator ^ (const Vector& v) const {
            return Vector(_xyz[1] * v._xyz[2] - _xyz[2] * v._xyz[1],
                _xyz[2] * v._xyz[0] - _xyz[0] * v._xyz[2],
                _xyz[0] * v._xyz[1] - _xyz[1] * v._xyz[0]);
        }

        inline Vector operator * (float k) const {
            return Vector(_xyz[0] * k,
                _xyz[1] * k,
                _xyz[2] * k);
        }

        inline bool operator==(Vector& v){
            return this->x() == v.x() && this->y() == v.y() and this->z() == v.z();
        }

        inline Vector& operator *= (float k) {
            _xyz[0] *= k;
            _xyz[1] *= k;
            _xyz[2] *= k;
            return *this;
        }

        inline Vector operator / (float k) const {
            return Vector(_xyz[0] / k,
                _xyz[1] / k,
                _xyz[2] / k);
        }

        inline Vector& operator /= (float k) {
            _xyz[0] /= k;
            _xyz[1] /= k;
            _xyz[2] /= k;
            return *this;
        }

        inline float length() const {
            return sqrt(_xyz[0] * _xyz[0] + _xyz[1] * _xyz[1] + _xyz[2] * _xyz[2]);
        }

        inline float length2() const {
            return _xyz[0] * _xyz[0] + _xyz[1] * _xyz[1] + _xyz[2] * _xyz[2];
        }

        inline float normalize() {
            float norm = length();
            if (norm > 0.0)
            {
                float inv = 1.0f / norm;
                _xyz[0] *= inv;
                _xyz[1] *= inv;
                _xyz[2] *= inv;
            }
            return norm;
        }
    };
}

#endif
