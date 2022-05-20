//
// Created by wailer on 22/02/2022.
//

#include "Vector2.h"

Vector2::Vector2() {x=0.0; y=0.0;}
Vector2::Vector2(int x, int y): x(x), y(y) {}
Vector2::Vector2(double x, double y): x(x), y(y) {}

Vector2 operator+ (Vector2 v1, Vector2 v2) {return {v1.x + v2.x, v1.y + v2.y};}
Vector2 operator- (Vector2 v1, Vector2 v2) {return v1 + -v2;}
Vector2 operator* (Vector2 v1, Vector2 v2) {return {v1.x * v2.x, v1.y * v2.y};}
Vector2 operator/ (Vector2 v1, Vector2 v2) {return {v1.x / v2.x, v1.y / v2.y};}
Vector2 operator* (Vector2 v, double n) {return v * Vector2(n, n);}
Vector2 operator* (double n, Vector2 v) {return v * n;}
Vector2 operator/ (Vector2 v, double n) {return v * (1.0/n);}

void Vector2::operator+= (Vector2 vec) {(*this) = (*this) + vec;}
void Vector2::operator-= (Vector2 vec) {(*this) = (*this) - vec;}
void Vector2::operator*= (Vector2 vec) {(*this) = (*this) * vec;}
void Vector2::operator*= (double n)    {(*this) = (*this) * n;}
void Vector2::operator/= (Vector2 vec) {(*this) = (*this) / vec;}
void Vector2::operator/= (double n)    {(*this) = (*this) / n;}
Vector2 Vector2::operator-() {return (*this) * -1;}

bool Vector2::operator==(Vector2 vec) const {return (x == vec.x && y == vec.y);}
bool Vector2::operator!= (Vector2 vec) const {return !((*this) == vec);}

double Vector2::operator[](int n) {return (n == 0) ? x : y;}
std::ostream &operator<< (std::ostream &os, Vector2 v) {
    os << v.ToString();
    return os;
}

std::string Vector2::ToString() const {
    return "("+std::to_string(x) + ", " + std::to_string(y) + ")";
}

Vector2 Vector2::Normalized() const {
    double len = Len();
    if (len > 0) return {x/len, y/len};
    return {0, 0};
}

double Vector2::Len() const {return sqrt(x*x + y*y);}

double Vector2::LenSquared() const {return x*x + y*y;}

Vector2 Vector2::RandVector2() {
    return {float(rand())/ float(RAND_MAX), float(rand())/ float(RAND_MAX)};
}

double Vector2::Dot(Vector2 vec) const {
    return x*vec.x + y*vec.y;
}

