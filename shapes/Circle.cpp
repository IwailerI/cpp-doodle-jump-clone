//
// Created by wailer on 22/02/2022.
//

#include "Circle.h"

Circle::Circle(const Vector2 &position, const Vector2 &velocity, const ALLEGRO_COLOR &color, double radius):
    Shape(position, velocity, color),
    _radius(radius)
    {}

Circle::Circle() {
    _radius = 0;
}

double Circle::getRadius() const {return _radius;}
void Circle::setRadius(double radius) {_radius = radius;}

void Circle::setScale(double scale) {
    _radius = _radius / _scale * scale; // apply new scale
    _scale = scale;
}

Vector2 Circle::GetBoundaries() {
    if (_position.x-_radius < 0) {_position.x = _radius; return {1, 0};}
    else if (_position.x+_radius >= SCREEN_W) {_position.x = SCREEN_W-_radius-1; return {-1, 0};}
    else if (_position.y-_radius < 0) {_position.y = _radius; return {0, 1};}
    else if (_position.y+_radius >= SCREEN_H) {_position.y = SCREEN_H-_radius-1;return {0, -1}; }
    else return {0, 0};
}

Vector2 Circle::GetClosestPointTo(Vector2 pos) {
    // if pos is within the circle, return pos
    if ((pos - _position).LenSquared() <= _radius * _radius) return pos;

    // return vector from circle center towards pos, stopping at circle edge, added to circle center
    return _position + (pos - _position).Normalized() * _radius;
}

Vector2 Circle::GetSurfaceNormalAt(Vector2 pos) {
    return (pos - _position).Normalized();
}

void Circle::Draw() {
    al_draw_circle(_position.x, _position.y, _radius, _color, _thickness);
}

void Circle::Randomize() {
    Shape::Randomize();
    _radius = rand()%28 + 3;

    // avoid square being spawned in wall, same as square
    _position = Vector2::RandVector2() * Vector2(SCREEN_W - _radius*2, SCREEN_H - _radius*2) + Vector2(_radius, _radius);
}

