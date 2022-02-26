#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc50-cpp"
//
// Created by wailer on 22/02/2022.
//

#include "Shape.h"

float Shape::randf() {
    return float(rand())/ float(RAND_MAX);
}

Shape::Shape(const Vector2 &position, Vector2 velocity, const ALLEGRO_COLOR &color):
_position(position), _color(color)
{
    double ln = velocity.Len();
    _direction = velocity/ln;
    _velocity = ln;
}

Shape::Shape() {
    _velocity = 0;
    _direction = Vector2(0, 0);
    _position = Vector2(0, 0);
    _color = al_map_rgb(255, 255, 255);
}

const Vector2 &Shape::getPosition() const {return _position;}
void Shape::setPosition(const Vector2 &position) {_position = position;}

const Vector2 &Shape::getDirection() const {return _direction;}
void Shape::setDirection(const Vector2 &direction) {_direction = direction;}

double Shape::getVelocity() const {return _velocity;}
void Shape::setVelocity(double velocity) {_velocity = velocity;}

const ALLEGRO_COLOR &Shape::getColor() const {return _color;}
void Shape::setColor(const ALLEGRO_COLOR &color) {_color = color;}

bool Shape::hasCollided() const {return _collided;}
void Shape::setCollided(bool collided) {_collided = collided;}

double Shape::getScale() const {return _scale;}
// no implementation for setScale(), because it is dependent on properties like _side or _radius

Vector2 Shape::GetBoundaries() {
    if (_position.x < 0) return {1, 0};
    else if (_position.x >= SCREEN_W) return {-1, 0};
    else if (_position.y < 0) return {0, 1};
    else if (_position.y >= SCREEN_H) return {0, -1};
    else return {0, 0};
}

void Shape::Move() {
    _position += _direction * _velocity; // * delta
}

void Shape::Collide(Vector2 normal) {
//     n - surface normal (must be normalized)
//     r - reflection
//     d - current direction
//     d * n instead of dot(d, n) works for now, so i will leave it
//     r = d - 2 * dot(d, n) * n
    _direction -= normal * normal.Dot(_direction) * 2;
    _position += _direction * _velocity;
}

void Shape::Randomize() {
    _position = Vector2::RandVector2() * Vector2(SCREEN_W, SCREEN_H);
    _direction = (Vector2::RandVector2()*2 - Vector2(1, 1)).Normalized();
    _velocity = randf() * (MAX_SPEED - MIN_SPEED) + MIN_SPEED; // NOLINT(cppcoreguidelines-narrowing-conversions)

//     we don't use full [0;255], because we want to see our color on black background
    _color = al_map_rgb(rand() % 200 + 56, rand() % 200 + 56, rand() % 200 + 56);
}

#pragma clang diagnostic pop