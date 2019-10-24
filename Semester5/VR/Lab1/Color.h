#ifndef RT_COLOR_INCLUDED
#define RT_COLOR_INCLUDED

namespace rt {

    class Color {
    private:
        float _rgb[3];

    public:
        Color() {
            _rgb[0] = 0;
            _rgb[1] = 0;
            _rgb[2] = 0;
        }

        Color(float r, float g, float b) {
            _rgb[0] = r;
            _rgb[1] = g;
            _rgb[2] = b;
        }

        Color(const Color& c) {
            _rgb[0] = c._rgb[0];
            _rgb[1] = c._rgb[1];
            _rgb[2] = c._rgb[2];
        }

        inline float red() const {
            return _rgb[0];
        }

        inline float green() const {
            return _rgb[1];
        }

        inline float blue() const {
            return _rgb[2];
        }

        inline Color operator + (const Color& c) const {
            return Color(_rgb[0] + c._rgb[0],
                _rgb[1] + c._rgb[1],
                _rgb[2] + c._rgb[2]);
        }

        inline Color& operator += (const Color& c) {
            _rgb[0] += c._rgb[0];
            _rgb[1] += c._rgb[1];
            _rgb[2] += c._rgb[2];
            return *this;
        }

        inline Color operator - (const Color& c) const {
            return Color(_rgb[0] - c._rgb[0],
                _rgb[1] - c._rgb[1],
                _rgb[2] - c._rgb[2]);
        }

        inline Color& operator -= (const Color& c) {
            _rgb[0] -= c._rgb[0];
            _rgb[1] -= c._rgb[1];
            _rgb[2] -= c._rgb[2];
            return *this;
        }

        inline Color operator * (const Color& c) const {
            return Color(_rgb[0] * c._rgb[0],
                _rgb[1] * c._rgb[1],
                _rgb[2] * c._rgb[2]);
        }

        inline Color& operator *= (const Color& c) {
            _rgb[0] *= c._rgb[0];
            _rgb[1] *= c._rgb[1];
            _rgb[2] *= c._rgb[2];
            return *this;
        }

        inline Color operator / (const Color& c) const {
            return Color(_rgb[0] / c._rgb[0],
                _rgb[1] / c._rgb[1],
                _rgb[2] / c._rgb[2]);
        }

        inline Color& operator /= (const Color& c) {
            _rgb[0] /= c._rgb[0];
            _rgb[1] /= c._rgb[1];
            _rgb[2] /= c._rgb[2];
            return *this;
        }

        inline Color operator * (float k) const {
            return Color(_rgb[0] * k,
                _rgb[1] * k,
                _rgb[2] * k);
        }

        inline Color& operator *= (float k) {
            _rgb[0] *= k;
            _rgb[1] *= k;
            _rgb[2] *= k;
            return *this;
        }

        inline Color operator / (float k) const {
            return Color(_rgb[0] / k,
                _rgb[1] / k,
                _rgb[2] / k);
        }

        inline Color& operator /= (float k) {
            _rgb[0] /= k;
            _rgb[1] /= k;
            _rgb[2] /= k;
            return *this;
        }
    };
}

#endif
