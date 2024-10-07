//
// Created by Jules Dupont on 01/10/2024.
//

#ifndef VEC3_H
#define VEC3_H
#include <cmath>
#include <fstream>
#include <ostream>

struct Vec3 {
    float x, y, z;
};

inline Vec3 add(const Vec3& first, const Vec3& second) {
    return Vec3{first.x + second.x, first.y + second.y, first.z + second.z};
} ;

inline float dot(const Vec3& first, const Vec3& second) {
    return first.x * second.x + first.y * second.y + first.z * second.z;
} ;

inline Vec3 cross(const Vec3& first, const Vec3& second) {
    return Vec3{first.y * second.z - first.z * second.y, first.z * second.x - first.x * second.z, first.x * second.y - first.y * second.x};
};

inline float length(const Vec3& vec) {
    return sqrt(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z);
}

inline float squared_length(const Vec3& vec) {
    return vec.x*vec.x + vec.y*vec.y + vec.z*vec.z;
}

inline Vec3 operator+(const Vec3& first, const Vec3& second) { return add(first, second); }

inline Vec3 operator*(const float scalar, const Vec3& vector) { return Vec3{scalar * vector.x, scalar * vector.y, scalar * vector.z}; }

inline std::ostream& operator<<(std::ostream& out, const Vec3& v) {return out << "(" << v.x << ", " << v.y << ", " << v.z << ")";};

using Color = Vec3;

static constexpr int WIDTH = 384;
static constexpr int HEIGHT = 256;

struct Image {
    int width = WIDTH;
    int height = HEIGHT;

    Color colors[WIDTH * HEIGHT]{};

    Color& operator()(int x, int y) { return colors[y*WIDTH + x]; }
    const Color& operator()(int x, int y) const { return colors[y*WIDTH + x]; }
};

inline void writeColor(std::ostream& stream, const Color& color)
{
    // Convert from scalar in [0,1] to integer in [0,255]
    int red = int(255.0 * color.x);
    int green = int(255.0 * color.y);
    int blue = int(255.0 * color.z);

    stream << red << ' ' << green << ' ' << blue << '\n';
}

inline void writeImagePPM(const Image& image)
{
    std::ofstream file_stream{ "Img.ppm" };
    file_stream << "P3\n" << image.width << " " << image.height << "\n255\n";

    for (int j = 0; j < image.height; j++) {
        for (int i = 0; i < image.width; i++) {
            writeColor(file_stream, image(i,j));
        }
    }
}

#endif //VEC3_H
