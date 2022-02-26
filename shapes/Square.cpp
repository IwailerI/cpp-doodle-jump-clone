//
// Created by wailer on 22/02/2022.
//

#include "Square.h"

Square::Square(const Vector2 &position, const Vector2 &velocity, const ALLEGRO_COLOR &color, double side):
    Shape(position, velocity, color),
    _side(side)
    {}

Square::Square() {
    _side = 0;
}

double Square::getSide() const {return _side;}
void Square::setSide(double side) {_side = side;}

void Square::setScale(double scale) {
    _side = _side/_scale*scale; // apply new scale
    _scale = scale;
}

Vector2 Square::GetClosestPointTo(Vector2 pos) {
    Vector2 res;
    double ext = _side * .5;
    res.x = clamp(pos.x, _position.x - ext, _position.x + ext);
    res.y = clamp(pos.y, _position.y - ext, _position.y + ext);

    return res;
}

Vector2 Square::GetSurfaceNormalAt(Vector2 pos) {
    Vector2 off = pos-_position;
    if (abs(off.x) >= abs(off.y)) {
        return off.x > 0 ? Vector2(1, 0) : Vector2(-1, 0);
    } else {
        return off.y > 0 ? Vector2(0, 1) : Vector2(0, -1);
    }
}

Vector2 Square::GetBoundaries() {
    // check screen edges, accounting _side
    double ext = _side/2;

    if (_position.x-ext < 0) {_position.x = ext; return {1, 0};}
    else if (_position.x+ext >= SCREEN_W) {_position.x = SCREEN_W-ext-1; return {-1, 0};}
    else if (_position.y-ext < 0) {_position.y = ext; return {0, 1};}
    else if (_position.y+ext >= SCREEN_H) {_position.y = SCREEN_H-ext-1;return {0, -1}; }
    else return {0, 0};
}

void Square::Draw() {
    al_draw_rectangle(
            _position.x - _side/2,
            _position.y - _side/2,
            _position.x + _side/2,
            _position.y + _side/2,
            _color,
            _thickness
    );
}

void Square::Randomize() {
    Shape::Randomize();
    _side = rand()%26 + 5;

    // avoid square being spawned in wall
    _position = Vector2::RandVector2() * Vector2(SCREEN_W - _side, SCREEN_H - _side) + Vector2(_side*.5, _side*.5);
}

double Square::clamp(double n, double min, double max) {
    if (n < min) return min;
    else if (n > max) return max;
    else return n;
}
