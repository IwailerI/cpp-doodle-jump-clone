
//
// Created by wailer on 22/02/2022.
//

#ifndef PROJECT_VECTOR2_H
#define PROJECT_VECTOR2_H

#include <cmath>
#include <ostream>
#include <string>

struct Vector2 {
    double x, y;

    Vector2();
    Vector2(double x, double y);
    Vector2(int x, int y);

    double operator[](int n);

    Vector2 operator-();
    void operator+=(Vector2 vec);
    void operator-=(Vector2 vec);
    void operator*=(Vector2 vec);
    void operator*=(double n);
    void operator/=(Vector2 vec);
    void operator/=(double n);

    bool operator==(Vector2 vec) const;
    bool operator!=(Vector2 vec) const;

    std::string ToString() const;

    Vector2 Normalized() const;

    double Len() const;

    // doen't use sqrt, so is faster then Len()
    // can be used for comparing
    double LenSquared() const;

    static Vector2 RandVector2();

    double Dot(Vector2 vec) const;
};

Vector2 operator+(Vector2 v1, Vector2 v2);
Vector2 operator-(Vector2 v1, Vector2 v2);
Vector2 operator*(Vector2 v1, Vector2 v2);
Vector2 operator/(Vector2 v1, Vector2 v2);

Vector2 operator*(Vector2 v, double n);
Vector2 operator*(double n, Vector2 v);
Vector2 operator/(Vector2 v, double n);
std::ostream &operator<<(std::ostream &os, Vector2 v);

#endif  // PROJECT_VECTOR2_H
