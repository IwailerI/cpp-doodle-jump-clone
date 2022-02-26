
//
// Created by wailer on 22/02/2022.
//

#ifndef PROJECT_VECTOR2_H
#define PROJECT_VECTOR2_H

#include <string>
#include <cmath>

class Vector2 {
public:
    double x, y;

    Vector2();
    Vector2(double x, double y);
    Vector2(int x, int y);

    Vector2 operator+ (Vector2 vec) const;
    Vector2 operator- (Vector2 vec) const;
    Vector2 operator* (Vector2 vec) const;
    Vector2 operator* (double n) const;
    Vector2 operator/ (Vector2 vec) const;
    Vector2 operator/ (double n) const;

    void operator+= (Vector2 vec);
    void operator-= (Vector2 vec);
    void operator*= (Vector2 vec);
    void operator*= (double n);
    void operator/= (Vector2 vec);
    void operator/= (double n);

    bool operator== (Vector2 vec) const;
    bool operator!= (Vector2 vec) const;

    std::string ToString() const;

    Vector2 Normalized() const;

    double Len() const;

    // doen't use sqrt, so is faster then Len()
    // can be used for comparing
    double LenSquared() const;

    static Vector2 RandVector2();

    double Dot(Vector2 vec) const;
};

#endif //PROJECT_VECTOR2_H
