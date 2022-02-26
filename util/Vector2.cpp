//
// Created by wailer on 22/02/2022.
//

#include "Vector2.h"

Vector2::Vector2() {x=0.0; y=0.0;}
Vector2::Vector2(int x, int y): x(x), y(y) {}
Vector2::Vector2(double x, double y): x(x), y(y) {}

Vector2 Vector2::operator+(Vector2 vec) const {return{x + vec.x, y + vec.y};}
Vector2 Vector2::operator-(Vector2 vec) const {return{x - vec.x, y - vec.y};}
Vector2 Vector2::operator*(Vector2 vec) const {return{x * vec.x, y * vec.y};}
Vector2 Vector2::operator/(Vector2 vec) const {return{x / vec.x, y / vec.y};}

Vector2 Vector2::operator*(double n) const {return{x * n, y * n};}
Vector2 Vector2::operator/(double n) const {return{x / n, y / n};}

void Vector2::operator+= (Vector2 vec) {x+=vec.x; y+=vec.y;}
void Vector2::operator-= (Vector2 vec) {x-=vec.x; y-=vec.y;}
void Vector2::operator*= (Vector2 vec) {x*=vec.x; y*=vec.y;}
void Vector2::operator*= (double n)    {x*=n; y*=n;}
void Vector2::operator/= (Vector2 vec) {x/=vec.x; y/=vec.y;}
void Vector2::operator/= (double n)    {x/=n; y/=n;}

bool Vector2::operator==(Vector2 vec) const {return (x == vec.x && y == vec.y);}
bool Vector2::operator!= (Vector2 vec) const {return (x != vec.x || y != vec.y);}

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