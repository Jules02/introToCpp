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

#endif //VEC3_H
