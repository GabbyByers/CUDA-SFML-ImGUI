#pragma once

class Vec3f {
public:
    float x, y, z;

    Vec3f() {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }

    Vec3f(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vec3f(int x, int y, int z) {
        this->x = static_cast<float>(x);
        this->y = static_cast<float>(y);
        this->z = static_cast<float>(z);
    }

    Vec3f(const Vec3f& vec3f) {
        x = vec3f.x;
        y = vec3f.y;
        z = vec3f.z;
    }

    float length() {
        return sqrt((x * x) + (y * y) + (z * z));
    }

    void normalize() {
        float len = length();
        x /= len;
        y /= len;
        z /= len;
    }

    void print() {
        std::cout << "[" << x << ", " << y << ", " << z << "]\n";
    }

    Vec3f operator + (const float val) const {
        return Vec3f(x + val, y + val, z + val);
    }

    Vec3f operator - (const float val) const {
        return Vec3f(x - val, y - val, z - val);
    }

    Vec3f operator * (const float val) const {
        return Vec3f(x * val, y * val, z * val);
    }

    Vec3f operator / (const float val) const {
        return Vec3f(x / val, y / val, z / val);
    }

    Vec3f operator + (const Vec3f& vec3f) const {
        return Vec3f(x + vec3f.x, y + vec3f.y, z + vec3f.z);
    }

    Vec3f operator - (const Vec3f& vec3f) const {
        return Vec3f(x - vec3f.x, y - vec3f.y, z - vec3f.z);
    }

    void operator += (const float val) {
        x += val;
        y += val;
        z += val;
    }

    void operator -= (const float val) {
        x -= val;
        y -= val;
        z -= val;
    }

    void operator *= (const float val) {
        x *= val;
        y *= val;
        z *= val;
    }

    void operator /= (const float val) {
        x /= val;
        y /= val;
        z /= val;
    }

    void operator = (const Vec3f& vec3f) {
        x = vec3f.x;
        y = vec3f.y;
        z = vec3f.z;
    }

    void operator += (const Vec3f vec3f) {
        x += vec3f.x;
        y += vec3f.y;
        z += vec3f.z;
    }

    void operator -= (const Vec3f vec3f) {
        x -= vec3f.x;
        y -= vec3f.y;
        z -= vec3f.z;
    }

    bool operator > (Vec3f vec3f) {
        float len1 = length();
        float len2 = vec3f.length();
        return len1 > len2;
    }

    bool operator < (Vec3f vec3f) {
        float len1 = length();
        float len2 = vec3f.length();
        return len1 < len2;
    }

    Vec3f cross(Vec3f vec3f) {
        Vec3f C;
        C.x = (y * vec3f.z) + (z * vec3f.y);
        C.y = (z * vec3f.x) + (x * vec3f.z);
        C.z = (x * vec3f.y) + (y * vec3f.x);
        return C;
    }

    float dot(Vec3f vec3f) {
        return (x * vec3f.x) + (y * vec3f.y) + (z * vec3f.z);
    }
};